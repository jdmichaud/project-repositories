/*
** historic.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec 30 23:30:33 2001 jean-daniel michaud
** Last update Mon Dec 31 13:50:44 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "init_termcap.h"
#include "historic.h"
#include "xmalloc.h"

static t_list	*list = NULL;

int		load_historic(char *file)
{
  char		*cmd;
  FILE		*f;

  if ((f = fopen(file, "r")) == NULL)
    return (0);
  while (!feof(f))
    {
      cmd = xmalloc(LENGTH_MALLOC * sizeof (char));
      fgets(cmd, LENGTH_MALLOC, f);
      qadd(&list, cmd);
    }
  fclose(f);
  return (0);
}

int	save_historic(char *file)
{
  FILE	*f;

  if ((f = fopen(file, "w+")) == NULL)
    return (1);
  while (list)
    {
      fputs(list->elem, f);
      fputc('\n', f);
      list = list->next;
    }
  fclose(f);
  return (0);
}

char		*get_entry(int whence)
{
  static t_list	*current;
  t_list	*tmp;
  char		*cmd;

  cmd = NULL;
  if (!whence)
    for (tmp = list, current = list; tmp && tmp->next; current = tmp)
      tmp = tmp->next;
  else
    if (current)
      {
	if (whence == 1)
	  {
	    cmd = current->elem;
	    if (current->prec)
	      current = current->prec;
	  }
	else
	  if (current->next)
	    {
	      current = current->next;
	      cmd = current->elem;
	    }
      }
  return (cmd);
}

int		hiadd(char *cmd)
{
  qadd(&list, cmd);
  return (0);
}
