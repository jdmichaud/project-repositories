/*
** eval_expr.c for eval_expr in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 15:56:56 2001 jean-daniel michaud
** Last update Sun Oct  7 23:22:51 2001 jean-daniel michaud
*/

#include "eval_expr.h"

int		eval_expr(char **str)
{
  int		a;
  int		op;
  t_pile	*pile;
  int		si;

  pile = NULL;
  a = push (&pile, signe(str) * my_atoi(get_number (str)));
  while (**str != '\0')
    {
      op = is_op(**str);
      for (; (((op == 1) || (op == 2)) && (**str != '\0'));
	   op = is_op(**str))
	{
	  if ((is_op((*str)[1])) == 5)
	    {
	      si = signe(str);
	      (*str)++;
	      a = push (&pile, si * eval_expr(str));      
	    }
	  else
	      a = push (&pile, signe(str) * my_atoi(get_number(str)));
	}
      for (; (((op == 3) || (op == 4) || (op == 7)) && (**str != '\0')); 
	   op = is_op(**str))
	{
	  if ((is_op((*str)[1])) == 5)
	    {
	      (*str)++;
	      if (op == 3)
		a = push (&pile, pop(&pile) * eval_expr(str));    
	      if (op == 4)
		a = push (&pile, pop(&pile) / eval_expr(str));    
	      if (op == 7)
		a = push (&pile, pop(&pile) % eval_expr(str));    
	    }
	  else
	    {
	      (*str)++;
	      si = signe(str);
	      if (op == 3)
		a = push (&pile, pop(&pile) * (si * my_atoi(get_number(str))));
	      if (op == 4)
		a = push (&pile, pop(&pile) / (si * my_atoi(get_number(str))));
	      if (op == 7)
		a = push (&pile, pop(&pile) % (si * my_atoi(get_number(str))));
	    }
	}
      if (op == 6)
	{
	  (*str)++;
	  return (collapse(pile));
	}
      if (op == 5)
	{
	  (*str)++;
	  push(&pile, eval_expr(str));
	}
    }
  return (collapse(pile));
}
