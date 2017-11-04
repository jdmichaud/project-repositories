/*
** btree_find_node.c for btree_find_node in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 22:18:25 2001 jean-daniel michaud
** Last update Sat Oct  6 19:30:55 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

t_btree		*btree_find_node(t_btree *btree, void *elem, t_cmpfunc cmp)
{
  t_btree	*node;
  
  if (btree)
    {
      node = btree_find_node(btree->left, elem, cmp);
      if (node)
	return (node);
      if (!cmp(btree->elem, elem))
	return (btree);
      node = btree_find_node(btree->right, elem, cmp);
      if (node)
	return (node);
    }
  return (0);
}
