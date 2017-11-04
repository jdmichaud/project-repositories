/*
** list_put.c for list_put in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 20:40:22 2001 jean-daniel michaud
** Last update Sun Oct  7 15:23:18 2001 jean-daniel michaud
*/

#include "list.h"

void	*malloc(unsigned int);

void	list_put(t_list **list, int fd, void *elem)
{
  t_list	*l;

  if ((l = malloc (sizeof (t_list))) == NULL)
    return;
  l->elem = elem;
  l->fd = fd;
  l->next = *list;
  *list = l;
}
