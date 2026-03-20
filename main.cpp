#include "Engine.h"
#include "Player.h"
#include "NPC.h"
#include <memory>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    std::cout << "=== CookN Engine Demo ===" << std::endl;
    std::cout << "IMPORTANT: Please resize your console window to at least 80x25 characters." << std::endl;
    std::cout << "Use the ARROW KEYS to move the Player." << std::endl;
    std::cout << "Press ESC to Quit." << std::endl;
    std::cout << "Starting in 2 seconds..." << std::endl;
    
    Sleep(2000); // Give user time to see instructions and resize

    Engine engine;
    engine.initialize();

    // Add game entities to the current scene
    auto player = std::make_shared<Player>(10.0f, 10.0f);
    auto guard = std::make_shared<NPC>("Guard", 20.0f, 10.0f);
    auto villager = std::make_shared<NPC>("Villager", 15.0f, 25.0f);
    auto shopkeeper = std::make_shared<NPC>("Shopkeeper", 30.0f, 30.0f);

    engine.add_entity(player);
    engine.add_entity(guard);
    engine.add_entity(villager);
    engine.add_entity(shopkeeper);

    // Run the game loop
    engine.run();
    engine.shutdown();

    std::cout << "=== Demo Complete ===" << std::endl;
    return 0;
}