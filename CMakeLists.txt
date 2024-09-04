cmake_minimum_required(VERSION 3.27)
project(escaper_text_based_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(escaper_text_based_game src/main.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/GameMenu/GameMenu.h
        src/GameMenu/GameMenu.cpp
        src/GameSettings/GameSettings.h
        src/GameSettings/GameSettings.cpp
        src/Map/Map.cpp
        src/Map/Map.h
        src/BaseCharacter/BaseCharacter.h
        src/BaseCharacter/BaseCharacter.cpp
        src/Player/Player.h
        src/Player/Player.cpp
        src/Enemy/Enemy.cpp
        src/Enemy/Enemy.h
        src/RenderEngine/RenderEngine.h
        src/RenderEngine/RenderEngine.cpp)
