/*
** list_sort.c for list_sort in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 21:23:15 2001 jean-daniel michaud
** Last update Thu Oct  4 03:15:36 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_sort(t_dlist **dlist, t_cmpfunc cmp)
{
  t_dlist	*l;
  void		*tmp;
  int		stop;

  stop = 1;
  if (*dlist != 0)
    {
      while (stop)
	{
	  stop = 0;
	  for (l = *dlist; l->next != 0; l = l->next)
	    {
	      if (cmp(l->elem, l->next->elem) > 0)
		{
		  stop = 1;
		  tmp = l->elem;
		  l->elem = l->next->elem;
		  l->next->elem = tmp;
		}
	    }
	}
    }
}
