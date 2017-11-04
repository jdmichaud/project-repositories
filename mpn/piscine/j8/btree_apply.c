/*
** btree_apply.c for btree_apply in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 21:29:42 2001 jean-daniel michaud
** Last update Sat Oct  6 19:30:03 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_apply(t_btree *btree, void (*f)(void *))
{
  if (btree)
    {
      btree_apply(btree->left, f);
      f(btree->elem);
      btree_apply(btree->right, f);
    }
}
