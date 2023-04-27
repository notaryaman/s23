#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <cctype>
#include <iostream>
using namespace std;
// Space for implementing Move functions.

Move::Move(const std::string& input)
{
  number = input.at(0);
  player = input.at(2);
  row = input.at(4);
  column = input.at(5);
  player = toupper(player);
  int col = column;
  size_t len = input.length();
  if(!isspace(input.at(1)))
     {
        throw ParseError("Invalid structure");
     }
  if(!isspace(input.at(3)))
     {
        throw ParseError("Invalid structure");
     }
    
  if(len<6)
  {
    throw ParseError("Invalid length");
  }
  if(len>6)
  {
    if(isspace(input.at(6)))
    {
      if(input.at(7) == '#')
      {
        len = len;
      }
      else
      {
        throw ParseError("Invalid comment");
      }
    }
    else
    {
      throw ParseError("Invalid comment");
    }
  }
  if(number<=9 && number>=1)
  {
          number=number;
  }
  else
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
