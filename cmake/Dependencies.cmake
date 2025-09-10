set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

# =======================================================================
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

# =======================================================================
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

# =======================================================================
FetchContent_Declare(
    stb_image
    URL https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/stb_image/include/stb_image
    DOWNLOAD_NO_EXTRACT TRUE
)

message(STATUS "[deps] Getting stb_image")
FetchContent_MakeAvailable(stb_image)

add_library(stb_image INTERFACE)
target_include_directories(stb_image INTERFACE ${CMAKE_SOURCE_DIR}/external/stb_image/include)

# =======================================================================
FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad
    GIT_TAG v2.0.8
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glad
    GIT_SHALLOW TRUE
)

message(STATUS "[deps] Getting glad")
FetchContent_MakeAvailable(glad)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/glad/cmake)
glad_add_library(glad SHARED API gl:core=4.5)
set_target_properties(glad PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/_deps/glad-build"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/_deps/glad-build"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIG>/_deps/glad-build"
)

# =======================================================================
set(GLM_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm
    GIT_TAG 1.0.1
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/glm
    GIT_SHALLOW TRUE
)

message(STATUS "[deps] Getting glm")

FetchContent_MakeAvailable(glm)

# =======================================================================
FetchContent_Declare(
    entt
    GIT_REPOSITORY https://github.com/skypjack/entt
    GIT_TAG v3.15.0
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/external/entt
    GIT_SHALLOW TRUE
)

message(STATUS "[deps] Getting entt")

FetchContent_MakeAvailable(entt)
