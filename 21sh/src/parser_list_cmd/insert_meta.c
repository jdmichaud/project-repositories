/*
** insert_meta.c
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 31 07:11:49 2001 Florent Monbillard
** Last update Mon Dec 31 11:43:54 2001 Florent Monbillard
*/

#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "meta.h"
#include "xmalloc.h"
#include "insert_meta.h"

char	**xmetachar(t_command *cmd, int pos)
{
  char	**tmp;

  if ((tmp = metachar(cmd->argv[pos])) == NULL)
    {
      tmp = xmalloc(2 * sizeof (char *));
      tmp[0] = strdup(cmd->argv[pos]);
      tmp[1] = NULL;
    }
  return (tmp);
}

int	insert_meta_in_cmd(t_command *cmd, int pos)
{
  char	**res;
  char	**tmp;
  int	i;
  int	len;
  int	j;

  tmp = xmetachar(cmd, pos);
  for (i = 0; (tmp) && (tmp[i] != NULL); ++i)
    ;
  len = i + cmd->argc - 1;
  for (i = 0, res = xmalloc(sizeof (char *) * (len + 1)); i < pos; ++i)
    res[i] = strdup(cmd->argv[i]);
  for (j = 0; (tmp) && (j < (len - cmd->argc + 1)); ++j)
    res[i++] = strdup(tmp[j]);
  for (j = pos + 1, pos = i - 1; j < cmd->argc; ++j)
    res[i++] = strdup(cmd->argv[j]);
  res[len] = NULL;
  for (i = 0; i < cmd->argc; ++i)
    free(cmd->argv[i]);
  for (i = 0; (tmp) && (tmp[i]); ++i)
    free(tmp[i]);
  my_free(cmd->argv, tmp, NULL, NULL);
  cmd->argv = res;
  cmd->argc = len;
  return (pos);
}
