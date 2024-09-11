#ifndef PHYSIC_ENGINE_H
#define PHYSIC_ENGINE_H

#include "../Player/Player.h"

class PhysicEngine {

public:
    void detectCollision(Player player, BaseCharacter* enemies);
};

#endif