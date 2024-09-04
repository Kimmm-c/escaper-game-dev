#ifndef PLAYER_H
#define PLAYER_H

#include<cstdint>
#include "../BaseCharacter/BaseCharacter.h"

class Player : public BaseCharacter {
    uint8_t health = 100;

public:
    void setHealth(uint8_t newHealth);

private:
    uint8_t getHealth() const;
};

#endif