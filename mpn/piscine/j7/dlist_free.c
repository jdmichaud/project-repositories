/*
** list_free.c for list_free in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 23:58:37 2001 jean-daniel michaud
** Last update Wed Oct  3 23:47:42 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	free(void *);

void		dlist_free(t_dlist **dlist)
{
  t_dlist	*l;

  l = *dlist;
  while (l)
    {
      l = l->next;
      free(l->prev);
    }
  *dlist = 0;
}
