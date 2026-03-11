#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "entity.h"
#include <string>

class SpatialEntity : public Entity {
protected:
<<<<<<< HEAD
    float width;
    float height;
    bool is_static;

public:
    SpatialEntity(const std::string& name, float start_x, float start_y);

    //sz
    float get_width() const;
    float get_height() const;
    void set_size(float w, float h);

    bool get_is_static() const;
    void set_is_static(bool s);

    //render
    virtual char get_symbol() const;

    //overrd entity
    void update(float delta_time) override = 0;
    void draw(float alpha) override = 0;
    void on_event(const Event& event) override = 0;
    
    //helpers=>phy._hand.
    float get_left() const;
    float get_right() const;
    float get_top() const;
    float get_bottom() const;
=======
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
>>>>>>> arshiyahera-patch-1
};

#endif