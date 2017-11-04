//
// parse.cc for  in 
// 
// Made by GIZMO
// Login   <grimau_r@epita.fr>
// 
// Started on  Sun May 19 11:04:40 2002 GIZMO
// Last update Tue May 28 15:12:00 2002 jean-daniel michaud
//

#include <stack>
#include <stdio.h>
#include "parse.hh"
#include "lexer.h"

extern int background_p;

extern "C"
{
#include "pgm.h"
}

std::vector<Vector3D>		Parse::parse_point() const
{
  string			file;
  double			nb;
  std::stack<double>		stck;
  std::vector<Vector3D>		points;
  
  file = getPointFilename();
  lex_open(file.c_str());
  
  while (yylex(&nb) != MEOF)
    {
      stck.push(nb);
      if (stck.size() == 3)
	{
	  double c = stck.top();
	  stck.pop();
	  double b = stck.top();
	  stck.pop();
	  double a = stck.top();
	  stck.pop();

	  points.push_back(*new Vector3D(a, b, c));
	}
    }
  if (stck.size() != 0)
    {
      std::cerr << "math: bad file of points !" << std::endl;
      exit(1);
    }
  
  lex_close();
  return (points);
}


gray		**Parse::parse_pgm(int *cols, int *rows, gray *maxval) const
{
  gray	**pgmbuf = NULL;
  FILE	*f;
  
  if ((f = fopen(getPGMFilename().c_str(), "r")) != 0)
    {
      if ((pgmbuf = pgm_readpgm(f, cols, rows, maxval)) == 0)
	{
	  std::cerr << "math: bad pgm file !" << std::endl;
	  exit(1);
	}
      fclose(f);
    }
  return (pgmbuf);
}

Model&		Parse::generate_points() const
{
  gray	**pgmbuf;
  int	cols;
  int	rows;
  gray	maxval;

  pgmbuf = parse_pgm (&cols, &rows, &maxval);
  Model *model = new Model(cols, rows, maxval);
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (background_p || pgmbuf[i][j] != 0)
	model->add_point (i, j, pgmbuf[i][j]);
  free (pgmbuf);
  return (*model);
}
