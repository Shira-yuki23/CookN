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

<<<<<<< HEAD
<<<<<<< HEAD
#endif
=======
#endif


>>>>>>> 4569e1523a852dfdc9dd00d7f7a793d0362ce5d6
=======
#endif

>>>>>>> origin/main
