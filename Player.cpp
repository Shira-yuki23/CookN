#include "Player.h"
#include "Event.h"
#include <iostream>

Player::Player(int startX, int startY)
    : SpatialEntity("Player", startX, startY)
{
    // ✅ Constructor uses base class SpatialEntity
}

void Player::move(int dx, int dy) {
    Entity::move(static_cast<float>(dx), static_cast<float>(dy));  
    // ✅ Uses base move() now
}

void Player::update(float deltaTime) {  
    x += vx * deltaTime;  
    y += vy * deltaTime;  
    // ✅ Update uses velocity and deltaTime from base
}

void Player::render() {
    std::cout << "Player at (" << static_cast<int>(x) << "," << static_cast<int>(y) << ")\n";  
    // ✅ Uses base x,y
}

// --- Complete event handling ---
void Player::onEvent(Event& event) {
    switch (event.type) {

        // --- Input Events ---
        case EventType::MOVE_UP: move(0, -1); break;
        case EventType::MOVE_DOWN: move(0, 1); break;
        case EventType::MOVE_LEFT: move(-1, 0); break;
        case EventType::MOVE_RIGHT: move(1, 0); break;
        case EventType::ATTACK:
            std::cout << name << " attacks!\n"; break;
        case EventType::INTERACT:
            std::cout << name << " interacts!\n"; break;
        case EventType::PAUSE:
            std::cout << "Game paused\n"; break;
        case EventType::QUIT:
            std::cout << "Player quits game\n"; break;

        // --- Collision Events ---
        case EventType::COLLISION:
            vx = 0; vy = 0;
            std::cout << name << " collided with entity " << event.senderID << "\n"; break;
        case EventType::BLOCKED:
            std::cout << name << " is blocked by " << event.senderID << "\n"; break;
        case EventType::ITEM_COLLECTED:
            std::cout << name << " collected an item!\n"; break;

        // --- Combat Events ---
        case EventType::DAMAGE_TAKEN:
            std::cout << name << " took " << event.value << " damage!\n"; break;
        case EventType::HEAL:
            std::cout << name << " healed " << event.value << " HP!\n"; break;
        case EventType::DEATH:
            isActive = false;
            std::cout << name << " died!\n"; break;

        // --- Scene Events ---
        case EventType::SCENE_SWITCH:
            std::cout << name << " switching scene to " << event.senderID << "\n"; break;
        case EventType::LEVEL_COMPLETE:
            std::cout << name << " completed level!\n"; break;
        case EventType::GAME_OVER:
            std::cout << "Game Over for " << name << "\n"; break;

        // --- Entity Lifecycle ---
        case EventType::SPAWN:
            isActive = true; break;
        case EventType::DESTROY:
            isActive = false; break;

        default: break; // Unknown events ignored
    }
}