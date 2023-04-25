#include "Errors.h"
#include "Board.h"
#include <iostream>
#include <vector>
#include <string>
#include "Move.h"
// Space for implementing Board functions.

Board::Board() : board_(3, std::vector<char>(3, ' ')) {}

bool Board::applyMove(const Move& move) {
    if (board_[move.row][move.column] != ' ') {
        return false;
    }
    board_[move.row][move.column] = move.player;
    return true;
}

bool Board::isWinningMove(const Move& move) const {
    char player = move.player;

    for (int i = 0; i < 3; ++i) {
        if ((board_[i][0] == player && board_[i][1] == player && board_[i][2] == player) ||
            (board_[0][i] == player && board_[1][i] == player && board_[2][i] == player)) {
            return true;
        }
    }

    if ((board_[0][0] == player && board_[1][1] == player && board_[2][2] == player) ||
        (board_[0][2] == player && board_[1][1] == player && board_[2][0] == player)) {
        return true;
    }

    return false;
}

bool Board::isFull() const {
    for (const auto& row : board_) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    Board board;
    std::string line;
    int moves = 0;

    while (std::getline(std::cin, line)) {
        try {
            Move move(line);

            if (!board.applyMove(move)) {
                std::cout << "Invalid move." << std::endl;
                return 2;
            }

            ++moves;

            if (board.isWinningMove(move)) {
                std::cout << "Game over: " << move.player << " wins." << std::endl;
                return 0;
            }

            if (board.isFull()) {
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
