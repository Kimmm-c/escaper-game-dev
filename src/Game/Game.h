#ifndef GAME_H
#define GAME_H

#include <cereal/archives/binary.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/set.hpp>

#include "../GameMenu/GameMenu.h"
#include "../GameSettings/GameSettings.h"
#include "../Map/Map.h"
#include "../PhysicEngine/PhysicEngine.h"

class Game {
    const GameMenu *mainMenu;
    const GameMenu *difficultyMenu;
    const GameMenu *mapMenu;
    const GameMenu *midGameMenu;
    GameSettings *gameSettings;
    Map *map;
    Player *player;
    PhysicEngine *physicEngine;
    uint8_t countdownClock;
    int gameState;

public:
    Game();

    ~Game();

    void gameInit();

    int getUserSelection(const GameMenu *menu);

    void displayGameGuide();

    void config();

    void run();

    void start();

private:
    void setCountdownClock(uint8_t sec);

    uint8_t getCountdownClock() const;

    pair<uint8_t, uint8_t> getDestination() const;
};

#endif