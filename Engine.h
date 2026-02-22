#ifndef ENGINE_H
#define ENGINE_H
#include <memory>
#include <vector>
#include <string>
#include "SceneManager.h"  

class Scene;
class InputHandler;
class Renderer;

class Engine {
    private:
    std::unique_ptr<SceneManager> sceneManager;
    std::shared_ptr<Scene> currentScene;
    std::unique_ptr<InputHandler> inputHandler;
    std::unique_ptr<Renderer> renderer;
    bool is_running;
    float delta_time;

    void calculateDeltaTime();
    
public:
    Engine();
    ~Engine();
    void initialize();
    void run();
    void shutdown();
    void loadScene(const std::string& sceneName);
    void switchScene(const std::string& sceneName);
    std::shared_ptr<Scene> getCurrentScene() const;
    bool getIsRunning() const;
    float getDeltaTime() const;
    void setRunning(bool running);
};

#endif 