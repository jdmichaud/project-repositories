/*
** louise.c for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 22:55:44 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 19:31:18 2001 jean-daniel michaud
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <gmp.h>
#include "errors.h"
#include "tree.h"
#include "stack.h"
#include "io.h"
#include "louise.h"
#include "compute.h"

int		main()
{
  t_stack	*stack;
  mpq_t		*res;
  t_node	*tree;

  stack = NULL;
  stack = get_expr(stack);
  tree = compute(&stack);
  res = calc_tree(tree);
  if (stack)
    errors(STK_ERR_VAL);
  show_tree(tree, stdout);
  fputc(' ', stdout);
  fputc('=', stdout);
  fputc(' ', stdout);
  mpq_out_str(stdout, 10, *res);
  fputc('\n', stdout);
  free_node(tree);
  mpq_clear(*res);
  free(res);
  return (0);
}
