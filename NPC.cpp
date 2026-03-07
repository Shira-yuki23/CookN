#include "NPC.h"
#include <iostream>
#include <cstdlib>

NPC::NPC(float start_x, float start_y): SpatialEntity("NPC", start_x, start_y){}

void NPC::update(float deltaTime) {
    //Randmove
    int r = rand() % 4;
    switch(r) {
        case 0: set_valocity(1, 0); break;   //right
        case 1: set_valocity(-1, 0); break;  //left
        case 2: set_valocity(0, 1); break;   //down
        case 3: set_valocity(0, -1); break;  //up
    }
}

void NPC::onEvent(Event& event) {

    if (event.type == EventType::COLLISION) {
        std::cout << "NPC collided with entity " << event.senderID << std::endl;
        set_valocity(0,0);
    }

}
