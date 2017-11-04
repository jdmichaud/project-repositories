/*
** list_apply.c for list_apply in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:00:41 2001 jean-daniel michaud
** Last update Wed Oct  3 21:38:38 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_apply(t_dlist *dlist, void (*f)(void *))
{
  for (; dlist != 0; dlist = dlist->next)
    f(dlist->elem);
}
