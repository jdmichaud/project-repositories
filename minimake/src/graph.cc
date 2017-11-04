//
// graph.cc for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun Feb 17 16:54:57 2002 jean-daniel michaud
// Last update Sun Feb 24 15:31:37 2002 jean-daniel michaud
//

#include <stdlib.h>
#include <assert.h>
#include "graph.hh"
#include "except.hh"
#include "options.hh"
#include "stat.hh"
#include "rules.hh"
#include "node.hh"

extern Option	opts;

//
// Methode de Graph
//

void		Graph::add(const string& name, 
			   list<string> actions, list<string> deps)
{
  Rules		rules(name, actions, deps);

  if (opts.Verbose())
    cout << name << " va dependre de ";
  for (list<string>::const_iterator route = deps.begin(); route != deps.end();
       ++route)
    {
      if (opts.Verbose())
	cout << *route << " ";
    }
  if (opts.Verbose())
    cout << endl;
  rules.putNum(_rules_index++);
  _rules.push_back(rules);
}

void				Graph::makeAdj(void)
{
  vector<Rules>::const_iterator	rroute;
  list<string>::const_iterator	nroute;
  unsigned			i;

  createMat();
  if (!_rules.empty())
    for (rroute = _rules.begin(), i = 0; rroute != _rules.end(); ++rroute, ++i)
      for (nroute = ((*rroute).getDeps()).begin();
  	   nroute != ((*rroute).getDeps()).end(); ++nroute)
	_adj[i][getNumber(*nroute)] = 1;
}

void		Graph::show(ostream& out) const
{
  for (unsigned i = 0; i < _adj.size(); ++i)
    {
      for (unsigned j = 0; j < _adj[i].size(); ++j)
	out << _adj[i][j] << " ";
      out << endl;
    }
}

short				Graph::getNumber(const string& rule_name) const
{
  vector<Rules>::const_iterator	route;

  for (route = _rules.begin(); route != _rules.end(); ++route)
    if ((*route).getName() == rule_name)
      return ((*route).getNumber());
  return (-1);
}

bool		Graph::hasCycle(void) const
{
  StackNode	s;
  unsigned int	i;
  unsigned int	j;
  
  for (i = 0; i < _adj.size(); ++i)
    for (j = 0; j < _adj[i].size(); ++j)
      if (_adj[i][j] && !(_adj[i][j] & PASS))
	cycleDetection(i, j, s);
  return (1);
}

void		Graph::createMat(void)
{
  vector<int>	vi;

  for (int i = 0; i < _rules_index; ++i)
    {
      _adj.push_back(vi);
      for (int j = 0; j < _rules_index; ++j)
	_adj[i].push_back(0);
    }
}

void		Graph::clean(void)
{
  for (unsigned int i = 0; i < _adj.size(); ++i)
    for (unsigned int j = 0; j < _adj[i].size(); ++j)
      _adj[i][j] = _adj[i][j] ? 1 : 0;
}

void		Graph::cycleDetection(unsigned int i, 
				      unsigned int j, StackNode& s) const
{
  assert((i >= 0) && (i < _adj.size()));
  assert((j >= 0) && (j < _adj[i].size()));
  s.push(i);
  if (s.isHere(j))
    throw Cycle(_rules[i].getName());
  for (unsigned n = 0; n < _adj[j].size(); ++n)
    if (_adj[j][n])
      cycleDetection(j, n, s);
  s.pop();
}

void		Graph::exec(const Option& opts)
{
  int		i;

  if (opts.Verbose())
    cout << "--->>> Execution" << endl;
  if (!_rules.size())
    {
      cout << "minimake: no target to make." << endl;
      exit(2);
    }
  if ((i = (opts.IsRuleSpecify() ? getNumber(opts.GetRule()) : 0)) < 0)
    throw UknRule(opts.GetRule());
  execution(i);
}

bool		Graph::execution(unsigned i)
{
  list<string>::const_iterator	j;

  assert(i >= 0 && i < _rules.size());
  for (j = (_rules[i].getDeps()).begin();
       j != (_rules[i].getDeps()).end(); ++j)
    if ((getNumber(*j) >= 0) && !_rules[getNumber(*j)].isDone())
      execution(getNumber(*j));
  if ((!is_exist(_rules[i].getName())) || (_rules[i].mustReact()))
    _rules[i].execute();
  _rules[i].Done();
  return (true);
}

void		Graph::checkDepedencies(void) const
{
  for (unsigned i = 0; i < _rules.size(); ++i)
    for (list<string>::const_iterator j = (_rules[i].getDeps()).begin();
	 j != (_rules[i].getDeps()).end(); ++j)
      if ((getNumber(*j) < 0) && (!is_exist(*j)))
	throw UknRule(*j);
}

void		Graph::showVar(ostream& out) const
{
  for (unsigned i = 0; i < _vars.size(); ++i)
    cout << _vars[i].getName() << " " << _vars[i].getValue() << endl;
}

const char	*Graph::getValue(const string& name) const
{
  for (unsigned i = 0; i < _vars.size(); ++i)
    if (name == _vars[i].getName())
      return (_vars[i].getValue().c_str());
  return (NULL);
}
