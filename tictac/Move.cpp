#include "Errors.h"
#include "Move.h"
#include <sstream>
using namespace std;
// Space for implementing Move functions.

Move::Move(const std::string& input)
{
  std::istringstream in(input);
  in>>number;
  in>>player;
  player = toupper(player);
  in>>row;
  in>>column;
  int col = std::stoi(column);
  if(number>9||number<1)
  {
          throw ParseError("Invalid number");
  }
  if(player == 'O' || player == 'X')
  {
          player = player;
  }
  else
  {
          throw ParseError("Invalid player");
  }
  if(row>='A' && row<='C')
  {
          row = (row - 'A') + 1;
  }
   else
  {
          throw ParseError("Invalid row");
  }
  if(col>=1 &&col<= 3)
  {
       column = column;
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

std::ostream& operator << (std::ostream& stream, const Move& move) 
{
  stream<<move.number<<' '<<move.player<<' ';
  stream<< row<< column;
  return stream;
}
