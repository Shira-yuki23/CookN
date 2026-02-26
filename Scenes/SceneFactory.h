 #pragma once
#include <memory>
#include <string>
#include <iostream>
#include "Scene.h"

// Single-file SceneFactory
class SceneFactory {
public:
    // Create scene by name
    static std::shared_ptr<Scene> createScene(const std::string& sceneName) {
        if (sceneName == "Menu") {
            return std::make_shared<Scene>("Menu");
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
};