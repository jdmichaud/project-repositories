/*
** my_printchar.c for my_printchar in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:40:49 2001 jean-daniel michaud
** Last update Sun Nov  4 19:07:06 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <stdarg.h>

#include "my_printchar.h"

int	my_printchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(-1);
  return (1);
}

int	my_printchar_from_arg(va_list *arg)
{
  char	c;
  
  c = va_arg(*arg, int);
  if (write(1, &c, 1) == -1)
    exit(-1);
  return (1);
}
