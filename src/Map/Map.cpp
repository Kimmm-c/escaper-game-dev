#include "Map.h"

Map::Map(uint8_t w, uint8_t h)
        : width(w), height(h) {}

void Map::draw() {

}

uint8_t Map::getWidth() const { return width; }

uint8_t Map::getHeight() const { return height; }