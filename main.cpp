 #include "Player.h"
#include "PhysicsManager.h"
#include "InputHandler.h"
#include "Event.h"

#include "SceneManager.h"
#include "SceneFactory.h"
#include "ConfigManager.h"
#include "ResourceManager.h"
#include "EventDispatcher.h"

#include <iostream>
#include <memory>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(milliseconds) Sleep(milliseconds)
#else
#include <unistd.h>
#define SLEEP(milliseconds) usleep(milliseconds * 1000)
#endif

int main() {
    try {
        // 🔹 Input system
        InputHandler input;

        // 🔹 Utility systems
        ConfigManager::getInstance().load_config("config.txt");
        ResourceManager::getInstance().initialize();
        EventDispatcher::getInstance().initialize();

        // 🔹 Scene system
        SceneManager sceneManager;
        SceneFactory::registerScenes();

        sceneManager.changeScene("GameScene"); // or "MenuScene"

        // Game loop settings
        const float TARGET_FPS = 60.0f;
        const float FRAME_TIME = 1.0f / TARGET_FPS;
        const int TARGET_FRAME_TIME_MS = static_cast<int>(FRAME_TIME * 1000);

        int frameCount = 0;
        const int MAX_FRAMES = 1000;

        std::cout << "Game started with Scene System." << std::endl;

        while (frameCount < MAX_FRAMES) {
            auto frameStart = std::chrono::high_resolution_clock::now();

            // 🔹 Input
            input.process_input();

#ifdef _WIN32
            if (input.is_key_pressed(VK_ESCAPE)) {
                std::cout << "Escape pressed - exiting..." << std::endl;
                break;
            }
#endif

            // 🔹 Event system
            EventDispatcher::getInstance().processEvents();

            // 🔹 Scene update & render
            sceneManager.update(FRAME_TIME);
            sceneManager.render(FRAME_TIME);

            // 🔹 Frame control
            auto frameEnd = std::chrono::high_resolution_clock::now();
            auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);

            int sleepTime = TARGET_FRAME_TIME_MS - static_cast<int>(frameDuration.count());

            if (sleepTime > 0) {
                SLEEP(sleepTime);
            }

            frameCount++;
        }

        std::cout << "Game loop ended after " << frameCount << " frames." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}