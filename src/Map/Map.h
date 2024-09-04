#ifndef MAP_H
#define MAP_H

#include<cstdint>

class Map {
    uint8_t width;
    uint8_t height;

public:
    Map(uint8_t w, uint8_t h);
    void draw();

private:
    uint8_t getWidth() const;
    uint8_t getHeight() const;
};

#endif