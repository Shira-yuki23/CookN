 #pragma once

#include "Scene.h"
#include <iostream>

class MenuScene : public Scene {
public:
    MenuScene();

    void update(float deltaTime) override;
};