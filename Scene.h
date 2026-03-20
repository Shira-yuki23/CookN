#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Entity;

class Scene 
{
private:
    std::string name;
    std::vector<std::shared_ptr<Entity>> entities;
public:
    Scene() = default;
    Scene(const std::string& sceneName);
    void setName(const std::string& sceneName);
    std::string getName() const;
    void addEntity(std::shared_ptr<Entity> entity);
    void removeEntity(std::shared_ptr<Entity> entity);
    void removeEntity(const std::string& entityId);
    std::vector<std::shared_ptr<Entity>> getEntities() const;
    virtual void update(float deltaTime);
    virtual void render();
};

#endif