 #pragma once
#include "Scene.h"
#include <iostream>

class SettingsScene : public Scene {
private:
    bool settingsOpen;
public:
    SettingsScene();
    void update(float deltaTime) override;
    void openSettings();
    void closeSettings();
};