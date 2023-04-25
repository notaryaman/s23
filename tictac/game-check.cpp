#include "Board.h"
#include "Errors.h"
#include "Move.h"
#include <iostream>
int main() 
{
  std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    std::string line;
    int moves = 0;

    while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            if (board[move.row][move.column] != ' ') {
                std::cout << "Invalid move." << std::endl;
                return 2;
            }

            board[move.row][move.column] = move.player;
            ++moves;

            if (checkWin(board, move.player)) {
                std::cout << "Game over: " << move.player << " wins." << std::endl;
                return 0;
            }

            if (moves == 9) {
                std::cout << "Game over: Draw." << std::endl;
                return 0;
            }

        } catch (const ParseError& e) {
            std::cout << "Parse error." << std::endl;
            return 1;
        }
    }

    if (moves == 0) {
        std::cout << "Game in progress: New game." << std::endl;
    } else {
        char nextPlayer = (moves % 2 == 0) ? 'X' : 'O';
        std::cout << "Game in progress: " << nextPlayer << "'s turn." << std::endl;
    }

    return 0;
}
