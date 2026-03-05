 #pragma once

#include <memory>
#include <map>
#include <string>
#include <iostream>

#include "Scene.h"
#include "SceneFactory.h"

class SceneManager {
private:
    std::map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;

public:
    SceneManager();
    ~SceneManager();

    void addScene(const std::shared_ptr<Scene>& scene);
    void removeScene(const std::string& sceneName);

    void switchScene(const std::string& sceneName);

    // NEW FUNCTION
    void createAndAddScene(const std::string& sceneName);

    std::shared_ptr<Scene> getCurrentScene() const;

    void printAllScenes() const;
};