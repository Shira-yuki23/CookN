#ifndef SPATIAL_ENTITY_H
#define SPATIAL_ENTITY_H

#include "Entity.h"

class SpatialEntity : public Entity {
protected:
    int x;
    int y;

public:
    SpatialEntity(const std::string& name, int startX, int startY);

    int getX() const;
    int getY() const;
    void setPosition(int newX, int newY);
    //from entity
    void update(float deltaTime) override;
    void render() override;
};

#endif

