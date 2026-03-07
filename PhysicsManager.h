#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include "SpatialEntity.h"
#include <vector>
#include <memory>

class PhysicsManager {
private:
    std::vector<std::shared_ptr<SpatialEntity>> entities;
    float gravity = 9.8f;
    bool enableCollisionsFlag = true;

public:
    void registerEntity(std::shared_ptr<SpatialEntity> entity);
    void unregisterEntity(std::shared_ptr<SpatialEntity> entity);
    void update(float deltaTime); 
    void move(SpatialEntity& entity, float dx, float dy);  
    bool checkCollision(const SpatialEntity& a, const SpatialEntity& b);
    void setGravity(float g);
    void enableCollisions(bool enable);
};

#endif