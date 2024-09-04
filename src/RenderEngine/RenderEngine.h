#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include "../Map/Map.h"
#include "../Player/Player.h"


class RenderEngine {
    void drawMap(Map map, Player player, BaseCharacter* enemies);
    void renderPlayerHealth(Player player);
};

#endif