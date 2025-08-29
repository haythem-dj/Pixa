cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Pixa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

include(cmake/Dependencies.cmake)

add_subdirectory(src)

if (PIXA_BUILD_TEST)
    add_subdirectory(test)
endif()