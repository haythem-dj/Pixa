set(SPDLOG_BUILD_SHARED ON CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_STATIC OFF CACHE BOOL "" FORCE)
set(SPDLOG_HEADER_ONLY OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/spdlog
    GIT_SHALLOW TRUE
)

message(STATUS "[deps] Getting spdlog")
FetchContent_MakeAvailable(spdlog)

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-3.2.20
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/SDL3
    GIT_SHALLOW TRUE
)

message(STATUS "[deps] Getting SDL3")
FetchContent_MakeAvailable(SDL3)