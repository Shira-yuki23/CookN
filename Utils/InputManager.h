 #pragma once


class InputManager
{
public:
    virtual ~InputManager() = default;

    
    virtual bool PausePressed() const = 0;
    virtual bool StartPressed() const = 0;
    virtual bool KeyPressed(int key) const = 0;

    
    static void SetActive(InputManager* manager)
    {
        active = manager;
    }

    static InputManager* GetActive()
    {
        return active;
    }

    static bool Pause()
    {
        return active ? active->PausePressed() : false;
    }

    static bool Start()
    {
        return active ? active->StartPressed() : false;
    }

    static bool Key(int key)
    {
        return active ? active->KeyPressed(key) : false;
    }

private:
    static InputManager* active; // singleton-style active instance
};