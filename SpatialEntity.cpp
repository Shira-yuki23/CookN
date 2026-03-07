#include "SpatialEntity.h"
<<<<<<< HEAD

SpatialEntity::SpatialEntity(const std::string& name, float startX, float startY)
    : Entity(name), x(startX), y(startY), prevX(startX), prevY(startY)
{}
=======
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
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
