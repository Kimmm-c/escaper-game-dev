#ifndef GAME_H
#define GAME_H

#include "../GameMenu/GameMenu.h"
#include "../GameSettings/GameSettings.h"
#include "../Map/Map.h"

class Game {
    const GameMenu* mainMenu;
    const GameMenu* difficultyMenu;
    const GameMenu* mapMenu;
    GameSettings* gameSettings;
    Map* map;
//    GameOptionMenu optionMenu;
//    Player player;
//    Enemy* enemies;
//    Map map;
//    CollisionSystem* collisionSystem;
//    PhysicSystem* physicSystem;
//    RenderSystem* renderSystem;
    uint8_t countdownClock;

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
};

#endif