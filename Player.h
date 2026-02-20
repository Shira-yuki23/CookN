#ifndef PLAYER_H
#define PLAYER_H

#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
    Player(float startX = 0, float startY = 0);

    void update(float deltaTime) override;
    void draw() override;

    void move(float dx, float dy);
    void onEvent(Event& event) override;
};

#endif