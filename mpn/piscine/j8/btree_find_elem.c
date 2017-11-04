/*
** btree_find_elem.c for btree_find_elem in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 22:34:21 2001 jean-daniel michaud
** Last update Sat Oct  6 19:30:42 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void		*btree_find_elem(t_btree *btree, void *elem, t_cmpfunc cmp)
{
  void		*node;

  if (btree)
    {
      node = btree_find_elem(btree->left, elem, cmp);
      if (node)
	return (node);
      if (!cmp(btree->elem, elem))
	return (btree->elem);
      node = btree_find_elem(btree->right, elem, cmp);
      if (node)
	return (node);
    }
  return (0);
}
