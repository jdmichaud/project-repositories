//
// graph.hh for minimake in 
// 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sun Feb 17 11:58:08 2002 jean-daniel michaud
// Last update Sun Feb 24 15:31:43 2002 jean-daniel michaud
//

#ifndef GRAPH_HH_
# define GRAPH_HH_

#include <list>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "var.hh"
#include "node.hh"
#include "rules.hh"
#include "options.hh"

#define PASS	2
#define DONE	4

extern Option	opts;

using namespace std;

class Graph
{
public:
  Graph() : _rules_index(0) {
    if (opts.Verbose())
      cout << "Graph Born" << endl;
  }
  virtual ~Graph() { if (opts.Verbose()) cout << "Graph Die" << endl; }

  void		add(const string& name, 
		    list<string> actions, list<string> deps);
  void		addVar(const Variable& var) { _vars.push_back(var); }
  void		makeAdj(void);
  bool		hasCycle(void) const;
  void		exec(const Option& opts);
  void		clean(void);

  short		getNumber(const string &rule_name) const ;
  const char	*getValue(const string& name) const ;
  void		checkDepedencies(void) const;

  void		show(ostream& out) const ;
  void		showVar(ostream& out) const ;

private:
  void		createMat(void);
  void		cycleDetection(unsigned int i, 
			       unsigned  int j, StackNode& s) const ;
  bool		execution(unsigned i);
  bool		isLeaf(unsigned int i) 
  {
    for (unsigned int j = 0; j < _adj[i].size(); ++j)
      if (_adj[i][j])
	return (false);
    return (true);
  }

  unsigned short	_rules_index;
  vector<Rules>		_rules;
  vector<vector<int> >	_adj;
  vector<Variable>	_vars;

};

#endif /* !GRAPH_HH_ */
