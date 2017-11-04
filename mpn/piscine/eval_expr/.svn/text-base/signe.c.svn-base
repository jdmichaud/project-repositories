/*
** signe.c for signe in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 16:01:22 2001 jean-daniel michaud
** Last update Sun Oct  7 17:53:18 2001 jean-daniel michaud
*/

#include "eval_expr.h"

int	signe(char **str)
{
  int	j;
  
  j = 1;
  while ((**str == '-') || (**str == '+'))
    {
      if (**str == '-')
	j *= -1;
      ++(*str);
    }
  return (j);
}
