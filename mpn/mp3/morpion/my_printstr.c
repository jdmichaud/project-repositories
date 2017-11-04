/*
** my_printstr.c for my_printstr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:45:20 2001 jean-daniel michaud
** Last update Sun Nov  4 19:07:32 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <stdarg.h>

#include "my_printstr.h"
#include "my_printchar.h"

int	my_printstr(va_list *arg)
{
  int	cpt;
  char	*str;

  str = va_arg(*arg, char *);
  cpt = 0;
  while (str[cpt] != 0)
    {
      my_printchar(str[cpt]);
      ++cpt;
    }
  return (cpt);
}
