 #pragma once
#include <iostream>
#include <cstdlib>

#define DEBUG_ASSERT(condition, message)                           \
    do {                                                           \
        if(!(condition))                                           \
        {                                                          \
            std::cerr << "\n[ASSERTION FAILED]\n";                 \
            std::cerr << "Message: " << message << std::endl;      \
            std::cerr << "File: " << __FILE__ << std::endl;        \
            std::cerr << "Line: " << __LINE__ << std::endl;        \
            std::exit(EXIT_FAILURE);                               \
        }                                                          \
    } while(false)