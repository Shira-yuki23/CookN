#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

class Entity {
private:
    string id;
    string name;
    bool isActive;

    static string generateUniqueId();

public:
    Entity(const string& entityName);
    virtual ~Entity() {}   

    string getId() const;
    string getName() const;
    bool getIsActive() const;

    void setIsActive(bool active);

    // Add these for polymorphism
    virtual void update() = 0;
    virtual void draw() = 0;
};

#endif
