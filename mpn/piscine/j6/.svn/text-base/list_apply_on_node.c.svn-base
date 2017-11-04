/*
** list_apply_on_node.c for list_apply_on_node in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 22:23:47 2001 jean-daniel michaud
** Last update Tue Oct  2 22:27:35 2001 jean-daniel michaud
*/

#include "list.h"
#define NULL	0

void	*malloc(unsigned int);

void		list_apply_on_node(t_list *list, void (*f)(t_list *))
{
  for (; list != NULL; list = list->next)
    f(list);
}
