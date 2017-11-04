/*
** btree_add_btree.c for btree_add_btree in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sat Oct  6 19:02:59 2001 Jean-Daniel Michaudf
** Last update Sat Oct  6 19:29:29 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_add_btree(t_btree **father, t_btree *son, t_cmpfunc cmp)
{
  if (son)
    {
      btree_put(father, son->elem, cmp);
      btree_add_btree(father, son->left, cmp);
      btree_add_btree(father, son->right, cmp);
    }
}
