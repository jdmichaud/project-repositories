/*
** btree_add_list.c for btree_add_list in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sat Oct  6 19:11:59 2001 Jean-Daniel Michaudf
** Last update Sat Oct  6 19:29:39 2001 jean-daniel michaud
*/

#include "list.h"
#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_add_list(t_btree **btree, t_list *list, t_cmpfunc cmp)
{
  while (list)
    {
      btree_put(btree, list->elem, cmp);
      list = list->next;
    }
}
