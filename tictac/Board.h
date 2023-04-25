#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Move.h"

// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board {
public:
    Board();
    bool applyMove(const Move& move);
    bool isWinningMove(const Move& move) const;
    bool isFull() const;

private:
    std::vector<std::vector<char>> board_;
};
#endif
