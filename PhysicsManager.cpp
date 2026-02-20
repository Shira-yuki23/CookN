#include "PhysicsManager.h"
void PhysicsManager::move(
    SpatialEntity& entity,
    int dx,
    int dy
) {
    entity.setPosition(
        entity.getX() + dx,
        entity.getY() + dy
    );
}
bool PhysicsManager::checkCollision(
    const SpatialEntity& a,
    const SpatialEntity& b
)
{ return a.getX() == b.getX() && a.getY() == b.getY();}