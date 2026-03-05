#pragma once

#include "Pixa/Common/Defines.hpp"

#ifdef PIXA_ENABLE_ASSERTS
    #define PIXA_ASSERT(x, ...)                                             \
        do                                                                  \
        {                                                                   \
            if (!(x))                                                       \
            {                                                               \
                PIXA_FATAL("Assertion failed: {}, {}", __FILE__, __LINE__); \
                PIXA_FATAL(__VA_ARGS__);                                    \
            }                                                               \
        } while (false)
#else
    #define PIXA_ASSERT
#endif