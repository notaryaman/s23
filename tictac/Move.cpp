#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <cctype>
#include <iostream>
using namespace std;
// Space for implementing Move functions.

Move::Move(const std::string& input)
{
  string inp;
  std::getline(cin, inp);
  number = inp[0];
  player = inp[2];
  row = inp[4];
  column = inp[5];
  player = toupper(player);
  string play = str(player);
  int col = column;
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
 /* if (!in.eof())
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
  }*/
}

std::ostream& operator << (std::ostream& stream, const Move& move) 
{
  stream<<move.number<<' '<<move.player<<' ';
  stream<< move.row<< move.column;
  return stream;
}
