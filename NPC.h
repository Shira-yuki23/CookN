#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"

class NPC : public SpatialEntity {
public:
    NPC(float startX, float startY);
    
    void update(float deltaTime) override;
    void onEvent(Event& event) override;
    char getSymbol() const override { return 'N'; }
};

#endif