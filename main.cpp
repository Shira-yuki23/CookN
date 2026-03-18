#include "Player.h"
#include "PhysicsManager.h"
#include "InputHandler.h"
#include "Event.h"

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
        // 1️⃣ Create InputHandler
        InputHandler input;

        // 2️⃣ Create PhysicsManager
        PhysicsManager physics;
        physics.set_gravity(0.0f);
        physics.enable_collisions(true);

        // 3️⃣ Create a player
        auto player = std::make_shared<Player>(5.0f, 5.0f);
        
        if (!player) {
            std::cerr << "Failed to create player!" << std::endl;
            return 1;
        }

        // 4️⃣ Register player with PhysicsManager
        physics.register_entity(player);

        // Game loop variables
        const float TARGET_FPS = 60.0f;
        const float FRAME_TIME = 1.0f / TARGET_FPS;
        const int TARGET_FRAME_TIME_MS = static_cast<int>(FRAME_TIME * 1000); // ~16ms for 60 FPS
        
        int frameCount = 0;
        const int MAX_FRAMES = 1000;

        std::cout << "Game started. Target frame time: " << TARGET_FRAME_TIME_MS << "ms" << std::endl;

        // 5️⃣ Run game loop
        while (frameCount < MAX_FRAMES) {
            auto frameStart = std::chrono::high_resolution_clock::now();

            // Process input
            input.process_input();

            // Handle movement events
#ifdef _WIN32
            if (input.is_key_pressed(VK_ESCAPE)) {
                std::cout << "Escape pressed - exiting..." << std::endl;
                break;
            }

            if (input.is_key_pressed(VK_UP)) {
                InputEvent e(EventType::MOVE_UP, "keyboard", VK_UP, true);
                player->on_event(e);
            }
            if (input.is_key_pressed(VK_DOWN)) {
                InputEvent e(EventType::MOVE_DOWN, "keyboard", VK_DOWN, true);
                player->on_event(e);
            }
            if (input.is_key_pressed(VK_LEFT)) {
                InputEvent e(EventType::MOVE_LEFT, "keyboard", VK_LEFT, true);
                player->on_event(e);
            }
            if (input.is_key_pressed(VK_RIGHT)) {
                InputEvent e(EventType::MOVE_RIGHT, "keyboard", VK_RIGHT, true);
                player->on_event(e);
            }
#endif

            // Physics & player update
            physics.update(FRAME_TIME);
            player->update(FRAME_TIME);

            // Draw
            player->draw(FRAME_TIME);

            // Frame rate control - Platform-specific sleep
            auto frameEnd = std::chrono::high_resolution_clock::now();
            auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(
                frameEnd - frameStart);
            
            // Calculate sleep time needed to maintain target FPS
            int sleepTime = TARGET_FRAME_TIME_MS - static_cast<int>(frameDuration.count());
            
            if (sleepTime > 0) {
                SLEEP(sleepTime);
            } else if (sleepTime < -5) {
                // If we're running more than 5ms behind, print a warning
                static int warningCounter = 0;
                if (++warningCounter % 60 == 0) { // Print once per second approx
                    std::cout << "Warning: Running behind by " << -sleepTime 
                              << "ms (Frame took " << frameDuration.count() << "ms)" << std::endl;
                }
            }

            frameCount++;

            // Optional FPS display every 60 frames (~1 second at 60 FPS)
            if (frameCount % 60 == 0) {
                auto now = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
                    now - frameStart);
                
                if (elapsed.count() > 0) {
                    float fps = 1000.0f / elapsed.count();
                    std::cout << "Frame " << frameCount << " - FPS: " << fps 
                              << " (Frame time: " << frameDuration.count() << "ms)" << std::endl;
                }
            }
        }

        std::cout << "Game loop ended normally after " << frameCount << " frames." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred!" << std::endl;
        return 1;
    }

    return 0;
}