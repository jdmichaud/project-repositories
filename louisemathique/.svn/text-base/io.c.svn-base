/*
** io.c for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 23:29:25 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 19:48:04 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "tree.h"
#include "stack.h"
#include "my_ctype.h"
#include "io.h"
#include "errors.h"

t_node		*get_number(FILE *fd, char c)
{
  mpq_t		nbr;
  mpz_t		nbr_tmp;
  t_fils	fils;

  fils.right = NULL;
  fils.left = NULL;
  mpq_init(nbr);
  mpz_init(nbr_tmp);
  ungetc(c, fd);
  mpz_inp_str(nbr_tmp, fd, 10);
  mpq_set_z(nbr, nbr_tmp);
  return (create_node(NODE_NUM, 0, nbr, &fils));
}

t_node	*creat_op_node(char c)
{
  t_fils	fils;

  fils.right = NULL;
  fils.left = NULL;
  return (create_node(NODE_OP, c, NULL, &fils));
}

t_stack	*get_expr(t_stack *stack)
{
  char	c;

  while (1)
    {
      for (c = getc(stdin); (my_isspace(c)) && (c != EOF);)
	c = getc(stdin);
      if (c == EOF)
	return (stack);
      if (my_isdigit(c))
	push(&stack, get_number(stdin, c));
      else
	if (my_isop(c))
	  push(&stack, creat_op_node(c));
	else
	  errors(SYN_ERR_VAL);
      if (!my_isspace(c = getc(stdin)) && (c != EOF))
	errors(SYN_ERR_VAL);
      if (c == EOF)
	return (stack);
    }
}
