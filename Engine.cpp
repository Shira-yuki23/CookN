#include "engine.h"
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <thread>
#include <chrono>
#include "Scene.h"
#include "Entity.h"
#include "InputHandler.h" 
#include "renderer.h"
#include "PhysicsManager.h" 
#include "Event.h" 

using namespace std::chrono;

Engine::Engine() 
    : is_running(false)
    , is_paused(false)
    , delta_time(0.0f)
    , frame_count(0)
    , target_fps(60)  
    , current_fps(0)
{
    std::cout << "[ENGINE] Engine created" << std::endl;
}

Engine::~Engine() 
{
    shutdown();
}

void Engine::initialize() 
{
    std::cout << "[ENGINE] Initializing..." << std::endl;
    
    input_handler = std::make_unique<InputHandler>();
    
    // Connect input events to the current scene's entities
    input_handler->on_input_event = [this](const InputEvent& event) {
        if (event.type == EventType::QUIT) {
            is_running = false;
        }

        if (current_scene) {
            auto entities = current_scene->getEntities();
            for (auto& entity : entities) {
                if (entity) {
                    entity->on_event(event);
                }
            }
        }
    };

    renderer = std::make_unique<Renderer>();  
    physics_manager = std::make_unique<PhysicsManager>();
    
    current_scene = std::make_shared<Scene>("DefaultScene");
    scenes.push_back(current_scene);
    
    is_running = true;
    is_paused = false;
    last_frame_time = high_resolution_clock::now();
    
    std::cout << "[ENGINE] Initialization complete" << std::endl;
    std::cout << "[ENGINE] Target FPS: " << target_fps << std::endl;
}

void Engine::run() 
{
    if (!is_running) 
    {
        std::cerr << "[ENGINE ERROR] Cannot run - engine not initialized" << std::endl;
        return;
    }
    
    std::cout << "[ENGINE] Game loop started" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    const double target_frame_time = 1.0 / target_fps; 
    
    auto previous_time = high_resolution_clock::now();
    double lag = 0.0;
    
    while(is_running)
    {
        auto current_time = high_resolution_clock::now();
        
        double elapsed = duration<double>(current_time - previous_time).count();
        previous_time = current_time;
        lag += elapsed;

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

        static auto last_fps_time = high_resolution_clock::now();
        static int last_frame_count = 0;
        
        auto now = high_resolution_clock::now();
        double time_since_last_fps = duration<double>(now - last_fps_time).count();
        
        if (time_since_last_fps >= 1.0) 
        {
            current_fps = frame_count - last_frame_count;
            last_fps_time = now;
            last_frame_count = frame_count;
        }

                auto frame_end = high_resolution_clock::now();
        double frame_duration = duration<double>(frame_end - current_time).count();
        
        if (frame_duration < target_frame_time)  
        {
            // Calculate sleep time in milliseconds
            int sleep_ms = static_cast<int>((target_frame_time - frame_duration) * 1000);
            
            // Use milliseconds directly - this works with older GCC
            std::chrono::milliseconds sleep_duration(sleep_ms);
            Sleep(sleep_ms);
        }
    }
}

void Engine::shutdown() 
{
    std::cout << "[ENGINE] Shutting down..." << std::endl;
    is_running = false;

    renderer.reset();
    input_handler.reset();
    physics_manager.reset();
    scenes.clear();
    current_scene.reset();
    
    std::cout << "[ENGINE] Shutdown complete" << std::endl;
}

void Engine::add_scene(std::shared_ptr<Scene> scene)
{
    if (scene)
    {
        scenes.push_back(scene);
        std::cout << "[ENGINE] Scene added: " << scene->getName() << std::endl;
    }
}

void Engine::load_scene(const std::string& scene_name) 
{
    std::cout << "[ENGINE] Loading scene: " << scene_name << std::endl;
    
    for (auto& scene : scenes)
    {
        if (scene->getName() == scene_name)
        {
            current_scene = scene;
            std::cout << "[ENGINE] Scene loaded: " << scene_name << std::endl;
            return;
        }
    }
    
    std::cerr << "[ENGINE ERROR] Scene not found: " << scene_name << std::endl;
}

bool Engine::switch_scene(const std::string& scene_name) 
{
    for(auto& scene : scenes)
    {
        if(scene->getName() == scene_name)
        {
            current_scene = scene;
            std::cout << "[ENGINE] Switched to scene: " << scene_name << std::endl;
            return true;
        }
    }
    
    std::cerr << "[ENGINE ERROR] Cannot switch - scene not found: " << scene_name << std::endl;
    return false;
}

void Engine::pause()
{
    if (!is_paused)
    {
        is_paused = true;
        std::cout << "[ENGINE] Game paused" << std::endl;
    }
}

void Engine::resume()
{
    if (is_paused)
    {
        is_paused = false;
        std::cout << "[ENGINE] Game resumed" << std::endl;
    }
}

void Engine::add_entity(std::shared_ptr<Entity> entity)
{
    if (current_scene && entity)
    {
        current_scene->addEntity(entity);
        std::cout << "[ENGINE] Entity added to current scene" << std::endl;
    }
}

void Engine::remove_entity(const std::string& entity_id)
{
    if (current_scene)
    {
        current_scene->removeEntity(entity_id);
        std::cout << "[ENGINE] Entity removed: " << entity_id << std::endl;
    }
}

std::shared_ptr<Scene> Engine::get_current_scene() const 
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
    if (fps > 0) {
        target_fps = fps;
        std::cout << "[ENGINE] Target FPS set to: " << target_fps << std::endl;
    }
}