#Aetna
OOP project  by 223, 239,249, 221

Overview

Aetna is a simple console-based game engine designed to demonstrate how core game engines work without using graphics or external libraries. The project focuses on object-oriented programming (OOP) concepts and modular design, making it suitable for beginners.


Team Members

Zarin Tasnim Mishi (249)

Arshiya Saryn Hera (239)

Fariha Musfirat Shifa (223)

Nafisa Anjum Neha (221)


# Aetna Engine - Foundation Setup

## Files Created by Zarin (249):
1. `Engine.h/cpp` - Core engine class and game loop
2. `main.cpp` - Entry point
3. `Scene.h` - Base Scene class (interface)
4. `Entity.h` - Base Entity class (abstract)
5. `CMakeLists.txt` - Build configuration

## Next Steps for Team:

### Arshiya (239) - Entity Management & Event Handling:
1. Implement `Entity.cpp` with basic functionality
2. Create derived entity classes (Player, NPC, etc.)
3. Implement event system

### Fariha (223) - Input/Output & Physics:
1. Create `InputHandler.h/cpp` 
2. Create `Renderer.h/cpp`
3. Create `PhysicsManager.h/cpp`

### Nafisa (221) - Scene Management & Testing:
1. Implement `Scene.cpp`
2. Create scene management system
3. Create test entities and scenes

## Building Instructions:
```bash
mkdir build
cd build
cmake ..
make
./AetnaEngine
 dcb1ab6 (Initial commit-basic framework)
