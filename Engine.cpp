#include "Engine.h"
#include <iostream>
#include <chrono>
#include <thread>

//add headers here
#include "Scene.h"
#include "InputHandler.h"
#include "Renderer.h"

using namespace std::chrono;

Engine::Engine() : is_running(false), delta_time(0.0f) {
    std::cout << "Engine initialized" << std::endl;
}

Engine::~Engine() {
    shutdown();
}

void Engine::initialize() {
    inputHandler = std::make_unique<InputHandler>();
    renderer = std::make_unique<Renderer>();
    currentScene = std::make_shared<Scene>("DefaultScene");
    is_running = true;
    std::cout << "Engine initialization complete" << std::endl;
}

void Engine::run() {
    if (!is_running) {
        std::cerr << "Engine not initialized. Call initialize() first." << std::endl;
        return;
    }
    std::cout << "Starting game loop..." << std::endl;
    auto lastTime = high_resolution_clock::now();
    while (is_running) {
        calculateDeltaTime();
        inputHandler->processInput();
        if (currentScene) {
            currentScene->update(delta_time);
        }
        renderer->render(currentScene.get());
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60 FPS
    }
}

void Engine::calculateDeltaTime() {
    static auto lastTime = high_resolution_clock::now();
    auto currentTime = high_resolution_clock::now();
    
    duration<float> elapsed = currentTime - lastTime;
    delta_time = elapsed.count();
    lastTime = currentTime;
}

void Engine::shutdown() {
    is_running = false;
    std::cout << "Engine shutting down..." << std::endl;
}


void Engine::loadScene(const std::string& sceneName) {
    std::cout << "Loading scene: " << sceneName << std::endl;
}

void Engine::switchScene(const std::string& sceneName) {
    std::cout << "Switching to scene: " << sceneName << std::endl;
}

std::shared_ptr<Scene> Engine::getCurrentScene() const {
    return currentScene;
}

bool Engine::getIsRunning() const {
    return is_running;
}

float Engine::getDeltaTime() const {
    return delta_time;
}

void Engine::setRunning(bool running) {
    is_running = running;
}