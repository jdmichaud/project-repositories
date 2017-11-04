/*
** eat2.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Wed Dec 12 16:48:20 2001 jonathan mimouni
** Last update Thu Dec 13 12:55:25 2001 jonathan mimouni
*/

#include "list_cmd.h"
#include "parser_line.h"
#include "eat2.h"
#include "my_malloc.h"

int	eat_backquote(int *nb_malloc, int *i, char **line, char **cmd)
{
  eat_char(nb_malloc, i, line, cmd);
  ++(*line);
  if (*line == '\0')
    --(*line);
  else
    {
      ++(*i);
      eat_char(nb_malloc, i, line, cmd);
    }
  return (0);
}

int	eat_char(int *nb_malloc, int *i, char **line, char **cmd)
{
  if (*i < (*nb_malloc * CMD_SIZE - 1))
    (*cmd)[*i] = **line;
  else
    {
      (*nb_malloc)++;
      (*cmd)[*i] = '\0';
      *cmd = my_realloc(*cmd, *nb_malloc * CMD_SIZE);
      (*cmd)[*i] = **line;
    }
  return (0);
}
