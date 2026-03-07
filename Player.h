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

<<<<<<< HEAD
#endif
=======
#endif


>>>>>>> 4569e1523a852dfdc9dd00d7f7a793d0362ce5d6
