#ifndef ENGINE_H
#define ENGINE_H
#include <memory>
#include <vector>
#include <string>
//declare the classes here,forward declaration
class Scene;
class InputHandler;
class Renderer;
class Engine 
{
private:
    std::shared_ptr<Scene> current_scene;
    std::unique_ptr<InputHandler> input_handler;
    std::unique_ptr<Renderer> renderer;
    bool is_running;
    float delta_time;
    void calculate_delta_time();
public:
    Engine();
    ~Engine();
    void initialize();
    void run();
    void shutdown();
    void load_scene(const std::string& scene_name);
    void switch_scene(const std::string& scene_name);
    std::shared_ptr<Scene> get_current_scene() const;
    bool get_is_running() const;
    float get_delta_time() const;
    void set_running(bool running);
};
#endif 