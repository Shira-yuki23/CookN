#include "Renderer.h"
#include "Scene.h"
#include <iostream>
#include <algorithm>
#include <memory>

#ifdef _WIN32
#include <windows.h>
#endif

Renderer::Renderer(int console_width, int console_height) 
    : width(console_width)
    , height(console_height)
    , use_color(false)
{
    screen_buffer.resize(height, std::string(width, ' '));
    back_buffer.resize(height, std::string(width, ' '));
    
    std::cout << "[RENDERER] Initialized (" << width << "x" << height << ")" << std::endl;
}

Renderer::~Renderer()
{
    reset_color();
    std::cout << "[RENDERER] Shutdown" << std::endl;
}

void Renderer::render(Scene* scene, float alpha)
{
    if (!scene) return;
    
    clear_buffer();
    draw_border();
    
    const auto& entities = scene->get_entities();  

    for (const auto& entity : entities)
    {
        auto spatial_entity = std::dynamic_pointer_cast<SpatialEntity>(entity);
        if (spatial_entity) 
        {  
            draw_entity(spatial_entity, alpha);
        }
    }
    
    draw_text(2, 0, "Scene: " + scene->get_name());
    draw_text(width - 20, 0, "Alpha: " + std::to_string(alpha).substr(0, 4));
    
    swap_buffers();
    display();
}

void Renderer::clear_buffer()
{
    for (auto& line : back_buffer)
    {
        std::fill(line.begin(), line.end(), ' ');
    }
}

void Renderer::swap_buffers()
{
    screen_buffer.swap(back_buffer);
}

void Renderer::draw_border()
{

    for (int x = 0; x < width; x++)
    {
        back_buffer[0][x] = '-';
    }

    for (int x = 0; x < width; x++)
    {
        back_buffer[height - 1][x] = '-';
    }

    for (int y = 0; y < height; y++)
    {
        back_buffer[y][0] = '|';
    }

    for (int y = 0; y < height; y++)
    {
        back_buffer[y][width - 1] = '|';
    }

    back_buffer[0][0] = '+';
    back_buffer[0][width - 1] = '+';
    back_buffer[height - 1][0] = '+';
    back_buffer[height - 1][width - 1] = '+';
}

void Renderer::draw_entity(const std::shared_ptr<SpatialEntity>& spatial_entity, float alpha)
{
    if (!spatial_entity) return;

    int x = static_cast<int>(spatial_entity->get_prev_x() + 
                             (spatial_entity->get_x() - spatial_entity->get_prev_x()) * alpha);
    int y = static_cast<int>(spatial_entity->get_prev_y() + 
                             (spatial_entity->get_y() - spatial_entity->get_prev_y()) * alpha);
    
    x = std::clamp(x, 1, width - 2);
    y = std::clamp(y, 1, height - 2);
    
    char symbol = spatial_entity->get_symbol();
    back_buffer[y][x] = symbol;
    
    if (x < width - 10)
    {
        std::string info = spatial_entity->get_name().substr(0, 5);
        for (size_t i = 0; i < info.length() && x + i + 1 < width - 1; i++)
        {
            back_buffer[y][x + i + 1] = info[i];
        }
    }
}

void Renderer::draw_text(int x, int y, const std::string& text)
{
    if (y < 0 || y >= height) return;
    
    for (size_t i = 0; i < text.length(); i++)
    {
        int draw_x = x + static_cast<int>(i);
        if (draw_x >= 0 && draw_x < width)
        {
            back_buffer[y][draw_x] = text[i];
        }
    }
}

void Renderer::set_pixel(int x, int y, char c)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        back_buffer[y][x] = c;
    }
}

void Renderer::clear()
{
    for (auto& line : screen_buffer)
    {
        std::fill(line.begin(), line.end(), ' ');
    }
    for (auto& line : back_buffer)
    {
        std::fill(line.begin(), line.end(), ' ');
    }
}

void Renderer::display()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    for (const auto& line : screen_buffer)
    {
        std::cout << line << std::endl;
    }
}

void Renderer::set_size(int w, int h)
{
    width = w;
    height = h;
    screen_buffer.resize(height, std::string(width, ' '));
    back_buffer.resize(height, std::string(width, ' '));
}

void Renderer::set_color(int foreground, int background)
{
    use_color = true;
    
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, foreground | (background << 4));
    #else
    std::cout << "\033[" << foreground << "m";
    if (background > 0)
    {
        std::cout << "\033[" << (background + 10) << "m";
    }
    #endif
}

void Renderer::reset_color()
{
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);  
    #else
    std::cout << "\033[0m"; 
    #endif
}