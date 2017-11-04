/*
** btree_put.c for btree_put in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 20:43:27 2001 jean-daniel michaud
** Last update Sat Oct  6 19:31:23 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_put(t_btree **btree, void *elem, t_cmpfunc cmp)
{
  if (*btree == NULL)
    {
      *btree = malloc(sizeof (t_btree));
      (*btree)->elem = elem;
      (*btree)->right = 0;
      (*btree)->left = 0;
    }
  else
    if (cmp(elem, (*btree)->elem) <= 0)
      btree_put(&((*btree)->left), elem, cmp);
    else
      btree_put(&((*btree)->right), elem, cmp);
}
