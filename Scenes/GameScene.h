 #pragma once

#include "Scene.h"
#include <iostream>

class GameScene : public Scene {
private:
    bool isRunning;
    float elapsedTime;

public:
    GameScene();

    void update(float deltaTime) override;

    void startGame();
    void stopGame();
};