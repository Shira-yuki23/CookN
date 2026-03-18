#ifndef RENDERER_H
#define RENDERER_H

#include "SpatialEntity.h" 
#include <memory>
#include <string>
#include <vector>

class Scene;  

class Renderer 
{
private:
    int width;
    int height;
    std::vector<std::string> screen_buffer;
    std::vector<std::string> back_buffer;
    bool use_color;
    
    void clear_buffer();
    void swap_buffers();
    void draw_border();
    void draw_entity(const std::shared_ptr<SpatialEntity>& entity, float alpha); 
    void draw_text(int x, int y, const std::string& text);
    void set_pixel(int x, int y, char c);
    
public:
    Renderer(int console_width = 80, int console_height = 25);
    ~Renderer();

    void render(Scene* scene, float alpha);
    void clear();
    void display();
    void set_size(int w, int h);
    void set_color(int foreground, int background = 0);
    void reset_color();
    
    int get_width() const { return width; }
    int get_height() const { return height; }
};

#endif