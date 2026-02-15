#include "Player.h"
#include <iostream>

Player::Player(int startX, int startY)
    : SpatialEntity("Player", startX, startY) {}

void Player::move(int dx, int dy) {
    setPosition(getX() + dx, getY() + dy);
}

void Player::update(float) {
    // movement handled by input/physics
}

void Player::render() {
    std::cout << "Player at (" << getX() << "," << getY() << ")\n";
}
