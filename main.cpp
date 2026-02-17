#include <iostream>
#include <memory>
#include <vector>
#include "Entity.h"
#include "SpatialEntity.h"
#include "Player.h"
#include "NPC.h"
#include "PhysicsManager.h"
#include "InputHandler.h"

int main() {
    // Create input and physics managers
    InputHandler input;
    PhysicsManager physics;

    // Create entities
    std::vector<std::unique_ptr<Entity>> entities;

    auto player = std::make_unique<Player>(0, 0);   // x=0, y=0
    auto npc = std::make_unique<NPC>(2, 2);         // x=2, y=2

    entities.push_back(std::move(player));
    entities.push_back(std::move(npc));

    bool running = true;
    while (running) {
        // Get input (for demo, just 1 = move right, 2 = quit)
        int cmd = input.getInput();
        if (cmd == 2) {
            running = false;
            continue;
        }

        // Update positions via physics
        if (cmd == 1) {
            physics.move(*dynamic_cast<SpatialEntity*>(entities[0].get()), 1, 0);
        }

        // Check collision
        if (physics.checkCollision(
                *dynamic_cast<SpatialEntity*>(entities[0].get()),
                *dynamic_cast<SpatialEntity*>(entities[1].get()))) {
            std::cout << "Collision!\n";
        }

        // Update & render all entities
        for (auto& e : entities) {
            e->update(0.016f);   // deltaTime ~16ms
            e->render();
        }

        std::cout << "----------------------\n";
    }

    return 0;
}
