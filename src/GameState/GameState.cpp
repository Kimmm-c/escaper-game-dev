#include "GameState.h"

#include <utility>

GameState::GameState(uint8_t w,
                     uint8_t h,
                     map<pair<uint8_t, uint8_t>, set<pair<uint8_t, uint8_t>>> graph,
                     pair<uint8_t, uint8_t> playerPosition)
                     : mapWidth(w)
                     , mapHeight(h)
                     , graph(std::move(graph))
                     , playerPosition(std::move(playerPosition)){}