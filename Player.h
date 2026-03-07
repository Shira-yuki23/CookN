#ifndef PLAYER_H
#define PLAYER_H

#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
    Player(float startX, float startY);
    
    void update() override; 

    void draw() override;   

    void onEvent(Event& event);
    
    char getSymbol() const override { return 'P'; }
};

#endif

