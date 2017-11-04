/*
** list_free.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Tue Oct  2 22:06:58 2001 julien gein
** Last update Wed Dec 19 12:04:54 2001 julien gein
*/

#include <stdlib.h>
#include "data_struct.h"

void		list_free(t_list **list)
{
  t_list	*tmp;
  
  while (*list)
    {
      tmp = *list;
      *list = (*list)->next;
      free(tmp);
      tmp = 0;
    }
}
