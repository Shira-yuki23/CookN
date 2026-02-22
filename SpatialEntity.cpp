#include "SpatialEntity.h"
#include <iostream>

using namespace std;

SpatialEntity::SpatialEntity(const string& name, float startX, float startY)
    : Entity(name)
{
    setPosition(startX, startY);
}

float SpatialEntity::getX() const { return x; }
float SpatialEntity::getY() const { return y; }
void SpatialEntity::setPosition(float newX, float newY) { Entity::setPosition(newX, newY); }

void SpatialEntity::update(float deltaTime) {
    // Default spatial entity movement using velocity
    x += vx * deltaTime;
    y += vy * deltaTime;
}

void SpatialEntity::draw() {
    cout << "Drawing SpatialEntity: " << name 
         << " at (" << x << ", " << y << ")" << endl;
}