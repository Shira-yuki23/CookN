#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
    float width = 1.0f;
    float height = 1.0f;
    bool is_static = false;

public:
    SpatialEntity(const std::string& name, float start_x, float start_y)
        : Entity(name)  // Entity handles position!
    {
        set_position(start_x, start_y);  // Use Entity's method
    }
    
    // Size (specific to SpatialEntity)
    float get_width() const { return width; }
    float get_height() const { return height; }
    void set_size(float w, float h) { width = w; height = h; }
    
    // Properties
    bool get_is_static() const { return is_static; }
    void set_is_static(bool s) { is_static = s; }
    
    // For rendering
    virtual char get_symbol() const { return '?'; }
    
    // SpatialEntity still needs to implement pure virtuals from Entity
    void update() override = 0;  // Still pure virtual
    void draw() override = 0;    // Still pure virtual
    bool get_is_static() const { return isStatic; }
    void set_is_static(bool s) { isStatic = s; }
    
    virtual char get_symbol() const { return '?'; }
    void update() override = 0;  
    void draw() override = 0;    
};
#endif
