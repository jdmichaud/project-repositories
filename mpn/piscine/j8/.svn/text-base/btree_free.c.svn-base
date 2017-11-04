/*
** btree_free.c for btree_free in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sat Oct  6 18:57:26 2001 Jean-Daniel Michaudf
** Last update Sat Oct  6 19:31:04 2001 jean-daniel michaud
*/


#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_free(t_btree **btree)
{
  if ((btree) && (*btree))
    {
      btree_free(&((*btree)->left));
      btree_free(&((*btree)->right));
      free(*btree);
      *btree = NULL;
    }
}
