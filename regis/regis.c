/*
** regis.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec  5 14:08:50 2001 jean-daniel michaud
** Last update Mon Dec 10 12:32:15 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "mkgraph.h"
#include "regis.h"
#include "list.h"
#include "algo.h"
#include "utils.h"

#include "debug.h"

extern	char	*gl_str;

int		main(void)
{
  t_matrix	*matrix;
  t_list	*list;

  list = NULL;
  matrix = make_graph();
  list = reduce(matrix, matrix->nnode + 1);
  if (iscolorize(list))
    spile(matrix, list);
  else 
    {
      err_spile(matrix, list);
      return (2);
    }
  return (0);
}

