#include "NPC.h"
#include <iostream>

NPC::NPC(int x, int y)
    : SpatialEntity("NPC", x, y) {}

void NPC::update(float) {}

void NPC::render() {
    std::cout << "NPC at (" << getX() << "," << getY() << ")\n";
}
