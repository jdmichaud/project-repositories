/*
** list_add_to_list.c for list_add_to_list in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:26:57 2001 jean-daniel michaud
** Last update Thu Oct  4 02:52:51 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void		dlist_add_to_dlist(t_dlist **dest, t_dlist *src)
{
  t_dlist	*l;

  if (*dest == 0)
    *dest = src;
  else
    {
      for (l = *dest; l->next != 0; l = l->next)
	;
      l->next = src;
      src->prev = l;
    }
}
