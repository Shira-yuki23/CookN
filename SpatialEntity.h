#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "entity.h"
#include <string>

class SpatialEntity : public Entity {
protected:
    float width = 1.0f;
    float height = 1.0f;
    bool is_static = false;

public:
    SpatialEntity(const std::string& name, float start_x = 0.0f, float start_y = 0.0f)
        : Entity(name)
    {
        set_position(start_x, start_y);
    }

    // Size accessors
    float get_width() const { return width; }
    float get_height() const { return height; }
    void set_size(float w, float h) { width = w; height = h; }

    // Static flag
    bool get_is_static() const { return is_static; }
    void set_is_static(bool s) { is_static = s; }

    // Symbol for debugging / console representation
    virtual char get_symbol() const { return '?'; }

    // Polymorphic functions matching new Entity
    void update(float delta_time) override = 0;
    void draw(float alpha) override = 0;
    void on_event(const Event& event) override = 0;
};

#endif