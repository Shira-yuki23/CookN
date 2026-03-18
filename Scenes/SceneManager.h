 #pragma once
#include <memory>
#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>
#include "Scene.h"

class SceneManager
{
private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;

    std::stack<std::string> sceneHistory;   // NEW FEATURE

public:
    SceneManager();
    ~SceneManager();

    void addScene(const std::shared_ptr<Scene>& scene);
    void removeScene(const std::string& sceneName);

    void switchScene(const std::string& sceneName);

    // NEW FUNCTION
    void goBack();

    std::shared_ptr<Scene> getCurrentScene() const;

    void printAllScenes() const;
    void createAndAddScene(const std::string& sceneName);
};
