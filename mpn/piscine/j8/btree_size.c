/*
** btree_size.c for btree_size in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 21:39:21 2001 jean-daniel michaud
** Last update Sat Oct  6 19:31:44 2001 jean-daniel michaud
*/

#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int	btree_size(t_btree *btree)
{
  if (btree)
    return (btree_size(btree->left) + btree_size(btree->right) + 1);
  return (0);
}
