/*
** dlist_free_from_list.c for vm in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Jan  6 10:52:00 2002 jean-daniel michaud
** Last update Fri Jan 11 20:02:51 2002 jean-daniel michaud
*/

#include <stdio.h>

#include "dlist.h"

int	dlist_eq(void *e1, void *e2);

int	dlist_eq(void *e1, void *e2)
{
  return (e1 != e2);
}

void		dlist_free_from_list(t_dlist **list, t_dlist *from)
{
  t_dlist	*save;
  
  if (from)
    {
      save = from->next;
      while (from)
	{
	  dlist_rm_on_eq(list, from->elem, dlist_eq);
	  from = save;
	  if (save)
	    save = save->next ;
	}
    }
}
