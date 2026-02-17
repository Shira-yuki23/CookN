#include "Entity.h"

Entity::Entity(const std::string& entityName)
    : name(entityName), isActive(true)
{
    static int counter = 0;
    id = "E" + std::to_string(counter++);
    std::cout << "Entity created: " << name << " (ID: " << id << ")\n";
}

std::string Entity::getId() const { return id; }
std::string Entity::getName() const { return name; }
bool Entity::getIsActive() const { return isActive; }
void Entity::setIsActive(bool active) { isActive = active; }
