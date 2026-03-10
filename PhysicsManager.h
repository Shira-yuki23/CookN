#ifndef PHYSICS_MANAGER_H
#define PHYSICS_MANAGER_H

#include "SpatialEntity.h"
#include <vector>
#include <memory>

class PhysicsManager {
private:
    std::vector<std::shared_ptr<SpatialEntity>> entities;
    float gravity = 9.8f;
    bool _cFlag = true;

public:
    void register_entity(std::shared_ptr<SpatialEntity> entity);
    void unregister_entity(std::shared_ptr<SpatialEntity> entity);
    void update(float deltaTime); 
    void move(SpatialEntity& entity, float dx, float dy);  
    bool check_collision(const SpatialEntity& a, const SpatialEntity& b);
    void set_gravity(float g);
    void enable_collisions(bool enable);
};

#endif
