/*
** dlist_from_params.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:27:38 2001 GIZMO
** Last update Thu Oct  4 00:36:28 2001 GIZMO
*/

#include "dlist.h"

void	dlist_from_params(t_dlist **dlist, int ac, char *av[])
{
  int	i;
  
  if (dlist)
    {
      for (i = ac - 1; i >= 0; i--)
	dlist_put(dlist, av[i]);
    }
}
