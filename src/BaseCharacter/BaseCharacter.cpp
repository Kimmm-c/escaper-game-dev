#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(uint8_t x, uint8_t y)
        : position{x, y} {}

pair<uint8_t, uint8_t> BaseCharacter::getPosition() const { return position; }

void BaseCharacter::setPosition(uint8_t newX, uint8_t newY) {
    position.first = newX;
    position.second = newY;
}