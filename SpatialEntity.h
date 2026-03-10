#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
    float width = 1.0f;
    float height = 1.0f;
    bool isStatic = false;

public:
    SpatialEntity(const std::string& name, float startX, float startY) : Entity(name)  !
    {
        setPosition(startX, startY); 
    }
    
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    void setSize(float w, float h) { width = w; height = h; }
    
    bool getIsStatic() const { return isStatic; }
    void setIsStatic(bool s) { isStatic = s; }
    
    virtual char getSymbol() const { return '?'; }
    void update() override = 0;  
    void draw() override = 0;    

#endif
