/*
** my_ctype.c for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct 28 17:45:35 2001 jean-daniel michaud
** Last update Sun Oct 28 22:50:43 2001 jean-daniel michaud
*/

#include "my_ctype.h"

int	my_isspace(char c)
{
  if ((c == 32) || (c == '\n') || (c == '\t')
      || (c == '\f') || (c == '\r') || (c == '\v'))
    return (1);
  return (0);
}

int	my_isdigit(char c)
{
  if ((c >= 48) && (c <= 57))
    return (1);
  return (0);
}

int	my_isop(char c)
{
  if ((c == '/') || (c == '*') || (c == '+') || (c == '-'))
    return (1);
  return (0);
}
