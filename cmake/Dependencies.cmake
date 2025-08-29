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

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
    message(STATUS "[deps] Downloading spdlog...")
    FetchContent_MakeAvailable(spdlog)
    message(STATUS "[deps] Finished setting up spdlog")
else()
    message(STATUS "[deps] Using cached spdlog at ${spdlog_SOURCE_DIR}")
endif()