cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Pixa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SRCS
    src/Pixa.cpp
)

add_library(Pixa SHARED ${LIB_SRCS})

target_include_directories(Pixa PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_options(Pixa PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

target_compile_definitions(Pixa PRIVATE
    PIXA_EXPORT
)

if (PIXA_BUILD_TEST)
    add_subdirectory(test)
endif()