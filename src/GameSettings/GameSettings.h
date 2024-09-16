#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "../Enums/Enums.h"
using namespace Enums;

class GameSettings {
    int difficulty = Level::EASY;
    int mapGrid = Level::EASY;

public:
    int getDifficulty() const;
    int getMapGrid() const;
    void setDifficulty(int difficulty);
    void setMapGrid(int mapGrid);
};

#endif