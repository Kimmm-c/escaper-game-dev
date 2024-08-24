#ifndef GAME_H
#define GAME_H

#include "../GameMenu/GameMenu.h"
#include "../GameSettings/GameSettings.h"

class Game {
    const GameMenu* mainMenu;
    const GameMenu* difficultyMenu;
    const GameMenu* mapMenu;
    GameSettings* gameSettings;
//    GameOptionMenu optionMenu;
//    Player player;
//    Enemy* enemies;
//    Map map;
//    CollisionSystem* collisionSystem;
//    PhysicSystem* physicSystem;
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

private:

};

#endif