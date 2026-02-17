#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class IRenderer;   // IMPORTANT

class Player : public Entity {
private:
    int x;
    int y;
    int health;

public:
    Player(const std::string& name, int xPos, int yPos);

    void update() override;
    void draw(IRenderer& renderer) override;

    void takeDamage(int amount);
};

#endif
