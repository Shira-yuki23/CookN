 #include "SceneFactory.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "PauseScene.h"
#include "SettingsScene.h"   // ✅ New
#include "CreditsScene.h"    // ✅ New
#include <iostream>

std::shared_ptr<Scene> SceneFactory::createScene(const std::string& sceneName)
{
    if (sceneName == "Menu")
        return std::make_shared<MenuScene>();
    else if (sceneName == "Game")
        return std::make_shared<GameScene>();
    else if (sceneName == "Pause")
        return std::make_shared<PauseScene>();
    else if (sceneName == "Settings")
        return std::make_shared<SettingsScene>();
    else if (sceneName == "Credits")
        return std::make_shared<CreditsScene>();
    else
    {
        std::cout << "Unknown scene type: " << sceneName << std::endl;
        return nullptr;
    }
}