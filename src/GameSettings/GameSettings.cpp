#include "GameSettings.h"

int GameSettings::getDifficulty() const { return difficulty; }

int GameSettings::getMapGrid() const { return mapGrid; }

void GameSettings::setDifficulty(int newDifficulty) { difficulty = newDifficulty; }

void GameSettings::setMapGrid(int newGrid) { mapGrid = newGrid; }