add_executable(
    Sandbox
    Main.cpp
    StartScreen.cpp
)

target_compile_definitions(Sandbox PUBLIC SFML_STATIC TGUI_STATIC)
target_include_directories(
    Sandbox PUBLIC 
    ${CMAKE_SOURCE_DIR}/SFML-TGUI/include
    ${CMAKE_SOURCE_DIR}
)
target_link_directories(Sandbox PUBLIC ${CMAKE_SOURCE_DIR}/SFML-TGUI/lib)
target_link_libraries(
    Sandbox PUBLIC
    SF-Core 
)

target_link_libraries(
    Sandbox PUBLIC
    tgui-s
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
    freetype
    ogg
    opengl32
    gdi32
    winmm
)
