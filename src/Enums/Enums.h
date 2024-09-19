#ifndef ENUMS_H
#define ENUMS_H

namespace Enums {
    enum Level {
        EASY,
        NORMAL,
        HARD
    };

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum GameState {
        WIN,
        LOSE,
        EXIT,
        RESTART
    };
};


#endif //ENUMS_H