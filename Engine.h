#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <memory>
#include "EngineTime.h"
#include "EngineExceptions.h"

class Scene;
class InputHandler;
class Renderer;
class PhysicsManager;
class Entity;

class Engine 
{
private:
    using ScenePtr = std::shared_ptr<Scene>;
    using SceneList = std::vector<ScenePtr>;
    using EntityPtr = std::shared_ptr<Entity>;
    using InputHandlerPtr = std::unique_ptr<InputHandler>;
    using RendererPtr = std::unique_ptr<Renderer>;
    using PhysicsManagerPtr = std::unique_ptr<PhysicsManager>;
    using TimePoint = Time::Point;
    using Duration = Time::Duration;

    SceneList scenes;
    ScenePtr current_scene;
    InputHandlerPtr input_handler;
    RendererPtr renderer;
    PhysicsManagerPtr physics_manager;
    
    bool is_running;
    bool is_paused;
    float delta_time;
    int frame_count;
    int target_fps;
    int current_fps;
    
    TimePoint last_frame_time;
    
    void calculate_delta_time();
    
public:
    Engine();
    ~Engine();
    
    void initialize();
    void run();
    void shutdown();
    void pause();
    void resume();

    void add_scene(ScenePtr scene);
    void load_scene(const std::string& scene_name);
    bool switch_scene(const std::string& scene_name);
    ScenePtr get_current_scene() const;

    void add_entity(EntityPtr entity);
    void remove_entity(const std::string& entity_id);
    
    bool get_is_running() const;
    bool get_is_paused() const;
    float get_delta_time() const;
    int get_frame_count() const;
    
    void set_running(bool running);
    void set_paused(bool paused);
    void set_target_fps(int fps);
};

#endif