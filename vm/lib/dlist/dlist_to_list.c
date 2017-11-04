/*
** dlist_to_list.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Oct  3 23:45:27 2001 GIZMO
** Last update Sun Jan  6 17:37:04 2002 jean-daniel michaud
*/

#include <stdlib.h>
#include "dlist.h"

t_list		*dlist_to_list(t_dlist *list)
{
  t_list	*liste;
  
  liste = 0;
  while (list != 0)
    {
      list_append(&liste, list->elem);
      list = list->next;
    }
  return (liste);
}
