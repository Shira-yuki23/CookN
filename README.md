# Aetna Game Engine

## Overview

A modular 2D game engine framework built in C++ featuring a custom game loop, event-driven architecture, threaded event dispatching, entity management, spatial system, and console-based rendering with interpolation.

The engine is designed to simulate real-time game engine architecture using modular systems and scalable design patterns.

---

## Features

### Core Engine
- Fixed timestep game loop
- FPS control and monitoring
- Pause and resume functionality
- Alpha-based interpolation for smooth movement

---

### Scene System
- Multiple scene support
- Scene switching and management
- Scene-based entity grouping

---

### Entity System
- Base `Entity` class with unique ID
- Polymorphic interface:
  - `update(float dt)`
  - `draw(float alpha)`
  - `on_event(const Event&)`
- Designed for extensibility (Player, NPC, etc.)

---

### Spatial System
- Position and velocity tracking
- Width and height (AABB bounding box)
- Static and dynamic entity support
- Previous position tracking for interpolation
- Collision helper boundaries:
  - left, right, top, bottom

---

### Entity Management
- Dynamic entity lifecycle management
- Update and render pipeline
- Event broadcasting to all active entities
- Efficient entity lookup by ID

---

## Event System (Advanced)

### Event Types Supported
- Input events
- Collision events
- Combat events
- Scene events
- Entity lifecycle events (SPAWN / DESTROY)

### Event Features
- Strongly typed event hierarchy
- Runtime polymorphism using base `Event`
- Safe event cloning system using `unique_ptr`
- Debug support using `operator<<` overloads

---

## Event Dispatcher (Thread-Safe)

- Mutex-protected event queue
- Subscriber-based callback system
- Targeted and broadcast event support
- Uses `std::unique_ptr<Event>` for safe memory management

### Event Flow
Input → Event → Queue → Dispatcher → Subscribers → Entities


---

## Event Statistics System

- Tracks event frequency per type
- Measures average processing time
- Debugging and performance analysis tools

---

## Input System
- Windows API keyboard input
- Converts input into event objects
- Supports key press and release events

---

## Physics System
- Gravity simulation
- Velocity-based movement
- Axis-Aligned Bounding Box (AABB) collision detection
- Basic collision response system

---

## Rendering System (Console-Based)

### Renderer Features
- ASCII-based rendering engine
- Double buffering:
  - screen buffer
  - back buffer
- Cross-platform cursor control (Windows + ANSI)
- HUD overlay (Scene name, FPS, Alpha)

### Rendering Pipeline
Clear buffer
→ Draw border
→ Render entities (interpolated)
→ Draw UI text
→ Swap buffers
→ Display frame
---

### Interpolation


x = prev_x + (current_x - prev_x) * alpha
y = prev_y + (current_y - prev_y) * alpha


---
## Project Structure


      /Engine
      ├── Engine.cpp / .h
      ├── Scene.cpp / .h
      ├── Entity.cpp / .h
      ├── SpatialEntity.cpp / .h
      ├── Player.cpp / .h
      ├── NPC.cpp / .h
      ├── PhysicsManager.cpp / .h
      ├── InputHandler.cpp / .h
      ├── Event.cpp / .h
      ├── EventDispatcher.cpp / .h
      ├── EntityManager.cpp / .h
      ├── Renderer.cpp / .h
      ├── EventStats

## Architecture Overview

### Game Loop


      while (running):
         process_input()
         update_physics()
         update_scene()
         render()


---


## Example Usage
      Engine engine;
      
      engine.initialize();
      engine.run();
      Example Entity
      class Player : public SpatialEntity {
      public:
          void update(float dt) override;
          void draw(float alpha) override;
          void on_event(const Event& event) override;
      };
---


## Controls

| Key        | Action      |
| ---------- | ----------- |
| Arrow Keys | Move Player |
| Space      | Attack      |


## Dependencies

*   C++17 or later
*   Windows API (windows.h)
*   Optional Raylib (future rendering backend)

## Limitations

*   Windows-only input handling
*   Basic collision response
*   No ECS architecture yet
*   Mixed memory management (raw + smart pointers)
*   Console-based rendering only
  
## Future Improvements

*   Entity Component System (ECS)
*   Cross-platform input (SDL2)
*   Advanced rendering (OpenGL / SFML)
*   Camera system
*   Audio system
*   AI system
*   Resource manager
*   Improved physics engine

## Summary

This project demonstrates:

*   Game loop architecture
*   Event-driven system design
*   Thread-safe event dispatching
*   Physics simulation basics
*   Console rendering engine
*   Modular C++ architecture
## Authors

Fariha Musfirat Shifa — 230041223

Arshiya Saryn Hera — 230041239

Zarin Tasnim Mishi — 230041249

Nafisa Anjum Neha — 230041221


{Note:This project is an academic game engine prototype demonstrating how real-time engines structure entities, rendering, and event systems in C++.}
