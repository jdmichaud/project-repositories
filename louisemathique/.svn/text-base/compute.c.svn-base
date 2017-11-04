/*
** compute.c for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct 28 22:25:49 2001 jean-daniel michaud
** Last update Mon Oct 29 19:06:10 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>

#include "gmp.h"
#include "errors.h"
#include "tree.h"
#include "stack.h"
#include "compute.h"
#include "calc.h"
#include "my_stdlib.h"

void	do_op(mpq_t res, t_node *node)
{
  if (node->elm.op.c == '+')
    addm(res, node->elm.op.left, node->elm.op.right);
  if (node->elm.op.c == '-')
    subm(res, node->elm.op.left, node->elm.op.right);
  if (node->elm.op.c == '*')
    mulm(res, node->elm.op.left, node->elm.op.right);
  if (node->elm.op.c == '/')
    divm(res, node->elm.op.left, node->elm.op.right);
}

t_node		*compute(t_stack **stack)
{
  t_node	*node;

  node = pop(stack);
  if (!node)
    errors(ARG_ERR_VAL);
  if (node->type == NODE_OP)
    {
      node->elm.op.right = compute(stack);
      node->elm.op.left = compute(stack);
      return (node);
    }
  else
    return (node);
}
