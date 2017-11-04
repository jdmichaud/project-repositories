/*
** btree_depth.c for btree_depth in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 21:44:06 2001 jean-daniel michaud
** Last update Sun Oct  7 20:54:23 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int	btree_depth(t_btree *btree)
{
  int		a;
  int		b;
  
  if (!btree)
    return (0);
  if (!(btree->left) && !(btree->right))
    return (0);
  else
    {
      a = btree_depth(btree->left);
      b = btree_depth(btree->right);
      if (a > b)
	return (a + 1);
      else
	return (b + 1);
    }
}
