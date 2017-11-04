/*
** list_apply_on_node.c for list_apply_on_node in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:23:47 2001 jean-daniel michaud
** Last update Wed Oct  3 21:52:48 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	*malloc(unsigned int);

void		dlist_apply_on_node(t_dlist *dlist, void (*f)(t_dlist *))
{
  for (; dlist != 0; dlist = dlist->next)
    f(dlist);
}
