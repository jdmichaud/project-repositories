//
// node.hh for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 23 14:44:17 2002 jean-daniel michaud
// Last update Sat Feb 23 14:50:23 2002 jean-daniel michaud
//

#ifndef NODE_HH_
# define NODE_HH_

#include <list>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "rules.hh"
#include "options.hh"

using namespace std;

class	Node
{
public:
  explicit Node(const int i, const int j) : _i(i), _j(j)
  {
  }
  ~Node () {}

  int	getI(void) const { return (_i); }
  int	getJ(void) const { return (_j); }

private:
  int		_i;
  int		_j;
};

class	StackNode
{
public:
  void		push(unsigned i);
  void		pop(void);
  bool		isHere(const unsigned i);
 
  list<unsigned>	_node;
};


#endif /* !NODE_HH_ */
