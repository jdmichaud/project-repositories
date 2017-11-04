/*
** my_showmem.c for my_showmem in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 23:18:34 2001 jean-daniel michaud
** Last update Fri Jan  4 11:14:11 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "my.h"

void		my_showmem(void *mem, unsigned int size)
{
  char		*str;
  char		c;
  unsigned int	cpt;
  unsigned int	i;

  str = mem;
  cpt = 0;
  for (i = 0; i < size; ++i)
    {
      if (cpt > 15)
	{
	  my_printchar('\n');
	  cpt = 0;
	}
      ++cpt;
      c = str[i];
      c &= 240;
      c /= 16;
      my_printnbr_base(c, "0123456789ABCDEF");
      c = str[i];
      c &= 15;
      my_printnbr_base(c, "0123456789ABCDEF");
      my_printchar(' ');
    }
  my_printchar('\n');
}




