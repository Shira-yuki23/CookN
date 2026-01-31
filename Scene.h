#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <memory>
#include <vector>

class Entity;

class Scene {
private:
    std::string name;
    std::vector<std::shared_ptr<Entity>> entities;
    
public:
    Scene(const std::string& sceneName);
    virtual ~Scene() = default;

    virtual void update(float deltaTime);
    virtual void addEntity(std::shared_ptr<Entity> entity);
    virtual void removeEntity(std::shared_ptr<Entity> entity);

    std::string getName() const;
    std::vector<std::shared_ptr<Entity>> getEntities() const;
};

#endif 