#ifndef PLAYER_H
#define PLAYER_H

#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
    Player(float startX, float startY);
    
    void update() override; 

    void draw() override;   

    void on_event(Event& event);
    
    char get_symbol() const override { return 'P'; }
};

#endif