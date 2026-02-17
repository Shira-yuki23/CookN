#include "Player.h"
#include "IRenderer.h"
#include <iostream>

Player::Player(const std::string& name, int xPos, int yPos)
    : Entity(name), x(xPos), y(yPos), health(100) {}

void Player::update() {
    // Example movement
    x += 1;
}

void Player::draw(IRenderer& renderer) {
    renderer.drawPlayer(x, y);
}

void Player::takeDamage(int amount) {
    health -= amount;

    if (health <= 0) {
        setIsActive(false);
        std::cout << getName() << " died.\n";
    }
}
