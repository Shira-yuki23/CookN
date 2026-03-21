#include "engine.h"
#include <iostream>
#include <algorithm>
#include <windows.h>
#include "Scene.h"
#include "Entity.h"
#include "InputHandler.h" 
#include "renderer.h"
#include "PhysicsManager.h" 
#include "Event.h" 
#include "SpatialEntity.h"

Engine::Engine() 
    : is_running(false)
    , is_paused(false)
    , delta_time(0.0f)
    , frame_count(0)
    , target_fps(60)  
    , current_fps(0)
    , last_frame_time(Time::now())
{
}

Engine::~Engine() 
{
    shutdown();
}

void Engine::initialize() 
{
    input_handler = std::make_unique<InputHandler>();
    if (!input_handler)
    {
        throw InitializationException("Failed to create InputHandler");
    }

    input_handler->on_input_event = [this](const InputEvent& event) 
    {
        if (event.type == EventType::QUIT) 
        {
            is_running = false;
        }

        if (current_scene) 
        {
            auto entities = current_scene->getEntities();
            for (auto& entity : entities) 
            {
                if (entity) 
                {
                    entity->on_event(event);
                }
            }
        }
    };

    renderer = std::make_unique<Renderer>();  
    if (!renderer)
    {
        throw InitializationException("Failed to create Renderer");
    }

    physics_manager = std::make_unique<PhysicsManager>();
    if (!physics_manager)
    {
        throw InitializationException("Failed to create PhysicsManager");
    }
    
    current_scene = std::make_shared<Scene>("DefaultScene");
    if (!current_scene)
    {
        throw InitializationException("Failed to create DefaultScene");
    }
    scenes.push_back(current_scene);
    
    is_running = true;
    is_paused = false;
    last_frame_time = Time::now();
}

void Engine::run() 
{
    if (!is_running) 
    {
        throw EngineException("Cannot run - engine not initialized");
    }
    
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    const double target_frame_time = 1.0 / target_fps;
    auto previous_time = Time::now();
    double lag = 0.0;
    
    while(is_running)
    {
        auto current_time = Time::now();
        
        double elapsed = Time::elapsed_seconds(previous_time, current_time);
        previous_time = current_time;
        lag += elapsed;
        
        if (current_scene) 
        {
            for (auto& entity : current_scene->getEntities()) 
            {
                if (auto spatial = std::dynamic_pointer_cast<SpatialEntity>(entity)) 
                {
                    spatial->update_previous_position();
                }
            }
        }

        bool paused = is_paused;

        if (input_handler) 
        {
            input_handler->process_input();
        }
        
        while (lag >= target_frame_time && !paused)
        {
            delta_time = static_cast<float>(target_frame_time);
            
            if (physics_manager) 
            {
                physics_manager->update(delta_time);
            }
            
            if (current_scene) 
            {
                current_scene->update(delta_time);
            }
            
            lag -= target_frame_time;
        }

        if (renderer && current_scene) 
        {
            float alpha = static_cast<float>(lag / target_frame_time);
            if (alpha < 0.0f) alpha = 0.0f;
            if (alpha > 1.0f) alpha = 1.0f;
            renderer->render(current_scene.get(), alpha, current_fps);
        }
        
        frame_count++;

        static auto last_fps_time = Time::now();
        static int last_frame_count = 0;
        
        auto now = Time::now();
        double time_since_last_fps = Time::elapsed_seconds(last_fps_time, now);
        
        if (time_since_last_fps >= 1.0) 
        {
            current_fps = frame_count - last_frame_count;
            last_fps_time = now;
            last_frame_count = frame_count;
        }

        auto frame_end = Time::now();
        double frame_duration = Time::elapsed_seconds(current_time, frame_end);
        
        if (frame_duration < target_frame_time)  
        {
            int sleep_ms = static_cast<int>((target_frame_time - frame_duration) * 1000);
            Time::sleep_milliseconds(sleep_ms);
        }
    }
}

void Engine::shutdown() 
{
    is_running = false;

    renderer.reset();
    input_handler.reset();
    physics_manager.reset();
    scenes.clear();
    current_scene.reset();
}

void Engine::add_scene(ScenePtr scene)
{
    if (scene)
    {
        scenes.push_back(scene);
    }
}

void Engine::load_scene(const std::string& scene_name) 
{
    for (auto& scene : scenes)  
    {
        if (scene->getName() == scene_name)
        {
            current_scene = scene;
            return;
        }
    }
    
    throw SceneException("Scene not found: " + scene_name);
}

bool Engine::switch_scene(const std::string& scene_name) 
{
    for(auto& scene : scenes)  
    {
        if(scene->getName() == scene_name)
        {
            current_scene = scene;
            return true;
        }
    }
    
    throw SceneException("Cannot switch - scene not found: " + scene_name);
}

void Engine::pause()
{
    if (!is_paused)
    {
        is_paused = true;
    }
}

void Engine::resume()
{
    if (is_paused)
    {
        is_paused = false;
    }
}

void Engine::add_entity(EntityPtr entity)
{
    if (current_scene && entity)
    {
        current_scene->addEntity(entity);
    }
}

void Engine::remove_entity(const std::string& entity_id)
{
    if (current_scene)
    {
        current_scene->removeEntity(entity_id);
    }
}

Engine::ScenePtr Engine::get_current_scene() const 
{
    return current_scene;
}

bool Engine::get_is_running() const 
{
    return is_running;
}

bool Engine::get_is_paused() const 
{
    return is_paused;
}

float Engine::get_delta_time() const 
{
    return delta_time;
}

int Engine::get_frame_count() const 
{
    return frame_count;
}

void Engine::set_running(bool running) 
{
    is_running = running;
}

void Engine::set_paused(bool paused)
{
    is_paused = paused;
}

void Engine::set_target_fps(int fps)
{
    if (fps > 0) 
    {
        target_fps = fps;
    }
    else
    {
        throw EngineException("Invalid target FPS: " + std::to_string(fps));
    }
}