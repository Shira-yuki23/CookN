#include <iostream>
#include <memory>
#include <vector>
#include "Entity.h"

// Minimal Player class for demo
class Player : public Entity {
public:
    Player(float x_, float y_) : Entity("Player") { setPosition(x_, y_); }

    void update() override {
        // Example: could update animations, physics, etc.
    }

    void draw() override {
        std::cout << getName() << " at (" << getX() << ", " << getY() << ")\n";
    }
};

// Minimal NPC class for demo
class NPC : public Entity {
public:
    NPC(float x_, float y_) : Entity("NPC") { setPosition(x_, y_); }

    void update() override {
        // Example AI movement could go here
    }

    void draw() override {
        std::cout << getName() << " at (" << getX() << ", " << getY() << ")\n";
    }
};

// Simple InputHandler for demo
class InputHandler {
public:
    int getInput() {
        std::cout << "Enter 1 to move right, 2 to quit: ";
        int cmd;
        std::cin >> cmd;
        return cmd;
    }
};

// Simple PhysicsManager for demo
class PhysicsManager {
public:
    void move(Entity& e, float dx, float dy) {
        e.move(dx, dy);
    }

    bool checkCollision(const Entity& a, const Entity& b) {
        // Simple collision: same integer position
        return (static_cast<int>(a.getX()) == static_cast<int>(b.getX()) &&
                static_cast<int>(a.getY()) == static_cast<int>(b.getY()));
    }
};

int main() {
    InputHandler input;
    PhysicsManager physics;

    std::vector<std::unique_ptr<Entity>> entities;
    entities.push_back(std::make_unique<Player>(0, 0));
    entities.push_back(std::make_unique<NPC>(2, 2));

    bool running = true;
    while (running) {
        int cmd = input.getInput();
        if (cmd == 2) {
            running = false;
            continue;
        }

        if (cmd == 1) {
            physics.move(*entities[0], 1, 0); // move player right
        }

        if (physics.checkCollision(*entities[0], *entities[1])) {
            std::cout << "Collision!\n";
        }

        for (auto& e : entities) {
            e->update();
            e->draw();
        }

        std::cout << "---------------------\n";
    }

    return 0;
}