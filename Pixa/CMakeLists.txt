file(GLOB_RECURSE PIXA_SRCS src/*.cpp)

add_library(Pixa STATIC ${PIXA_SRCS})
target_include_directories(Pixa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Pixa
    PRIVATE
        SDL3::SDL3
        glm
        spdlog
        fmt
    PUBLIC
        glad
        stb_image
)
