/*
** get_number.c for get_number in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 16:15:54 2001 jean-daniel michaud
** Last update Sun Oct  7 23:19:56 2001 jean-daniel michaud
*/

#include "eval_expr.h"

char		*get_number(char **str)
{
  char		*s;
  int		i;

  s = *str;
  for (i = 0; my_is_digit(s[i]); i++)
    ;
  if (i == 0)
    return (NULL);
  s = malloc(i * sizeof (char));
  for (i = 0; my_is_digit(**str); ++i, ++(*str)) 
    s[i] = **str;
  s[i] = '\0';
  return (s);
}
