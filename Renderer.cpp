#include "Renderer.h"
#include "Scene.h"
#include "Entity.h"
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
    try 
    {
        screen_buffer.resize(height, std::string(width, ' '));
        back_buffer.resize(height, std::string(width, ' '));
    }
    catch (const std::exception& e)
    {
        throw RendererException("Failed to allocate screen buffers: " + std::string(e.what()));
    }
    
    hide_cursor();
}

Renderer::~Renderer()
{
    reset_color();
}

void Renderer::render(Scene* scene, float alpha, int fps)
{
    if (!scene) 
    {
        throw RendererException("Cannot render null scene");
    }
    
    clear_buffer();
    draw_border();
    
    const auto& entities = scene->getEntities();  

    for (const auto& entity : entities)
    {
        auto spatial_entity = std::dynamic_pointer_cast<SpatialEntity>(entity);
        if (spatial_entity) 
        {  
            draw_entity(spatial_entity, alpha);
        }
    }
    
    draw_text(2, 0, "Scene: " + scene->getName());
    draw_text(width - 20, 0, "Alpha: " + std::to_string(alpha).substr(0, 4));
    
    if (fps >= 0) 
    {
        draw_text(width - 32, 0, "FPS: " + std::to_string(fps));
    }
    
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
    if (!spatial_entity) 
    {
        return;
    }

    int x = static_cast<int>(spatial_entity->get_prev_x() + 
                             (spatial_entity->get_x() - spatial_entity->get_prev_x()) * alpha);
    int y = static_cast<int>(spatial_entity->get_prev_y() + 
                             (spatial_entity->get_y() - spatial_entity->get_prev_y()) * alpha);
    
    if (x < 1) x = 1; if (x > width - 2) x = width - 2;
    if (y < 1) y = 1; if (y > height - 2) y = height - 2;
    
    char symbol = spatial_entity->get_symbol();
    back_buffer[y][x] = symbol;
}

void Renderer::draw_text(int x, int y, const std::string& text)
{
    if (y < 0 || y >= height) 
    {
        return;
    }
    
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
    set_cursor_position(0, 0);

    std::string frame;
    frame.reserve(height * (width + 1));
    for (int i = 0; i < height; i++)
    {
        frame += screen_buffer[i];
        if (i < height - 1) 
        { 
            frame += '\n';
        }
    }
    std::cout << frame << std::flush;
}

void Renderer::hide_cursor()
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE)
    {
        throw RendererException("Failed to get console handle");
    }
    CONSOLE_CURSOR_INFO cursorInfo;
    if (!GetConsoleCursorInfo(hConsole, &cursorInfo))
    {
        throw RendererException("Failed to get console cursor info");
    }
    cursorInfo.bVisible = FALSE;
    if (!SetConsoleCursorInfo(hConsole, &cursorInfo))
    {
        throw RendererException("Failed to set console cursor info");
    }
#else
    std::cout << "\033[?25l" << std::flush;
#endif
}

void Renderer::set_cursor_position(int x, int y)
{
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE)
    {
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hConsole, coord);
    }
#endif
    if (x == 0 && y == 0) 
    {
        std::cout << "\033[H" << std::flush;
    } 
    else 
    {
        std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H" << std::flush;
    }
}

void Renderer::set_size(int w, int h)
{
    width = w;
    height = h;
    try
    {
        screen_buffer.resize(height, std::string(width, ' '));
        back_buffer.resize(height, std::string(width, ' '));
    }
    catch (const std::exception& e)
    {
        throw RendererException("Failed to resize screen buffers: " + std::string(e.what()));
    }
}

void Renderer::set_color(int foreground, int background)
{
    use_color = true;
    
    #ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE)
    {
        SetConsoleTextAttribute(hConsole, foreground | (background << 4));
    }
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
    if (hConsole != INVALID_HANDLE_VALUE)
    {
        SetConsoleTextAttribute(hConsole, 7);  
    }
    #else
    std::cout << "\033[0m"; 
    #endif
}