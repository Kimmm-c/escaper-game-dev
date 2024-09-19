#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(uint8_t x, uint8_t y)
        : position{make_pair(x, y)} {}

pair<uint8_t, uint8_t> BaseCharacter::getPosition() const { return position; }

void BaseCharacter::setPosition(pair<uint8_t, uint8_t> newPosition) {
    position = newPosition;
}