#ifndef NPC_H
#define NPC_H

#include "SpatialEntity.h"

class NPC : public SpatialEntity {
public:
    NPC(int x, int y);

    void update(float deltaTime) override;
    void render() override;
};

#endif

