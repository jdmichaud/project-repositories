/*
** my_cat.c for my_cat in ~/c/rendu/exos/cat/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 16:58:13 2001 jean-daniel michaud
** Last update Wed Oct 10 16:14:32 2001 jean-daniel michaud
*/

#include "my_cat.h"

int	cat(char *file)
{
  int	fd;
  char	c;

  if (file != NULL)
    {
      fd = open(file, O_RDONLY, 755);
      if (!fd)
	{
	  write(2, "erreur", 7);
	  exit (1);
	}
      while (read(fd, &c, READ_SIZE))
	write(1, &c, READ_SIZE);
    }
  else
    while (read(0, &c, READ_SIZE))
      write(1, &c, READ_SIZE);
  return (0);
}

int	catb(char *file)
{
  return (0);
}

int	cate(char *file)
{
  return (0);
}

int	call(char *file, char c)
{
  if (c == 'b')
    catb(file);
  else
    if (c == 'n')
      catn(file);
    else 
      if (c == 'e')
	cate(file);
      else 
	if (c == 'f')
	  catf(file);
	else 
	  if (c == 's')
	    cats(file);
	  else 
	    if (c == 't')
	      catt(file);
	    else 
	      if (c == 'u')
		catu(file);
	      else 
		cat(file);
  return (0);
}

int	main(int argc, char *argv[])
{
  int	i;
  char	c;

  c = '\0';
  for (i = 1; argv[i][0] == '-'; ++i)
    {
      if ((argv[i][1] == 'b') || (argv[i][1] == 'e') || (argv[i][1] == 'f') ||
	  (argv[i][1] == 'n') || (argv[i][1] == 's') || (argv[i][1] == 't') ||
	  (argv[i][1] == 'u') || (argv[i][1] == 'v'))
	c = argv[i][1];
      else
	{
	  write(2, "erreur", 7);
	  exit (1);
	}
    }
  call(argv[i], c);
  return (0);
}

	
       








