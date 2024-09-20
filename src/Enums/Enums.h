#ifndef ENUMS_H
#define ENUMS_H

namespace Enums {
    enum Level {
        EASY = 1,
        NORMAL = 2,
        HARD = 3
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