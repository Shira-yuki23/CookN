#ifndef PLAYER_H
#define PLAYER_H

#include "SpatialEntity.h"

class Player : public SpatialEntity {
public:
<<<<<<< HEAD
    Player(float startX, float startY);
    
    void update() override; 

    void draw() override;   

    void on_event(Event& event);
    
    char get_symbol() const override { return 'P'; }
};

#endif
=======
    Player(float startX = 0, float startY = 0);

    void update(float deltaTime) override;
    void draw() override;

    void move(float dx, float dy);
    void onEvent(Event& event) override;
};


#endif

>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
