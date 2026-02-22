#include "Entity.h"
#include <iostream>
#include <string>

Entity::Entity(const std::string& entityName)
    : name(entityName), isActive(true),
      x(0), y(0), vx(0), vy(0), tag("")   // ✅ Added only necessary initializations
{
    id = generateUniqueId();              // kept old ID system

    std::cout << "Entity created: "
              << name
              << " (ID: " << id << ")"
              << std::endl;
}

std::string Entity::getId() const {
    return id;
}

std::string Entity::getName() const {
    return name;
}

bool Entity::getIsActive() const {
    return isActive;
}

void Entity::setIsActive(bool active) {
    isActive = active;
}

std::string Entity::generateUniqueId() {
    static int counter = 0;
    return "E" + std::to_string(counter++);
}



void Entity::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

void Entity::setVelocity(float newVx, float newVy) {
    vx = newVx;
    vy = newVy;
}

void Entity::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Entity::setTag(const std::string& t) {
    tag = t;
}

std::string Entity::getTag() const {
    return tag;
}