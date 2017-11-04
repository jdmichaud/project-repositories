/*
** btree_add_to_left_end.c for btree_add_to_left in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 17:59:24 2001 jean-daniel michaud
** Last update Sat Oct  6 19:29:58 2001 jean-daniel michaud
*/

#include "btree.h"

void		*malloc(unsigned int);

void		btree_add_to_left_end(t_btree **root, void *elem)
{
  t_btree	*node;

  if (!(*root))
    {
      (*root) = malloc(sizeof (t_btree));
      (*root)->elem = elem;
      (*root)->left = 0;
      (*root)->right = 0;
    }
  node = (*root);
  while (node->left)
    node = node->left;
  node = malloc(sizeof (t_btree));
  node->elem = elem;
  node->left = 0;
  node->right = 0;
}








