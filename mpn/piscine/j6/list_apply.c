/*
** list_apply.c for list_apply in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:00:41 2001 jean-daniel michaud
** Last update Tue Oct  2 22:04:12 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void		list_apply(t_list **list, void (*f)(void *))
{
  t_list	*l;

  for (l = *list; l != NULL; l = l->next)
    f(l->elem);
}
