/*
** list_put.c for list_put in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 20:40:22 2001 jean-daniel michaud
** Last update Thu Oct  4 01:46:55 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void	dlist_put(t_dlist **dlist, void *elem)
{
  t_dlist	*l;

  if (!dlist)
    return;
  l = *dlist;
  if (((*dlist) = malloc (sizeof (t_dlist))) == 0)
    return;
  (*dlist)->elem = elem;
  (*dlist)->next = l;
  (*dlist)->prev = 0;
  if (l)
    l->prev = *dlist;
}
