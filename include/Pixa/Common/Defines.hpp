#pragma once

#include <stdint.h>
#include <string>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using size = size_t;

using b8 = bool;

using f32 = float;
using f64 = double;

using str = std::string;

#if defined(_WIN32) || defined(_WIN64)
    #define PIXA_PLATFORM_WINDOWS
#else
    #error "Unknown or unsupported operating system" 
#endif

#ifdef PIXA_PLATFORM_WINDOWS
    #ifdef PIXA_EXPORT
        #define PIXA_API __declspec(dllexport)
    #else
        #define PIXA_API __declspec(dllimport)
    #endif
#endif

#if !defined(NDEBUG) || defined(_DEBUG)
    #define PIXA_CONFIG_DEBUG
#else
    #define PIXA_CONFIG_RELEASE
#endif

#ifdef PIXA_CONFIG_DEBUG
    #define PIXA_ENABLE_ASSERTS 1
#else
    #define PIXA_ENABLE_ASSERTS 0
#endif