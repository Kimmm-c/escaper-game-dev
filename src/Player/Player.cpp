#include "Player.h"

void Player::setHealth(uint8_t newHealth) {
    health = newHealth;
}

uint8_t Player::getHealth() const { return health; }