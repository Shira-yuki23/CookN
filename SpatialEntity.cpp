#include "spatial_entity.h"
#include <iostream>

SpatialEntity::SpatialEntity(const std::string& name, float start_x, float start_y)
    : Entity(name)
{
    set_position(start_x, start_y);
}

// Optional: basic movement update using velocity
void SpatialEntity::update(float delta_time)
{
    if (!get_is_active() || get_is_static())
        return;

    move(get_vx() * delta_time, get_vy() * delta_time);
}

// Optional: simple debug draw
void SpatialEntity::draw(float alpha)
{
    // This is a placeholder. In a real engine, you'd draw sprites.
    std::cout << "Drawing SpatialEntity '" << get_name()
              << "' at (" << get_x() << ", " << get_y() << ")"
              << " with symbol '" << get_symbol() << "'\n";
}

// Basic event handling skeleton
void SpatialEntity::on_event(const Event& event)
{
    // Example: print the event type
    // std::cout << "SpatialEntity '" << get_name() << "' received event\n";
}