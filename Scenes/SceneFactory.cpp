 #include "SceneFactory.h"
#include "Scene.h"

#include <iostream>

std::shared_ptr<Scene> SceneFactory::createScene(const std::string& sceneName)
{
    if (sceneName == "Menu") {
        return std::make_shared<MenuScene>();
    }
    else if (sceneName == "Game") {
        return std::make_shared<Scene>("Game");
    }
    else if (sceneName == "Pause") {
        return std::make_shared<Scene>("Pause");
    }
    else {
        std::cout << "Unknown scene type: " << sceneName << std::endl;
        return nullptr;
    }
}