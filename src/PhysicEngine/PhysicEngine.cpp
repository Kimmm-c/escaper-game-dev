#include "PhysicEngine.h"

bool PhysicEngine::detectCollision(const pair<uint8_t, uint8_t> &currentPosition, int direction, const Map *map) const {
    pair<uint8_t, uint8_t> nextPosition = map->getNextPosition(currentPosition, direction);
    auto it = map->getGraph().find(currentPosition);

    // If currentPosition exists, check if currentPosition is connected to the next visited position
    if (it != map->getGraph().end()) {
        return it->second.count(nextPosition) > 0;
    }

    return false;
}
