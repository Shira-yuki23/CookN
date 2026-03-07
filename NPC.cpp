#include "NPC.h"
#include "event.h"
#include <iostream>
#include <cstdlib>

<<<<<<< HEAD
NPC::NPC(float startX, float startY): SpatialEntity("NPC", startX, startY){}

void NPC::update(float deltaTime) {
    //Randmove
    int r = rand() % 4;
    switch(r) {
        case 0: setVelocity(1, 0); break;   //right
        case 1: setVelocity(-1, 0); break;  //left
        case 2: setVelocity(0, 1); break;   //down
        case 3: setVelocity(0, -1); break;  //up
    }
}

void NPC::onEvent(Event& event) {

    if (event.type == EventType::COLLISION) {
        std::cout << "NPC collided with entity " << event.senderID << std::endl;
        setVelocity(0,0);
    }

=======
using namespace std;

NPC::NPC(float startX, float startY)
    : SpatialEntity("NPC", startX, startY)
{
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
}

void NPC::update(float deltaTime) {
    // Example: simple AI move randomly (placeholder)
    x += vx * deltaTime;
    y += vy * deltaTime;
}

void NPC::draw() {
    cout << "NPC " << name << " at (" << x << ", " << y << ")" << endl;
}

void NPC::onEvent(Event& event) {
    switch (event.type) {
        // --- Input Events ---
        case EventType::MOVE_UP: vx = 0; vy = -1; break;
        case EventType::MOVE_DOWN: vx = 0; vy = 1; break;
        case EventType::MOVE_LEFT: vx = -1; vy = 0; break;
        case EventType::MOVE_RIGHT: vx = 1; vy = 0; break;
        case EventType::ATTACK:
            std::cout << name << " attacks!\n"; break;
        case EventType::INTERACT:
            std::cout << name << " interacts!\n"; break;
        case EventType::PAUSE:
            break; // NPC ignores pause
        case EventType::QUIT:
            isActive = false; break; // NPC quits if needed

        // --- Collision Events ---
        case EventType::COLLISION:
            vx = 0; vy = 0;
            std::cout << name << " collided with entity " << event.senderID << "\n"; break;
        case EventType::BLOCKED:
            vx = 0; vy = 0; break;
        case EventType::ITEM_COLLECTED:
            break; // NPC ignores for now

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
            std::cout << name << " scene switching to " << event.senderID << "\n"; break;
        case EventType::LEVEL_COMPLETE:
        case EventType::GAME_OVER:
            isActive = false; break;

        // --- Entity Lifecycle ---
        case EventType::SPAWN:
            isActive = true; break;
        case EventType::DESTROY:
            isActive = false; break;

        default: break; // Ignore unknown events
    }
}