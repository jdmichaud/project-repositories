//
// rules.hh for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 23 14:39:43 2002 jean-daniel michaud
// Last update Sat Feb 23 15:46:25 2002 jean-daniel michaud
//

#ifndef RULES_HH_
# define RULES_HH_

#include <list>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "options.hh"

extern Option	opts;

using namespace std;

class Rules
{
public:
  Rules(const string& name, list<string> action, list<string> deps) 
    : _name(name), _action(action), _tdeps(deps), _done(0)
  {
    if (opts.Verbose())
      cout << "rules born" << endl;
  }
  Rules(const Rules& r);
  virtual ~Rules() 
  {
    list<Rules*>::const_iterator	route;

    for (route = _deps.begin(); route != _deps.end(); ++route)
      delete (*route);
    if (opts.Verbose())
      cout << "rules die" << endl;
  }

  void		add(const string& s);
  void		putName(const string& name);
  void		putAction(const list<string> action);
  void		putNum(unsigned short n);
  void		convert(const list<Rules> rules);
  bool		mustReact(void) const;
  void		execute(void) const;
  void		Done(void) { _done = true; }

  string	getName(void) const { return (_name); }
  const list<string>&	getAction(void) const { return (_action); }
  const list<string>&	getDeps(void) const { return (_tdeps); }
  short		getNumber(void) const { return (_num); }
  bool		isDone(void) const { return (_done); }

private:
  string		_name;
  list<string>		_action;
  list<Rules*>		_deps;
  list<string>		_tdeps;
  bool			_done;
  unsigned short	_num;
};

#endif /* !RULES_HH_ */
