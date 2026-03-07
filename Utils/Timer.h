 #pragma once
#include <algorithm> // for std::max

class Timer
{
protected:
    float time;  // current time
public:
    Timer() : time(0.0f) {}
    virtual ~Timer() = default;

    virtual void update(const float deltaTime)  // polymorphic
    {
        time += deltaTime;
    }

    virtual bool hasElapsed(const float duration) const
    {
        return time >= duration;
    }

    virtual void reset()
    {
        time = 0.0f;
    }

    float getTime() const { return time; } // const correctness

    float restart() // reset and return previous time
    {
        float t = time;
        reset();
        return t;
    }
};

// Countdown timer (inherits Timer)
class CountdownTimer : public Timer
{
private:
    float countdown;
public:
    CountdownTimer(float duration) : Timer(), countdown(duration) {}

    void update(const float deltaTime) override
    {
        if (time < countdown)
            time += deltaTime;
    }

    bool hasElapsed(const float duration = 0.0f) const override
    {
        return time >= countdown;
    }

    void reset() override
    {
        time = 0.0f;
    }

    float getRemaining() const
    {
        return std::max(0.0f, countdown - time);
    }
};