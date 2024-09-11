#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../GameMenu/GameMenu.h"


class RenderEngine {

public:
    void renderMenu(GameMenu menu);
    void drawMap(Map map, Player player, BaseCharacter* enemies);
    void renderPlayerHealth(Player player);
};

#endif