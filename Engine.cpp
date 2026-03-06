#include "Engine.h"
#include <iostream>
#include <chrono>
#include <thread>
//headers
#include "Scene.h"
#include "input_handler.h"
#include "Renderer.h"
using namespace std::chrono;
Engine::Engine() : is_running(false), delta_time(0.0f) 
{
    std::cout << "Engine initialized" << std::endl;
}
Engine::~Engine() 
{
    shutdown();
}
void Engine::initialize() 
{
    input_handler = std::make_unique<input_handler>();
    renderer = std::make_unique<Renderer>();
    current_scene = std::make_shared<Scene>("DefaultScene");
    is_running = true;
    std::cout << "Engine initialization complete" << std::endl;
}
void Engine::run() 
{
    if (!is_running) 
    {
        std::cerr << "Engine not initialized. Call initialize() first." << std::endl;
        return;
    }
    std::cout << "Starting game loop..." << std::endl;
    auto last_time = high_resolution_clock::now();
    while (is_running) 
    {
        calculate_delta_time();
        input_handler->process_input();
        if (current_scene) 
        {
            current_scene->update(delta_time);
        }
        renderer->render(current_scene.get());
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); 
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
    is_running = false;
    std::cout << "Engine shutting down..." << std::endl;
}


void Engine::load_scene(const std::string& scene_name) 
{
    std::cout << "Loading scene: " << scene_name << std::endl;
}

void Engine::switch_scene(const std::string& scene_name) 
{
    std::cout << "Switching to scene: " << scene_name << std::endl;
}

std::shared_ptr<Scene> Engine::get_current_scene() const 
{
    return current_scene;
}

bool Engine::get_is_running() const 
{
    return is_running;
}

float Engine::get_delta_time() const 
{
    return delta_time;
}

void Engine::set_running(bool running) 
{
    is_running = running;
}