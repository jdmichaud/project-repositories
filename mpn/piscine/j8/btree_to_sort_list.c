/*
** btree_to_sort_list.c for btree_to_sort_list in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sat Oct  6 19:29:17 2001 Jean-Daniel Michaudf
** Last update Sat Oct  6 19:31:53 2001 jean-daniel michaud
*/

#include "list.h"
#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

void	btree_to_sort_list(t_btree *btree, t_list **list)
{
  if (btree)
    {
      btree_to_sort_list(btree->right, list);
      list_put(list, btree->elem);
      btree_to_sort_list(btree->left, list);
    } 
}
