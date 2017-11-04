/*
** list_put_in_sortlist.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Tue Oct  2 23:16:31 2001 jonathan mimouni
** Last update Thu Dec 13 10:50:00 2001 jonathan mimouni
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_cmd.h"
#include "my_malloc.h"
#include "errors.h"

void		list_cmd_append(t_list_cmd **list, char *cmd, int sep)
{
  t_list_cmd	*p;
  
  if (*list == NULL)
    {
      *list = my_malloc(sizeof (t_list_cmd));
      (*list)->cmd = cmd;
      (*list)->separator = sep;
      (*list)->next = NULL;
    }
  else
    {
      p = *list;
      while (p->next != NULL)
	p = p->next;
      p->next = my_malloc(sizeof (t_list_cmd));
      p->next->cmd = cmd;
      p->next->separator = sep;
      p->next->next = NULL;
    }
}

void		list_cmd_free(t_list_cmd **list)
{
  t_list_cmd	*p;
  t_list_cmd	*prec;
  
  p = *list;
  while (p != NULL)
    {
      prec = p;
      p = p->next;
      free(prec);
    }
  *list = NULL;
}

void	list_cmd_print(t_list_cmd *list)
{
  int	i;
  char	*sep[3] = {";", "&&", "||"};

  for (i = 0; list != NULL; list = list->next, ++i)
    {
      if (list->cmd[0] == '\0')
	error_syntax(';', 0);
      else
	{
	  printf("cmd %d: %s\n", i, list->cmd);
	  if (list->separator != -1)
	    printf("separator: %s\n", sep[list->separator]);
	}
    }
}
