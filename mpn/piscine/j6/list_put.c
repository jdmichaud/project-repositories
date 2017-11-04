/*
** list_put.c for list_put in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 20:40:22 2001 jean-daniel michaud
** Last update Wed Oct  3 01:44:10 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void	list_put(t_list **list, void *elem)
{
  t_list	*l;

  if ((l = malloc (sizeof (t_list))) == NULL)
    return;
  l->elem = elem;
  l->next = *list;
  *list = l;
}
