#include "SpatialEntity.h"
#include<iostream>

SpatialEntity::SpatialEntity(const std::string& name, int startX,int startY) : Entity(name), x(startX), y(startY) {}
int SpatialEntity::getX() const { return x; }
int SpatialEntity::getY() const { return y; }

void SpatialEntity::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}
void SpatialEntity::update(float) {
    // hv to chng for movable obj 
}
void SpatialEntity::render() {
    std::cout << name << " at (" << x << "," << y << ")\n";
}