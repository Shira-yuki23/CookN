#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"

class NPC : public SpatialEntity {
public:
<<<<<<< HEAD
    NPC(float startX, float startY);
    
    void update(float deltaTime) override;
    void onEvent(Event& event) override;
    char getSymbol() const override { return 'N'; }
=======
    NPC(float startX = 0, float startY = 0);

    void update(float deltaTime) override;
    void draw() override;
    void onEvent(Event& event) override;
>>>>>>> 29b56c1b6970270daf01c4c6439b989cf6a1884b
};

#endif