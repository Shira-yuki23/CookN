#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"

class NPC : public SpatialEntity {
public:
    NPC(float startX = 0, float startY = 0);

    void update(float deltaTime) override;
    void draw() override;
    void onEvent(Event& event) override;
};

#endif