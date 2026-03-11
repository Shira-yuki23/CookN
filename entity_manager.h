#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>
#include <string>
#include "Entity.h"
#include "Event.h"

class EntityManager {
private:
    std::vector<Entity*> entities;

public:
    EntityManager() = default;
    ~EntityManager();

    void addEntity(Entity* entity);
    void removeEntity(const std::string& id);

    Entity* getEntityById(const std::string& id);

    void updateAll(float deltaTime);
    void renderAll();

    void broadcastEvent(Event& event);

    const std::vector<Entity*>& getEntities() const;
};

#endif