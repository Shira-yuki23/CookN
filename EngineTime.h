#ifndef ENGINETIME_H
#define ENGINETIME_H

#include <chrono>
#ifdef _WIN32
#include <windows.h>
#else
#include <thread>
#endif

namespace Time 
{
    //precise timing
    using Clock = std::chrono::high_resolution_clock;
    //a specific monment in time
    using Point = Clock::time_point;
    //time interval
    using Duration = std::chrono::duration<double>;
    using Milliseconds = std::chrono::milliseconds;
    //utilities
    inline double to_seconds(const Duration& duration) 
    {
        return duration.count();
    }
    inline Duration from_seconds(double seconds) 
    {
        return Duration(seconds);
    }
    //current time
    inline Point now() 
    {
        return Clock::now();
    }
    inline double elapsed_seconds(const Point& start, const Point& end) 
    {
        return Duration(end - start).count();
    }
    
    inline Milliseconds to_milliseconds(double seconds) 
    {
        return Milliseconds(static_cast<long long>(seconds * 1000));
    }

    inline void sleep_milliseconds(int ms) 
    {
#ifdef _WIN32
        Sleep(ms);
#else
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#endif
    }
}
#endif