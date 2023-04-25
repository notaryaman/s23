#include "Errors.h"
#include "Move.h"
#include <sstream>
using namespace std;

Move::Move(const std::string& input)
{
    std::istringstream in(input);
    in >> number;
    in >> player;
    player = toupper(player);

    char rowChar, colChar;
    in >> rowChar >> colChar;
    int col = colChar - '0';

    if (number > 9 || number < 1) 
    {
        throw ParseError("Invalid number");
    }

    if (player == 'O' || player == 'X') 
    {
        player = player;
    } 
     else 
    {
        throw ParseError("Invalid player");
    }

    if (rowChar >= 'A' && rowChar <= 'C') 
    {
        row = rowChar - 'A';
    } 
    else
    {
        throw ParseError("Invalid row");
    }

    if (col >= 1 && col <= 3)
    {
        column = col - 1;
    } 
  else
  {
        throw ParseError("Invalid column");
    }

    if (!in.eof())
    {
        char nextChar;
        in >> nextChar;
        if (nextChar != '#') 
        {
            throw ParseError("Invalid after column");
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const Move& move)
{
    stream << move.number << ' ' << move.player << ' ';
    stream << static_cast<char>('A' + move.row) << static_cast<char>('1' + move.column);
    return stream;
}
