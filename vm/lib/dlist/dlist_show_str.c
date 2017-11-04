/*
** dlist_show_str.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 21:25:13 2001 GIZMO
** Last update Thu Oct  4 00:38:53 2001 GIZMO
*/

#include <unistd.h>
#include "dlist.h"

void	my_printchar(char c);
void	my_printstr(char *str);

void		dlist_show_str(t_dlist *dlist)
{
  t_dlist	*tmp;

  tmp = dlist;
  while (tmp != 0)
    {
      my_printstr(tmp->elem);
      tmp = tmp->next;
    }
}




