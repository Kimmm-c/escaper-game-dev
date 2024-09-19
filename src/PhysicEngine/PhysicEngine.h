#ifndef PHYSIC_ENGINE_H
#define PHYSIC_ENGINE_H

#include "../Player/Player.h"
#include "../Map/Map.h"

class PhysicEngine {

public:
    bool detectCollision(const pair<uint8_t, uint8_t> &currentPosition, int direction, const Map *map) const;
};

#endif