#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = '-';
        }
    }
}

bool Board::applyMove(const Move& move) {
    if (grid[move.row][move.column] == '-') {
        grid[move.row][move.column] = move.player;
        return true;
    }
    return false;
}

bool Board::isWinningMove(const Move& move) const {
    char player = move.player;
    int row = move.row;
    int column = move.column;

    // Check row
    if (grid[row][0] == player && grid[row][1] == player && grid[row][2] == player)
        return true;

    // Check column
    if (grid[0][column] == player && grid[1][column] == player && grid[2][column] == player)
        return true;

    // Check diagonal
    if (row == column && grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;

    // Check anti-diagonal
    if (row + column == 2 && grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

bool Board::isFull() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}


