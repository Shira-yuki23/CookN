#include "SpatialEntity.h"

SpatialEntity::SpatialEntity(const std::string& name, float start_x, float start_y)
    : Entity(name), x(start_x), y(start_y), prev_x(start_x), prev_y(start_y)
{}
