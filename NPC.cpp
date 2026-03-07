#include "NPC.h"
#include <iostream>
#include <cstdlib>

NPC::NPC(float startX, float startY): SpatialEntity("NPC", startX, startY){}

void NPC::update(float deltaTime) {
    //Randmove
    int r = rand() % 4;
    switch(r) {
        case 0: setVelocity(1, 0); break;   //right
        case 1: setVelocity(-1, 0); break;  //left
        case 2: setVelocity(0, 1); break;   //down
        case 3: setVelocity(0, -1); break;  //up
    }
}

void NPC::onEvent(Event& event) {

    if (event.type == EventType::COLLISION) {
        std::cout << "NPC collided with entity " << event.senderID << std::endl;
        setVelocity(0,0);
    }

}
