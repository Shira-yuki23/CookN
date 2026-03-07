#include "SpatialEntity.h"

SpatialEntity::SpatialEntity(const std::string& name, float startX, float startY)
    : Entity(name), x(startX), y(startY), prevX(startX), prevY(startY)
{}