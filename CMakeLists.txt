cmake_minimum_required(VERSION 3.19)
project(Snake_New)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)

if (UNIX)
    set (CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

endif(UNIX)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set (SFML_DIR "D:/Studia/Programowanie/SFML/SFML-2.5.1/lib/cmake/SFML")

endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

# ASSETS
set(ASSETS src/assets/assets_managers)
include_directories(${ASSETS})


#STATES
set(STATES src/states)
include_directories(${STATES})


#STATE_INTERFACE
set(STATE_INTERFACE ${STATES}/state_interface)
include_directories(${STATE_INTERFACE})

#STATE_INPUT_INTERFACE
set(STATE_INPUT_INTERFACE ${STATE_INTERFACE}/input)
include_directories(${STATE_INPUT_INTERFACE})

#STATE_VIEW_INTERFACE
set(STATE_VIEW_INTERFACE ${STATE_INTERFACE}/views)
include_directories(${STATE_VIEW_INTERFACE})


#STATE_MENU
set(STATE_MENU ${STATES}/state_menu)
include_directories(${STATE_MENU})


#STATE_PLAY
set(STATE_PLAY ${STATES}/state_play)
include_directories(${STATE_PLAY})

#STATE_PLAY_GAME_LOGIC
set(STATE_PLAY_GAME_LOGIC ${STATE_PLAY}/game_logic)
include_directories(${STATE_PLAY_GAME_LOGIC})


set(SOURCE_FILES

        main.cpp
        src/game_manager.cpp
        src/game_manager.h

        ${ASSETS}/assets_manager.cpp
        ${ASSETS}/assets_manager.h
        ${ASSETS}/textures_manager.cpp
        ${ASSETS}/textures_manager.h
        ${ASSETS}/sounds_manager.cpp
        ${ASSETS}/sounds_manager.h
        ${ASSETS}/fonts_manager.cpp
        ${ASSETS}/fonts_manager.h

        ${STATE_INTERFACE}/state_interface.h
        ${STATE_INPUT_INTERFACE}/input_handling_interface.cpp
        ${STATE_INPUT_INTERFACE}/input_handling_interface.h
        ${STATE_VIEW_INTERFACE}/state_view_interface.h
        ${STATE_VIEW_INTERFACE}/tiles/tile.cpp
        ${STATE_VIEW_INTERFACE}/tiles/tile.h

        ${STATE_MENU}/state_menu.cpp
        ${STATE_MENU}/state_menu.h

        ${STATE_PLAY}/state_play.cpp
        ${STATE_PLAY}/state_play.h
        ${STATE_PLAY}/state_play_input_handling.cpp
        ${STATE_PLAY}/state_play_input_handling.h
        ${STATE_PLAY}/state_play_view.cpp
        ${STATE_PLAY}/state_play_view.h
        ${STATE_PLAY_GAME_LOGIC}/board/board.cpp
        ${STATE_PLAY_GAME_LOGIC}/board/board.h
        ${STATE_PLAY_GAME_LOGIC}/board/food.cpp
        ${STATE_PLAY_GAME_LOGIC}/board/food.h
        ${STATE_PLAY_GAME_LOGIC}/board/obstacles.cpp
        ${STATE_PLAY_GAME_LOGIC}/board/obstacles.h
        ${STATE_PLAY_GAME_LOGIC}/snake/snake.cpp
        ${STATE_PLAY_GAME_LOGIC}/snake/snake.h
)

add_executable(Snake_New ${SOURCE_FILES})

target_link_libraries (Snake_New sfml-graphics sfml-audio libstdc++fs.a)