/*
** btree_rm_all_eq.c for btree_rm_all_eq in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 22:49:55 2001 jean-daniel michaud
** Last update Sat Oct  6 19:38:26 2001 jean-daniel michaud
*/

#include "btree.h"
#include "max_min.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_rm_all_eq(t_btree **btree, void *elem, t_cmpfunc cmp)
{
  t_btree *node;
  
  if (!((btree) && (*btree)))
    return;
  btree_rm_all_eq(&((*btree)->left), elem, cmp);
  btree_rm_all_eq(&((*btree)->right), elem, cmp);
  if (!cmp(elem, (*btree)->elem))
    {
      if (!((*btree)->left) && !((*btree)->right))
	{
	  free(*btree);
	  (*btree) = NULL;
	}
      else
	{
	  node = (*btree);
	  if ((*btree)->left)
	    (*btree) = max((*btree)->left);
	  else
	    (*btree) = min((*btree)->right);
	  free(node);
	  node = NULL;
	}  
    }
}


