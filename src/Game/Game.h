#ifndef GAME_H
#define GAME_H

#include "../GameMenu/GameMenu.h"
#include "../GameSettings/GameSettings.h"
#include "../Map/Map.h"
#include "../PhysicEngine/PhysicEngine.h"

class Game {
    const GameMenu* mainMenu;
    const GameMenu* difficultyMenu;
    const GameMenu* mapMenu;
    GameSettings* gameSettings;
    Map* map;
    Player* player;
    PhysicEngine* physicEngine;
    uint8_t countdownClock;

//    GameOptionMenu optionMenu;
//    Enemy* enemies;
//    Map map;
//    CollisionSystem* collisionSystem;
//    RenderSystem* renderSystem;


public:
    Game();
    ~Game();
    int getUserSelection(const GameMenu* menu);
    void displayGameGuide();
    void setDifficultyLevel();
    void config();
    void handleInput();
    void update();
    void render();
    void run();
    void start();

private:
    void setCountdownClock(uint8_t sec);
    uint8_t getCountdownClock() const;
    pair<uint8_t, uint8_t> getDestination() const;
};

#endif