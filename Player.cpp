#include "Player.h"
#include "event.h"
#include "Event.h"
#include <iostream>
using namespace std;

Player::Player(float startX, float startY) 
    : SpatialEntity("Player", startX, startY)
{}

void Player::update() {
    // Use Entity's velocity and position
    set_position(get_x() + get_vx(), get_y() + get_vy());
}

void Player::draw() {
    cout << "Player at (" << static_cast<int>(get_x()) << "," 
         << static_cast<int>(get_y()) << ")\n";  
}

void Player::on_event(Event& event) {
    switch (event.type) {
        case EventType::MOVE_UP: 
            set_position(get_x(), get_y() - 1);
            break;
        case EventType::MOVE_DOWN: 
            set_position(get_x(), get_y() + 1);
            break;
        case EventType::MOVE_LEFT: 
            set_position(get_x() - 1, get_y());
            break;
        case EventType::MOVE_RIGHT: 
            set_position(get_x() + 1, get_y());
            break;
        case EventType::ATTACK:
            cout << name << " attacks!\n"; 
            break;
        // ... rest of cases
        default: break;
    }
}
