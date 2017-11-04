/*
** max_min.c for max_min in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sat Oct  6 14:31:45 2001 Jean-Daniel Michaudf
** Last update Sat Oct  6 19:32:10 2001 jean-daniel michaud
*/

#include "max_min.h"

t_btree	*max(t_btree *btree)
{
  if (btree->left)
    return (max(btree->left));
  if (btree->right)
    return (max(btree->right));
  return (btree);
}

t_btree	*min(t_btree *btree)
{
  if (btree->right)
    return (min(btree->left));
  if (btree->left)
    return (min(btree->right));
  return (btree);
}
