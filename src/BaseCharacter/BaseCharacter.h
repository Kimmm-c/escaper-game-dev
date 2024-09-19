#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include<utility>
#include<cstdint>

using namespace std;

class BaseCharacter {
    pair<uint8_t, uint8_t> position;

public:
    BaseCharacter(uint8_t x, uint8_t y);

    void setPosition(pair<uint8_t, uint8_t> newPosition);

    pair<uint8_t, uint8_t> getPosition() const;
};

#endif