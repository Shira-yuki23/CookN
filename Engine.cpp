#include "Engine.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>
#include "Scene.h"
#include "Entity.h"
#include "input_handler.h"
#include "Renderer.h"
#include "physics_manager.h"

using namespace std::chrono;

Engine::Engine() 
    : is_running(false)
    , is_paused(false)
    , delta_time(0.0f)
    , frame_count(0)
    , target_fps(60)  
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
    
    const double frame_time = 1.0 / target_fps; 
    
    auto previous_time = high_resolution_clock::now();
    double lag = 0.0;
    
    while(is_running)
    {
        auto current_time = high_resolution_clock::now();
        
        double elapsed = duration<double>(current_time - previous_time).count();
        previous_time = current_time;
        lag += elapsed;

        if (input_handler && !is_paused)
        {
            input_handler->process_input();
        }

        while (lag >= frame_time && !is_paused)
        {
            delta_time = frame_time;  
 
            if (physics_manager)
            {
                physics_manager->update(delta_time);
            }
            
            if (current_scene)
            {
                current_scene->update(delta_time);
            }
            
            lag -= frame_time;
        }

        if (renderer && current_scene)
        {
            float alpha = static_cast<float>(lag / frame_time);
            renderer->render(current_scene.get(), alpha);
        }

        frame_count++;

        if (frame_count % 60 == 0)
        {
            auto now = high_resolution_clock::now();
            double actual_frame_time = duration<double>(now - previous_time).count();
            double fps = 1.0 / actual_frame_time;
            std::cout << "[ENGINE] FPS: " << static_cast<int>(fps) << std::endl;
        }
    }
}

void Engine::calculate_delta_time() 
{
    static auto last_time = high_resolution_clock::now();
    auto current_time = high_resolution_clock::now();
    duration<float> elapsed = current_time - last_time;
    delta_time = elapsed.count();
    last_time = current_time;
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
        std::cout << "[ENGINE] Scene added: " << scene->get_name() << std::endl;
    }
}

void Engine::load_scene(const std::string& scene_name) 
{
    std::cout << "[ENGINE] Loading scene: " << scene_name << std::endl;
    
    for (auto& scene : scenes)
    {
        if (scene->get_name() == scene_name)
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
        if(scene->get_name() == scene_name)
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
        current_scene->add_entity(entity);
        std::cout << "[ENGINE] Entity added to current scene" << std::endl;
    }
}

void Engine::remove_entity(const std::string& entity_id)
{
    if (current_scene)
    {
        current_scene->remove_entity(entity_id);
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