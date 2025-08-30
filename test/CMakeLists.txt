project(TestPixa LANGUAGES CXX)

add_executable(TestPixa
    Main.cpp
)
target_link_libraries(TestPixa PRIVATE Pixa)

target_compile_options(TestPixa PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall;-Wextra>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)

add_custom_command(TARGET TestPixa POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Copying Pixa shared library to executable folder" 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:Pixa>"
        "$<TARGET_FILE_DIR:TestPixa>"
    COMMAND ${CMAKE_COMMAND} -E echo "Copying spdlog shared library to executable folder" 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:spdlog>"
        "$<TARGET_FILE_DIR:TestPixa>"
    COMMAND ${CMAKE_COMMAND} -E echo "Copying SDL3 shared library to executable folder" 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:SDL3::SDL3>"
        "$<TARGET_FILE_DIR:TestPixa>"

    COMMAND ${CMAKE_COMMAND} -E echo "Copying glad shared library to executable folder" 
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:glad>"
        "$<TARGET_FILE_DIR:TestPixa>"
)
