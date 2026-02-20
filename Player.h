#ifndef PLAYER_H
#define PLAYER_H


#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
    Player(int startX, int startY);

    void update(float deltaTime) override;
    void render() override;

    void move(int dx, int dy);
};

#endif


