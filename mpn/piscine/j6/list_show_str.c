/*
** list_show_str.c for list_show_str in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct  3 00:36:20 2001 jean-daniel michaud
** Last update Wed Oct  3 00:39:52 2001 jean-daniel michaud
*/

#include "list.h"
#define NULL	0

void	list_show_str(t_list *list)
{
  for (; list != NULL; list = list->next)
    my_printstr(list->elem);
}
