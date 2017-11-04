/*
** my_is_digit.c for my_is_digit in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 16:08:10 2001 jean-daniel michaud
** Last update Sun Oct  7 16:10:24 2001 jean-daniel michaud
*/

#include "eval_expr.h"

unsigned int	my_is_digit(char c)
{
  if ((c > 47) && (c < 58))
    return (1);
  return (0);
}
