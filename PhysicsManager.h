#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include "SpatialEntity.h"

class PhysicsManager {
public:
    void move(SpatialEntity& entity, int dx, int dy);

    bool checkCollision(
        const SpatialEntity& a,
        const SpatialEntity& b
    );
};

#endif


