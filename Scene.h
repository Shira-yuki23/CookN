#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "entity_manager.h"

class Scene {
private:
    std::string name;
    EntityManager entityManager;  // Handles all entities in this scene

public:
    Scene() = default;
    Scene(const std::string& sceneName);

    void setName(const std::string& sceneName);
    std::string getName() const;

    // Access the EntityManager to add/remove entities
    EntityManager& getEntityManager();

    // Scene lifecycle
    void load();   // Load initial entities
    void reset();  // Reset entities to initial state

    void update(float deltaTime);  // Update all entities
    void render();                 // Render all entities
};

#endif