 #include "SettingsScene.h"

SettingsScene::SettingsScene() : Scene("Settings"), settingsOpen(true)
{
    std::cout << "[SettingsScene] Created" << std::endl;
}

void SettingsScene::openSettings()
{
    settingsOpen = true;
    std::cout << "[SettingsScene] Settings opened" << std::endl;
}

void SettingsScene::closeSettings()
{
    settingsOpen = false;
    std::cout << "[SettingsScene] Settings closed" << std::endl;
}

void SettingsScene::update(float deltaTime)
{
    if (settingsOpen)
        std::cout << "[SettingsScene] Updating settings..." << std::endl;
    else
        std::cout << "[SettingsScene] Settings closed" << std::endl;
}