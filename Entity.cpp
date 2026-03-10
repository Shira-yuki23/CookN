#include "Entity.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
    x = newX;
    y = newY;
}

<<<<<<< HEAD
// Note: getX/getY are inline in header
=======
float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b

void Entity::setVelocity(float newVx, float newVy) {
    vx = newVx;
    vy = newVy;
}

void Entity::move(float dx, float dy) {
<<<<<<< HEAD
    setPosition(x + dx, y + dy);
}

// Tag methods
=======
    x += dx;
    y += dy;
}

>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
void Entity::setTag(const std::string& t) {
    tag = t;
}

std::string Entity::getTag() const {
    return tag;
}