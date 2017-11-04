/*
** list_from_params.c for list_from_params in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 00:40:45 2001 jean-daniel michaud
** Last update Thu Oct  4 03:15:36 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_from_params(t_dlist **dlist, int ac, char *av[])
{
  int		i;

  for (i = 0; i < ac; ++i)
      dlist_append(dlist, av[i]);
}

