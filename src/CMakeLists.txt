set(LIB_SRCS
    Core/Engine.cpp
    Core/Logger.cpp
    Core/Window.cpp
)

add_library(Pixa SHARED ${LIB_SRCS})

target_include_directories(Pixa PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_compile_options(Pixa PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

target_compile_definitions(Pixa PRIVATE
    PIXA_EXPORT
)

target_precompile_headers(Pixa PRIVATE ${CMAKE_SOURCE_DIR}/include/Pixa/pch.hpp)

target_link_libraries(Pixa PRIVATE
    SDL3::SDL3
)

target_link_libraries(Pixa PUBLIC
    spdlog::spdlog
)