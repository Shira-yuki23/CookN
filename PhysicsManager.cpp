#include "PhysicsManager.h"
#include <algorithm>
#include <iostream> // optional, for debug prints

// Register a new entity to the physics system
void PhysicsManager::register_entity(std::shared_ptr<SpatialEntity> entity) {
    if (entity && std::find(entities.begin(), entities.end(), entity) == entities.end()) {
        entities.push_back(entity);
        // std::cout << "[PHYSICS] Entity registered\n";
    }
}

// Remove an entity from the physics system
void PhysicsManager::unregister_entity(std::shared_ptr<SpatialEntity> entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    // std::cout << "[PHYSICS] Entity unregistered\n";
}

// Move entity by dx, dy (ignores velocity)
void PhysicsManager::move(SpatialEntity& entity, float dx, float dy) {
    entity.set_position(entity.get_x() + dx, entity.get_y() + dy);
}

//collision check
bool PhysicsManager::check_collision(const SpatialEntity& a, const SpatialEntity& b) const {
    float ax1 = a.get_x();
    float ay1 = a.get_y();
    float ax2 = ax1 + a.get_width();
    float ay2 = ay1 + a.get_height();

    float bx1 = b.get_x();
    float by1 = b.get_y();
    float bx2 = bx1 + b.get_width();
    float by2 = by1 + b.get_height();

    // Check overlap
    bool overlap_x = ax1 < bx2 && ax2 > bx1;
    bool overlap_y = ay1 < by2 && ay2 > by1;

    return overlap_x && overlap_y;
}

//gravity
void PhysicsManager::set_gravity(float g) {
    gravity = g;
    // std::cout << "[PHYSICS] Gravity set to " << gravity << "\n";
}

//collisions enabler
void PhysicsManager::enable_collisions(bool enable) {
    collision = enable;
    // std::cout << "[PHYSICS] Collisions " << (collision ? "enabled" : "disabled") << "\n";
}

void PhysicsManager::update(float deltaTime) {
    for (auto& entity : entities) {
        if (entity->get_is_static()) continue;

        // Apply gravity to vertical velocity
        float vx = entity->get_vx();
        float vy = entity->get_vy() + gravity * deltaTime;
        entity->set_velocity(vx, vy);

        // Move entity by its velocity
        entity->set_position(
            entity->get_x() + vx * deltaTime,
            entity->get_y() + vy * deltaTime
        );
    }

    // Collision handling
    if (collision) {
        for (size_t i = 0; i < entities.size(); i++) {
            for (size_t j = i + 1; j < entities.size(); j++) {
                if (check_collision(*entities[i], *entities[j])) {
                    // Simple response: stop both entities
                    entities[i]->set_velocity(0.0f, 0.0f);
                    entities[j]->set_velocity(0.0f, 0.0f);
                }
            }
        }
    }
}