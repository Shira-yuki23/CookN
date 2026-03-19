 #pragma once
#include "Scene.h"
#include <iostream>

class CreditsScene : public Scene {
public:
    CreditsScene();
    void update(float deltaTime) override;
};