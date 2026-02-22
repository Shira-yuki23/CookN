    #ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "Scene.h"

// Forward declaration so Engine can be friend
class Engine;

class SceneManager {
private:
    std::shared_ptr<Scene> currentScene;
    std::map<std::string, std::shared_ptr<Scene>> scenes;

    // Engine can access private members
    friend class Engine;

public:
    SceneManager();
    ~SceneManager();

    void addScene(const std::shared_ptr<Scene>& scene);
    void removeScene(const std::string& sceneName);
    void switchScene(const std::string& sceneName);
    std::shared_ptr<Scene> getCurrentScene() const;

    // Utility function for debugging
    void printAllScenes() const;
};

#endif // SCENEMANAGER_H