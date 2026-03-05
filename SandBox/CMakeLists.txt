add_executable(SandBox Main.cpp)
find_package(fmt REQUIRED)
target_link_libraries(SandBox PRIVATE Pixa fmt::fmt)
