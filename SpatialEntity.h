#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
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
};

#endif