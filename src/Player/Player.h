#ifndef PLAYER_H
#define PLAYER_H

#include<cstdint>
#include "../BaseCharacter/BaseCharacter.h"

class Player : public BaseCharacter {
public:
    Player(uint8_t x, uint8_t y) : BaseCharacter(x, y) {};
};

#endif