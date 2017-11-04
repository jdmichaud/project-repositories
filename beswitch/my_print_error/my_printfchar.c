/*
** my_printchar.c for my_printchar in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:40:49 2001 jean-daniel michaud
** Last update Fri Nov  9 19:38:04 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#include "my_printfchar.h"

int	my_printechar(char c)
{
  if (write(2, &c, 1) == -1)
    exit(-1);
  return (1);
}

int	my_printechar_from_arg(va_list *arg)
{
  char	c;
  
  c = va_arg(*arg, int);
  if (write(2, &c, 1) == -1)
    exit(-1);
  return (1);
}
