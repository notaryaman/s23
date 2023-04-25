#include <iostream>
#include <string>
#include "Errors.h"
#include "Move.h"
#include "Board.h"

int main() {
    Board board;
    std::string line;
    char nextPlayer = 'X';

    while (std::getline(std::cin, line)) {
        try {
            Move move(line);
            if (move.player != nextPlayer) {
                std::cout << "Invalid move." << std::endl;
                return 2;
            }

            if (!board.applyMove(move)) {
                std::cout << "Invalid move." << std::endl;
                return 2;
            }

            if (board.isWinningMove(move)) {
                std::cout << "Game over: " << move.player << " wins." << std::endl;
                return 0;
            }

            if (board.isFull()) {
                std::cout << "Game over: Draw." << std::endl;
                return 0;
            }

            nextPlayer = (nextPlayer == 'X') ? 'O' : 'X';
        } catch (const ParseError& e) {
            std::cout << "Parse error." << std::endl;
            return 1;
        }
    }

    if (nextPlayer == 'X') {
        std::cout << "Game in progress: New game." << std::endl;
    } else {
        std::cout << "Game in progress: " << nextPlayer << "'s turn." << std::endl;
    }

    return 0;
}
