/*
** main.c for minimake in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Feb 16 08:18:30 2002 jean-daniel michaud
// Last update Sun Feb 24 12:00:20 2002 jean-daniel michaud
*/

#include <iostream>
#include <list>
#include "parse.hh"
#include "common.hh"
#include "options.hh"
#include "graph.hh"
#include "except.hh"

Graph		graph;
Option		opts;

int		main(unsigned int argc, char* argv[])
{
  try
    {
      opts.Get(argc, argv);
      yydebug = opts.GetTrace();
      parse((opts.GetName()).c_str());
      graph.makeAdj();
      if (opts.Verbose())
	{
	  graph.show(cout);
	  graph.showVar(cout);
	}
      graph.hasCycle();
      graph.checkDepedencies();
      graph.exec(opts);
      return (0);
    }
  catch (Cycle& c)
    {
      cout << "minimake: Graph cycles through " << c._rule << endl;
      exit (1);
    }
  catch (UknRule& u)
    {
      cout << "minimake: don't know how to make " 
	   << u._file << ". Stop" << endl;
      exit(2);
    }
}
