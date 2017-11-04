/*
** tree.c for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Oct 26 00:01:01 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 19:09:43 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include "errors.h"
#include "tree.h"
#include "stack.h"
#include "compute.h"
#include "my_stdlib.h"

void	free_node(t_node *node)
{
  if (node->type == NODE_OP)
    {
      free_node(node->elm.op.left);
      free_node(node->elm.op.right);
      free(node);
    }
  else
    {
      mpq_clear(node->elm.num.value);
      free(node);
    }
}

t_node		*create_node(t_type type, char c, mpq_t num, t_fils *fils)
{
  t_node	*node;

  node = xmalloc(sizeof (t_node));
  node->type = type;
  if (node->type == NODE_OP)
    {
      node->elm.op.c = c;
      node->elm.op.left = fils->left;
      node->elm.op.right = fils->right;
    }
  else
    {
      mpq_init(node->elm.num.value);
      mpq_set(node->elm.num.value, num);
    }
  return (node);
}

void	show_tree(t_node *tree, FILE* fd)
{
  if (tree->type == NODE_NUM)
    mpq_out_str(fd, 10, tree->elm.num.value);
  else
    {
      fputc('(', fd);
      show_tree(tree->elm.op.left, fd);
      fputc(' ', fd);      
      fputc(tree->elm.op.c, fd);
      fputc(' ', fd);      
      show_tree(tree->elm.op.right, fd);
      fputc(')', fd);
    }
}

void		init_mpq(mpq_t **res)
{
  *res = xmalloc(sizeof (mpq_t));
  mpq_init(**res);
}

mpq_t		*calc_tree(t_node *tree)
{
  mpq_t		*res;
  mpq_t		*tmp1;
  mpq_t		*tmp2;
  
  init_mpq(&res);
  if (tree->type == NODE_NUM)
    mpq_set(*res, tree->elm.num.value);
  if (tree->type == NODE_NUM)
    return (res);
  if ((tree->elm.op.left == NULL) || (tree->elm.op.right == NULL))
    errors(ARG_ERR_VAL);
  tmp1 = calc_tree(tree->elm.op.left);
  tmp2 = calc_tree(tree->elm.op.right);
  if (tree->elm.op.c == '+')
    mpq_add(*res, *tmp1, *tmp2);
  if (tree->elm.op.c == '-')
    mpq_sub(*res, *tmp1, *tmp2);
  if (tree->elm.op.c == '*')
    mpq_mul(*res, *tmp1, *tmp2);
  if ((tree->elm.op.c == '/') && (!mpq_sgn (*tmp2)))
    errors(CAL_ERR_VAL);
  if (tree->elm.op.c == '/')
    mpq_div(*res, *tmp1, *tmp2);
  free_p(tmp1, tmp2, NULL, NULL);
  return (res);
}


