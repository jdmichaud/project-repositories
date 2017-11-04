/*
** list_delhead.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Thu Dec 20 18:38:57 2001 julien gein
** Last update Thu Dec 20 18:41:27 2001 julien gein
*/

#include <stdlib.h>
#include "data_struct.h"

void	list_delhead(t_list **head, t_list *pos)
{
  t_list	*tmp;
  
  while (*head && *head != pos)
    {
      tmp = *head;
      *head = (*head)->next;
      free(tmp);
      tmp = 0;
    }
}
