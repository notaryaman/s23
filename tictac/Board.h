#include <iostream>

class Move {
public:
    int row, col;

    Move(int row, int col) : row(row), col(col) {}
};

std::ostream &operator<<(std::ostream &os, const Move &move) {
    os << "Move(row: " << move.row << ", col: " << move.col << ")";
    return os;
}

int main(int argc, char **argv) {
    Move move(1, 2);
    std::cout << move << '\n';
    return 0;
}
