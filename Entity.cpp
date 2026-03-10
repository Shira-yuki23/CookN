
#include "entity.h"
#include <string>
#include <sstream>

<<<<<<< HEAD
std::string Entity::generate_unique_id() {
=======
Entity::Entity(const std::string& entityName)
    : name(entityName), isActive(true),
      x(0), y(0), vx(0), vy(0), tag("")   // only necessary initializations
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
>>>>>>> origin/arshiyahera-patch-1
    static int counter = 0;
    std::ostringstream oss;
    oss << "e" << counter++;
    return oss.str();
}

Entity::Entity(const std::string& entity_name)
    : id(generate_unique_id()), name(entity_name), is_active(true),
      x(0.0f), y(0.0f), vx(0.0f), vy(0.0f), tag("")
{
    std::cout << "Entity created: " << name << " (ID: " << id << ")" << std::endl;
}

std::string Entity::get_id() const { return id; }
std::string Entity::get_name() const { return name; }

bool Entity::get_is_active() const { return is_active; }
void Entity::set_is_active(bool active) { is_active = active; }

void Entity::set_position(float new_x, float new_y) {
    x = new_x;
    y = new_y;
}

float Entity::get_x() const { return x; }
float Entity::get_y() const { return y; }

void Entity::set_velocity(float new_vx, float new_vy) {
    vx = new_vx;
    vy = new_vy;
}

void Entity::move(float dx, float dy) {
    x += dx;
    y += dy;
}

<<<<<<< HEAD
void Entity::set_tag(const std::string& t) { tag = t; }
std::string Entity::get_tag() const { return tag; }
=======
void Entity::setTag(const std::string& t) {
    tag = t;
}

std::string Entity::getTag() const {
    return tag;
}
>>>>>>> origin/arshiyahera-patch-1
