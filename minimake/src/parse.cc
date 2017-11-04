//
// parse.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 16 13:11:23 2002 jean-daniel michaud
// Last update Sat Feb 23 15:05:54 2002 jean-daniel michaud
//

#include <iostream>
#include <string>
#include "parse.hh"

using namespace std;

void	*parse (const string& fname)
{
  scan_open(fname);
  yyparse();
  scan_close();
  return (NULL);
}
