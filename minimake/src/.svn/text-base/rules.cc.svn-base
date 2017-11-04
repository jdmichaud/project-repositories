//
// rules.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 23 14:39:08 2002 jean-daniel michaud
// Last update Sun Feb 24 13:13:24 2002 jean-daniel michaud
//


#include "rules.hh"
#include "stat.hh"
#include "node.hh"

extern Option	opts;

//
// Constructeur de Rules
//

Rules::Rules(const Rules& r)
{
  _name = r.getName();
  _action = r.getAction();
  _tdeps = r.getDeps();
  _done = r.isDone();
  _num = r.getNumber();
  if (opts.Verbose())
    cout << "rules born" << endl;
}

//
// Methodes de Rules
//

void	Rules::add(const string& s)
{
  _tdeps.push_back(s);
}

void	Rules::putName(const string& name)
{
  _name = name;
}

void	Rules::putAction(const list<string> action)
{
  _action = action;
}

void	Rules::putNum(unsigned short n)
{
  _num = n;
}


void				Rules::convert(const list<Rules> rules)
{
  list<Rules>::const_iterator	rroute;
  list<string>::const_iterator	sroute;

  for (sroute = _tdeps.begin(); sroute != _tdeps.end(); ++sroute)
    for (rroute = rules.begin(); rroute != rules.end(); ++rroute)
      if ((*rroute).getName() == (*sroute))
	//	_deps.push_back(*rroute);//
	;
}

void				Rules::execute(void) const
{
  list<string>::const_iterator	actions;
  
  for (actions = _action.begin(); actions != _action.end(); ++actions)
    if ((*actions)[0] == '@')
      {
	if (system(&((*actions).data()[1])) != 0)
	  {
	    cerr << "*** Error code 2" << endl;
	    exit (2);
	  }
      }
    else
      {
	  cout << *actions << endl;
	  if (system((*actions).data()) != 0)
	    {
	      cerr << "*** Error code 2" << endl;
	      exit (2);
	    }
      }
}

bool		Rules::mustReact(void) const
{
  list<string>::const_iterator	route;
  
  if (opts.Verbose())
    cout << _name << endl;
  for (route = _tdeps.begin(); route != _tdeps.end(); ++route)
    if ((!is_exist(*route)) || is_older(getName(), (*route)))
      return (true);
  return (false);
}
