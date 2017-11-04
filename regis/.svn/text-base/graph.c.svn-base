/*
** graph.c for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec  6 10:14:58 2001 jean-daniel michaud
** Last update Mon Dec 10 16:22:07 2001 jean-daniel michaud
*/

#include "defs.h"
#include "struct.h"
#include "graph.h"

int	degree(t_matrix *matrix, int inode)
{
  int	i;
  int	d;

  for (d = 0, i = 0; i < matrix->nnode; ++i)
    if ((i != inode) && (matrix->graph[inode][i] > 0))
      ++d;
  return (d);
}

int		lifr_node(int *tnode, t_matrix *matrix)
{
  int		i;
  unsigned int	min;
  int		node;

  for (min = -1, i = 0, node = -1; i < matrix->nnode; ++i)
    if ((min > tnode[i]) && (tnode[i] > -1))
      {
	min = tnode[i];
	node = i;
      }
  return (node);
}

int	find_nsnode(t_matrix *matrix)
{
  int	inode;
  int	d;

  for (inode = 0, d = degree(matrix, inode); (inode < matrix->nnode)
	 && ((d >= matrix->ncolor) || (matrix->graph[inode][inode] < 0)); 
       ++inode)
    d = degree(matrix, inode);
  if (inode < matrix->nnode)
    return (inode);
  return (-1);
}

int	pure(int *nodes, int degree, int n)
{
  int	i;

  for (i = 0; i < n; ++i)
    if (nodes[i] > degree)
      nodes[i] = -1;
  return (1);
}
