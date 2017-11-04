/*
** my_printstr.c for my_printstr in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:45:20 2001 jean-daniel michaud
** Last update Fri Nov  9 19:36:41 2001 jean-daniel michaud
*/

#include <unistd.h>
#include <stdarg.h>

#include "my_printfstr.h"
#include "my_printfchar.h"

int	my_printestr(va_list *arg)
{
  int	cpt;
  char	*str;

  str = va_arg(*arg, char *);
  cpt = 0;
  while (str[cpt] != 0)
    {
      my_printechar(str[cpt]);
      ++cpt;
    }
  return (cpt);
}
