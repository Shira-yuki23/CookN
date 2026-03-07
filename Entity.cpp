#include "Entity.h"
#include "Event.h"  // ✅ Include this if you use events
#include <iostream>
#include <string>

std::string Entity::generateUniqueId() {
    static int counter = 0;
    return "E" + std::to_string(counter++);
}

Entity::Entity(const std::string& entityName)
    : name(entityName), 
      isActive(true),
      tag("")  // ✅ ONLY initialize non-inclass members
{
    id = generateUniqueId();
    
    // x,y,prevX,prevY,vx,vy are already 0 from in-class initialization
    
    std::cout << "Entity created: " << name << " (ID: " << id << ")" << std::endl;
}

Entity::~Entity() {
    std::cout << "Entity destroyed: " << name << std::endl;
}

// Basic getters/setters
std::string Entity::getId() const { return id; }
std::string Entity::getName() const { return name; }
bool Entity::getIsActive() const { return isActive; }
void Entity::setIsActive(bool active) { isActive = active; }

void Entity::setPosition(float newX, float newY) {
    prevX = x;  // Store previous position
    prevY = y;
    x = newX;
    y = newY;
}

// Note: getX/getY are inline in header

void Entity::setVelocity(float newVx, float newVy) {
    vx = newVx;
    vy = newVy;
}

void Entity::move(float dx, float dy) {
    setPosition(x + dx, y + dy);
}

// Tag methods
void Entity::setTag(const std::string& t) {
    tag = t;
}

std::string Entity::getTag() const {
    return tag;
}