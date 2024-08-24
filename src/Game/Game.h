#include "../GameMenu/GameMenu.h"

class Game {
    GameMenu* mainMenu;
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