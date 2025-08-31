#pragma once

#include <stdint.h>
#include <string>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t size;

typedef bool b8;

typedef float f32;
typedef double f64;

typedef std::string str;

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