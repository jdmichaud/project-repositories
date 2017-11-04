/*
** list_append.c for list_append in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 20:51:23 2001 jean-daniel michaud
** Last update Wed Oct  3 21:22:40 2001 jean-daniel michaud
*/


#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_append(t_dlist **dlist, void *elem)
{
  t_dlist	*l;

  if (*dlist == 0)
    {
      if ((*dlist = malloc(sizeof (t_dlist))) == 0)
	return;
      (*dlist)->next = 0;
      (*dlist)->elem = elem;
      (*dlist)->prev = 0;
    }
  else
    {
      for (l = *dlist; l->next != 0; l = l->next)
	;
      if ((l->next = malloc(sizeof (t_dlist))) == 0)
	return;
      l->next->next = 0;
      l->next->elem = elem;
      l->next->prev = l;
    }
}

