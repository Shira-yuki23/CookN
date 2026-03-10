#include "PhysicsManager.h"
#include <algorithm>

void PhysicsManager::update(float deltaTime) {
    for (auto& entity : entities) {
        if (entity->getIsStatic()) continue;

        float vx = entity->getVX();  
        float vy = entity->getVY(); 

        vy += gravity * deltaTime;
        entity->setVelocity(vx, vy);

        entity->setPosition(
            entity->getX() + vx * deltaTime,
            entity->getY() + vy * deltaTime
        );
    }

    if (enableCollisionsFlag) {
        for (size_t i = 0; i < entities.size(); i++) {
            for (size_t j = i + 1; j < entities.size(); j++) {
                if (checkCollision(*entities[i], *entities[j])) {
                    entities[i]->setVelocity(0,0);
                    entities[j]->setVelocity(0,0);
                }
            }
        }
    }
}