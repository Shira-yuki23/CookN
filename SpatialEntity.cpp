#include "spatial_entity.h"
#include <iostream>

<<<<<<< HEAD
SpatialEntity::SpatialEntity(const std::string& name, float start_x, float start_y) : Entity(name), width(1.0f), height(1.0f), is_static(false)
=======
SpatialEntity::SpatialEntity(const std::string& name, float start_x, float start_y)
    : Entity(name)
>>>>>>> arshiyahera-patch-1
{
    set_position(start_x, start_y);
}

<<<<<<< HEAD
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

char SpatialEntity::get_symbol() const
{
    return '?';
}

//for_collision=>phy._hand.
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
=======
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
>>>>>>> arshiyahera-patch-1
}