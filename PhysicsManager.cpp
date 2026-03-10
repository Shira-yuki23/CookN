#include "PhysicsManager.h"
#include <algorithm>

void PhysicsManager::update(float delta_time) {
    for (auto& entity : entities) {
        if (entity->get_is_static()) continue;

        float vx = entity->get_vx();  
        float vy = entity->get_vy(); 

        vy += gravity * delta_time;
        entity->set_velocity(vx, vy);

        entity->set_position(
            entity->get_x() + vx * delta_time,
            entity->get_y() + vy * delta_time
        );
    }

    if (enable_collision_flag) {
        for (size_t i = 0; i < entities.size(); i++) {
            for (size_t j = i + 1; j < entities.size(); j++) {
                if (check_collision(*entities[i], *entities[j])) {
                    entities[i]->set_velocity(0,0);
                    entities[j]->set_velocity(0,0);
                }
            }
        }
    }
}