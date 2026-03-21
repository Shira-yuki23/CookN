#include "SpatialEntity.h"

SpatialEntity::SpatialEntity(const std::string& name, float start_x, float start_y) : Entity(name), width(1.0f), height(1.0f), is_static(false), prev_x(start_x), prev_y(start_y)
{
    set_position(start_x, start_y);
}
float SpatialEntity::get_width() const
{
    return width;
}

float SpatialEntity::get_height() const
{
    return height;
}

void SpatialEntity::set_size(float w, float h)
{
    width = w;
    height = h;
}

bool SpatialEntity::get_is_static() const
{
    return is_static;
}

void SpatialEntity::set_is_static(bool s)
{
    is_static = s;
}

void SpatialEntity::update_previous_position()
{
    prev_x = x;
    prev_y = y;
}

char SpatialEntity::get_symbol() const
{
    return '?';
}

float SpatialEntity::get_left() const
{
    return get_x();
}

float SpatialEntity::get_right() const
{
    return get_x() + width;
}

float SpatialEntity::get_top() const
{
    return get_y();
}

float SpatialEntity::get_bottom() const
{
    return get_y() + height;
}

float SpatialEntity::get_prev_x() const
{
    return prev_x;
}

float SpatialEntity::get_prev_y() const
{
    return prev_y;
}
