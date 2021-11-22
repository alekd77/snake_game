cmake_minimum_required(VERSION 3.19)
project(Snake_New)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

endif(UNIX)

if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "D:/Studia/Programowanie/SFML/SFML-2.5.1/lib/cmake/SFML")

endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(Snake_New main.cpp src/game_manager.cpp src/game_state.h)

target_link_libraries (Snake_New sfml-graphics sfml-audio)