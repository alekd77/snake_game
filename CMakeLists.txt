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

# ASSETS
set(ASSETS src/assets/assets_managers)
include_directories(${ASSETS})

#LOGIC
set(BOARD_LOGIC src/game_logic/board)
include_directories(${BOARD_LOGIC})
set(SNAKE_LOGIC src/game_logic/snake)
include_directories(${SNAKE_LOGIC})

#STATES
set(STATES src/states)
include_directories(${STATES})

#STATES_VIEWS
set(STATES_VIEWS src/states/views)
include_directories(${STATES_VIEWS})
#VIEWS_TILES
set(VIEWS_TILES src/states/views/tiles)
include_directories(${VIEWS_TILES})

set(
        SOURCE_FILES
        main.cpp
        src/game_manager.cpp
        src/game_manager.h

        ${ASSETS}/assets_manager.cpp
        ${ASSETS}/assets_manager.h
        ${ASSETS}/textures_manager.cpp
        ${ASSETS}/textures_manager.h
        ${ASSETS}/sprites_manager.cpp
        ${ASSETS}/sprites_manager.h
        ${ASSETS}/sounds_manager.cpp
        ${ASSETS}/sounds_manager.h
        ${ASSETS}/fonts_manager.cpp
        ${ASSETS}/fonts_manager.h

        ${BOARD_LOGIC}/board.cpp
        ${BOARD_LOGIC}/board.h
        ${BOARD_LOGIC}/obstacles.cpp
        ${BOARD_LOGIC}/obstacles.h
        ${BOARD_LOGIC}/food.cpp
        ${BOARD_LOGIC}/food.h
        ${SNAKE_LOGIC}/snake.cpp
        ${SNAKE_LOGIC}/snake.h

        ${STATES}/state_menu.cpp
        ${STATES}/state_menu.h
        ${STATES}/state_play.cpp
        ${STATES}/state_play.h
        ${STATES_VIEWS}/state_view_interface.h
        ${STATES_VIEWS}/state_play_view.cpp
        ${STATES_VIEWS}/state_play_view.h
        ${VIEWS_TILES}/tile.cpp
        ${VIEWS_TILES}/tile.h
)

add_executable(Snake_New ${SOURCE_FILES})

target_link_libraries (Snake_New sfml-graphics sfml-audio libstdc++fs.a)