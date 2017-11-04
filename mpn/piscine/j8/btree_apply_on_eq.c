/*
** btree_apply_on_eq.c for btree_apply_on_eq in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 22:12:54 2001 jean-daniel michaud
** Last update Sat Oct  6 19:43:13 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_apply_on_eq(t_btree *btree,
			void (*f)(void *),
			void *elem,
			t_cmpfunc cmp)
{
  if (btree)
    {
      btree_apply_on_eq(btree->left, f, elem, cmp);
      if (!cmp(elem, btree->elem))
	f(btree->elem);
      btree_apply_on_eq(btree->right, f, elem, cmp);
    }      
}
