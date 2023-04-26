#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <cctype>
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
  play = str(player);
    int col = column;
  string tot = itoa(number) + str(player)  + itoa(row) + itoa(column);
  if(tot.length()<6)
  {
    throw ParseError("Invalid length");
  }
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
    char nxt;
    in >> nextChar;
    in >> nxt;
    if (!isspace(nextChar))
    {
        throw ParseError("Invalid after column");
    }
    if(nxt != '#')
    {
      throw ParseError("Invalid after column");
    }
  }
}

std::ostream& operator << (std::ostream& stream, const Move& move) 
{
  stream<<move.number<<' '<<move.player<<' ';
  stream<< move.row<< move.column;
  return stream;
}
