#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
<<<<<<< HEAD
protected:
    // ONLY add what Entity doesn't have
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
=======
public:
    SpatialEntity(const string& name, float startX = 0, float startY = 0);

    float getX() const;
    float getY() const;
    void setPosition(float newX, float newY);

    void update(float deltaTime) override;
    void draw() override;
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
};

#endif