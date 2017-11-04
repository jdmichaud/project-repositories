/*
** list_show_str.c for list_show_str in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 00:36:20 2001 jean-daniel michaud
** Last update Thu Oct  4 00:01:55 2001 jean-daniel michaud
*/

#include "list.h"
#include "dlist.h"

void	my_printstr(void *);

void	dlist_show_str(t_dlist *dlist)
{
  for (; dlist != 0; dlist = dlist->next)
    my_printstr(dlist->elem);
}
