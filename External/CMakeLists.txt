add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

add_library(stb_image STATIC stb_image/src/stb_image.cpp)
target_include_directories(stb_image PUBLIC stb_image/include)
