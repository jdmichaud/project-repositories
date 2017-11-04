/*
** my_cat2.c for my_cat in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 10 15:23:58 2001 jean-daniel michaud
** Last update Wed Oct 10 16:17:09 2001 jean-daniel michaud
*/

#include "my_cat.h"

int	cats(char *file)
{
  return (0);
}

int	catt(char *file)
{
  return (0);
}

int	catu(char *file)
{
  return (0);
}

int	catv(char *file)
{
  return (0);
}

int	catn(char *file)
{
  int i;
  int	fd;
  char	c;

  i = 0;
  if (file != NULL)
    {
      fd = open(file, O_RDONLY, 755);
      if (!fd)
	{
	  write(2, "erreur", 7);
	  exit (1);
	}
      while (read(fd, &c, READ_SIZE))
	{
	  write(1, &c, READ_SIZE);
	  if (c == '\n')
	    {
	      my_printnbr(++i);
	      my_printchar(' ');
	    }	      
	}
    }
  else
    while (read(0, &c, READ_SIZE))
      write(1, &c, READ_SIZE);
  return (0);

  
}

