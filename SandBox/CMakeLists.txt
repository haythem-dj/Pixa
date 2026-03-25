file(GLOB_RECURSE SANDBOX_SRCS src/*.cpp)

add_executable(SandBox ${SANDBOX_SRCS})
target_link_libraries(SandBox PRIVATE Pixa)
