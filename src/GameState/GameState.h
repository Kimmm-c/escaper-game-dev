#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>
#include <utility>
#include <map>
#include <set>

using namespace std;

class GameState {
    uint8_t mapWidth;
    uint8_t mapHeight;
    map<pair<uint8_t, uint8_t>, set<pair<uint8_t, uint8_t>>> graph;
    pair<uint8_t, uint8_t> playerPosition;

public:
    GameState(uint8_t w,
              uint8_t h,
              map<pair<uint8_t, uint8_t>, set<pair<uint8_t, uint8_t>>> graph,
              pair<uint8_t, uint8_t> playerPosition);
    template<class Archive>
    void serialize(Archive &ar);
};

template<class Archive>
void GameState::serialize(Archive &ar) {
    ar(playerPosition, mapWidth, mapHeight, graph);
}

#endif //GAMESTATE_H