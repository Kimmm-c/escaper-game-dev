cmake_minimum_required(VERSION 3.27)
project(escaper_text_based_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(escaper_text_based_game src/main.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/GameMenu/GameMenu.h
        src/GameMenu/GameMenu.cpp)
