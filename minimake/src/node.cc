//
// node.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 23 14:44:50 2002 jean-daniel michaud
// Last update Sat Feb 23 15:46:54 2002 jean-daniel michaud
//

#include "node.hh"

extern Option	opts;

//
// Methode de StackNode
//

void		StackNode::push(const unsigned i)
{
  if (opts.Verbose())
    cout << ">> " << i << endl;
  _node.push_front(i);
}

void		StackNode::pop(void)
{
  if (opts.Verbose())
    cout << "<< " << (*(_node.begin())) << endl;
  _node.pop_front();
}

bool		StackNode::isHere(const unsigned i)
{
  list<unsigned>::const_iterator	l;

  if (opts.Verbose())
    cout << "is here " << i << endl;
  for (l = _node.begin(); l != _node.end(); ++l)
    if ((*l) == i)
      return (true);
  return (false);
}
