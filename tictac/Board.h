#ifndef BOARD_H
#define BOARD_H

#include "Move.h"

class Board {
public:
    Board();

    bool applyMove(const Move& move);
    bool isWinningMove(const Move& move) const;
    bool isFull() const;

private:
    char grid[3][3];
};

#endif // BOARD_H

