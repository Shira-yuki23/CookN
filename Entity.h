#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class IRenderer;   // forward declaration

class Entity {
private:
    std::string id;
    std::string name;
    bool isActive;

    static std::string generateUniqueId();

public:
    Entity(const std::string& entityName);
    virtual ~Entity() {}

    std::string getId() const;
    std::string getName() const;
    bool getIsActive() const;

    void setIsActive(bool active);

    virtual void update() = 0;
    virtual void draw(IRenderer& renderer) = 0;
};

#endif
