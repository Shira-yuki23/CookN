#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity(const string& entityName)
    : name(entityName), isActive(true) {
    id = generateUniqueId();
    cout << "Entity created: " << name << " (ID: " << id << ")" << endl;
}

string Entity::getId() const {
    return id;
}

string Entity::getName() const {
    return name;
}

bool Entity::getIsActive() const {
    return isActive;
}

void Entity::setIsActive(bool active) {
    isActive = active;
}

string Entity::generateUniqueId() {
    static int counter = 0;
    return "E" + to_string(counter++);
}
