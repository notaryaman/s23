#include "Move.h"
#include <sstream>
#include <stdexcept>
#include <cctype>

Move::Move(const std::string& line) {
    std::istringstream iss(line);
    std::string square;
    iss >> moveNumber >> player >> square;

    if (iss.fail() || !iss.eof()) {
        throw std::runtime_error("Parse error");
    }

    player = toupper(player);
    square[0] = toupper(square[0]);
    row = square[0] - 'A';
    column = square[1] - '1';
}

bool Move::isValid(char expectedPlayer) const {
    return moveNumber >= 1 && moveNumber <= 9 &&
           player == expectedPlayer &&
           row >= 0 && row < 3 &&
           column >= 0 && column < 3;
}
