#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
public:
    Move(const std::string& line);

    int moveNumber;
    char player;
    int row;
    int column;

    bool isValid(char expectedPlayer) const;
};

#endif // MOVE_H

