#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
    float width = 1.0f;
    float height = 1.0f;
    bool isStatic = false;

public:
    SpatialEntity(const std::string& name, float startX, float startY) : Entity(name)  
    {
        setPosition(startX, startY); 
    }
    
    float get_width() const { return width; }
    float get_height() const { return height; }
    void set_size(float w, float h) { width = w; height = h; }
    
    bool get_is_static() const { return isStatic; }
    void set_is_static(bool s) { isStatic = s; }
    
    virtual char get_symbol() const { return '?'; }
    void update() override = 0;  
    void draw() override = 0;    

#endif
