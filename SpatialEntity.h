#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
    // ONLY add what Entity doesn't have
    float width = 1.0f;
    float height = 1.0f;
    bool isStatic = false;

public:
    SpatialEntity(const std::string& name, float startX, float startY)
        : Entity(name)  // Entity handles position!
    {
        setPosition(startX, startY);  // Use Entity's method
    }
    
    // Size (specific to SpatialEntity)
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    void setSize(float w, float h) { width = w; height = h; }
    
    // Properties
    bool getIsStatic() const { return isStatic; }
    void setIsStatic(bool s) { isStatic = s; }
    
    // For rendering
    virtual char getSymbol() const { return '?'; }
    
    // SpatialEntity still needs to implement pure virtuals from Entity
    void update() override = 0;  // Still pure virtual
    void draw() override = 0;    // Still pure virtual
};

#endif