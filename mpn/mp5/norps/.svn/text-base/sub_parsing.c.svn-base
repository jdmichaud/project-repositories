/*
** sub_parsing.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 00:32:10 2001 jean-daniel michaud
** Last update Tue Dec  4 03:29:35 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "list.h"
#include "parse_func.h"
#include "sub_parsing.h"

char		*gnw(char **cmd)
{
  if (**cmd)
    {
      nospace(cmd);
      if (**cmd == '\"')
	return (pstring(cmd));
      return (get_next_word(cmd));
    }
  return (NULL);
}

char		*pstring(char **cmd)
{
  t_list	*list;
  char		c;
  
  list = NULL;
  push (&list, '\"');
  (c = *(*cmd)++);
  do
    {
      while ((c = *(*cmd)++) != '\"')
	{
	  if (c == '\n')
	    push(&list, 10);
	  else
	    if (c == '\"')
	      push(&list, '\"');
	    else
	      push(&list, c);
	}
    }  while ((*(*cmd - 2)) == '\\');
  push(&list, c);
  c = *(*cmd)++;
  return (collapse(list));
}
