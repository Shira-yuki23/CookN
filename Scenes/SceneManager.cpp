   #include "SceneManager.h"

SceneManager::SceneManager() {
    std::cout << "[SceneManager] Created" << std::endl;
}

SceneManager::~SceneManager() {
    std::cout << "[SceneManager] Destroyed" << std::endl;
}

void SceneManager::addScene(const std::shared_ptr<Scene>& scene) {
    if (!scene) return;
    scenes[scene->getName()] = scene;
    std::cout << "[SceneManager] Added scene: " << scene->getName() << std::endl;
}

void SceneManager::removeScene(const std::string& sceneName) {
    scenes.erase(sceneName);
    std::cout << "[SceneManager] Removed scene: " << sceneName << std::endl;
    if (currentScene && currentScene->getName() == sceneName)
        currentScene = nullptr;
}

void SceneManager::switchScene(const std::string& sceneName) {
    if (scenes.find(sceneName) != scenes.end()) {
        currentScene = scenes[sceneName];
        std::cout << "[SceneManager] Switched to scene: " << sceneName << std::endl;
        currentScene->update(0.0f);
    } else {
        std::cerr << "[SceneManager] Scene not found: " << sceneName << std::endl;
    }
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() const {
    return currentScene;
}

void SceneManager::printAllScenes() const {
    std::cout << "[SceneManager] Scenes list:" << std::endl;
    for (auto& pair : scenes) {
        std::cout << " - " << pair.first << std::endl;
    }
}