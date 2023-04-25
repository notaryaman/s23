#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
#include "Errors.h"

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
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
