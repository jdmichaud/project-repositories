/*
** list_from_params.c for list_from_params in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 00:40:45 2001 jean-daniel michaud
** Last update Wed Oct  3 02:46:44 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void		list_from_params(t_list **list, int ac, char *av[])
{
  int		i;

  for (i = 0; i < ac; ++i)
      list_append(list, av[i]);
}

