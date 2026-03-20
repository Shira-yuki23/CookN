#ifndef Engine_H
#define Engine_H
#include <vector>
#include <string>
#include<thread>
#include <chrono>
#include <memory>
#include<algorithm>
class Scene;
class InputHandler;
class Renderer;
class PhysicsManager;
class Entity;
class Engine
{
private:
    std::vector<std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> current_scene;
    std::unique_ptr<InputHandler> input_handler;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<PhysicsManager> physics_manager;
    bool is_running;
    bool is_paused;
    float delta_time;
    int frame_count;
    int target_fps;
    int current_fps;
    std::chrono::high_resolution_clock::time_point last_frame_time;
    void calculate_delta_time();
public:
    Engine();
    ~Engine();
    void initialize();
    void run();
    void shutdown();
    void pause();
    void resume();
    void add_scene(std::shared_ptr<Scene> scene);
    void load_scene(const std::string& Scene_name);
    bool switch_scene(const std::string& Scene_name);
    std::shared_ptr<Scene> get_current_scene() const;
    void add_entity(std::shared_ptr<Entity> Entity);
    void remove_entity(const std::string& Entity_id);
    bool get_is_running() const;
    bool get_is_paused() const;
    float get_delta_time() const;
    int get_frame_count() const;
    void set_running(bool running);
    void set_paused(bool paused);
    void set_target_fps(int fps);
};

#endif