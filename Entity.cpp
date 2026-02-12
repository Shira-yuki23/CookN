#include "Entity.h"
#include <iostream>
#include <string>

Entity::Entity(const std::string& entityName)
    : name(entityName), isActive(true)
{
    id = generateUniqueId();

   
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
