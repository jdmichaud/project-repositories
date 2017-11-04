/*
** list_append.c for list_append in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 20:51:23 2001 jean-daniel michaud
** Last update Wed Oct  3 01:59:15 2001 jean-daniel michaud
*/


#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void		list_append(t_list **list, void *elem)
{
  t_list	*l;

  if (*list == NULL)
    {
      if ((*list = malloc(sizeof (t_list))) == NULL)
	return;
      (*list)->next = NULL;
      (*list)->elem = elem;
    }
  else
    {
      for (l = *list; l->next != NULL; l = l->next)
	;
      if ((l->next = malloc(sizeof (t_list))) == NULL)
	return;
      l->next->next = NULL;
      l->next->elem = elem;
    }
}

