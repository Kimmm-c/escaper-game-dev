#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

class GameSettings {
    int difficulty = 1;
    int mapGrid = 1;

public:
    int getDifficulty() const;
    int getMapGrid() const;
    void setDifficulty(int difficulty);
    void setMapGrid(int mapGrid);
};

#endif