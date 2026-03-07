 #pragma once

#include "Scene.h"
#include <iostream>

class PauseScene : public Scene {
private:
    bool paused;

public:
    PauseScene();

    void update(float deltaTime) override;

    void pause();
    void resume();
};