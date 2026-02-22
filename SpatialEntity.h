#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
public:
    SpatialEntity(const string& name, float startX = 0, float startY = 0);

    float getX() const;
    float getY() const;
    void setPosition(float newX, float newY);

    void update(float deltaTime) override;
    void draw() override;
};

#endif