#include "Board.h"

Board::Board() {
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            grid[i][j] = '-';
        }
    }
}

bool Board::applyMove(Move& move) 
{
    if (grid[move.row][move.column] == '-') 
    {
        grid[move.row][move.column] = move.player;
        return true;
    }
    return false;
}

bool Board::isWinningMove(const Move& move) 
{
    char player = move.player;
    int row = move.row;
    int column = move.column;
    if (grid[row][0] == player && grid[row][1] == player && grid[row][2] == player)
        return true;
    if (grid[0][column] == player && grid[1][column] == player && grid[2][column] == player)
        return true;
    if (row == column && grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (row + column == 2 && grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

bool Board::isFull() 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (grid[i][j] == '-') 
            {
                return false;
            }
        }
    }
    return true;
}


