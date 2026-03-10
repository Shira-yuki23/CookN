#include "Player.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "Event.h"
=======
#include "event.h"
>>>>>>> 4569e1523a852dfdc9dd00d7f7a793d0362ce5d6
=======
#include "event.h"
#include "Event.h"
>>>>>>> origin/main
#include <iostream>
using namespace std;

Player::Player(float startX, float startY) 
    : SpatialEntity("Player", startX, startY)
{}

void Player::update() {
    // Use Entity's velocity and position
    setPosition(getX() + getVX(), getY() + getVY());
}

void Player::draw() {
    cout << "Player at (" << static_cast<int>(getX()) << "," 
         << static_cast<int>(getY()) << ")\n";  
}

void Player::onEvent(Event& event) {
    switch (event.type) {
        case EventType::MOVE_UP: 
            setPosition(getX(), getY() - 1);
            break;
        case EventType::MOVE_DOWN: 
            setPosition(getX(), getY() + 1);
            break;
        case EventType::MOVE_LEFT: 
            setPosition(getX() - 1, getY());
            break;
        case EventType::MOVE_RIGHT: 
            setPosition(getX() + 1, getY());
            break;
        case EventType::ATTACK:
            cout << name << " attacks!\n"; 
            break;
        // ... rest of cases
        default: break;
    }
}
