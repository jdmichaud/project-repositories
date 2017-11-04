/*
** print.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 17:08:41 2001 jean-daniel michaud
** Last update Sun Oct 21 16:54:17 2001 jonathan mimouni
*/

#include <unistd.h>
#include "bistromathique.h"
#include "print.h"

void    my_printchar(char c)
{
  write(1, &c, 1);
}

void	my_printstr(char *str)
{
  int	i;

  for (i = 0; str[i] != '\0'; ++i)
      my_printchar(str[i]);
}

