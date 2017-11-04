/*
** dlist_sort.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 20:52:08 2001 GIZMO
** Last update Thu Nov 29 15:08:04 2001 GIZMO
*/

#include "dlist.h"

void		dlist_sort(t_dlist **dlist, t_cmpfunc cmp)
{
  t_dlist	*tmp;
  t_dlist	*save;
  unsigned int	i;
  unsigned int	j;

  if (dlist)
    {
      tmp = *dlist;
      for (i = 1; i <= dlist_size(tmp); i++)
	for (j = 1; j <= i - 1; j++)
	  {
	    if (cmp(tmp->elem, tmp->next->elem) > 0)
	      {
		save = tmp->elem;
		tmp->elem = tmp->next->elem;
		tmp->next->elem = save;
	      }
	    dlist_sort(&(tmp->next), cmp);
	  }
      *dlist = tmp;
    }
} 
