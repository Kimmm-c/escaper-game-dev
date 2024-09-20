cmake_minimum_required(VERSION 3.27)
project(escaper_text_based_game)

set(CMAKE_CXX_STANDARD 17)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(escaper_text_based_game src/main.cpp
        src/Game/Game.h
        src/Game/Game.cpp
        src/GameMenu/GameMenu.h
        src/GameMenu/GameMenu.cpp
        src/GameSettings/GameSettings.h
        src/GameSettings/GameSettings.cpp
        src/Map/Map.h
        src/Map/Map.cpp
        src/BaseCharacter/BaseCharacter.h
        src/BaseCharacter/BaseCharacter.cpp
        src/Player/Player.h
        src/Player/Player.cpp
        src/PhysicEngine/PhysicEngine.h
        src/PhysicEngine/PhysicEngine.cpp
        src/Utils/Utils.h
        src/Utils/Utils.cpp
        src/Enums/Enums.h
)