set(LIB_SRCS
    Core/Engine.cpp
    Core/Logger.cpp
    Core/Window.cpp
    Core/Timer.cpp
    Core/ScopedTimer.cpp
    Input/Input.cpp
    Graphics/Renderer.cpp
    Graphics/Shader.cpp
    Graphics/VAO.cpp
    Graphics/VBO.cpp
    Graphics/IBO.cpp
    Graphics/Texture.cpp
    Scene/Camera.cpp
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
    stb_image
    glad
)

target_link_libraries(Pixa PUBLIC
    spdlog::spdlog
    glm::glm
)