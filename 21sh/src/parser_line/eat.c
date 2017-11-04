/*
** eat.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Wed Dec 12 16:48:10 2001 jonathan mimouni
** Last update Mon Dec 31 09:47:31 2001 jonathan mimouni
*/

#include "list_cmd.h"
#include "parser_line.h"
#include "eat.h"
#include "eat2.h"
#include "errors.h"

int	eat_dot_comma(int *nb_malloc, int *i, char **line, char **cmd)
{
  **line = **line;
  **cmd = **cmd;
  *nb_malloc = *nb_malloc;
  (*i)--;
  return (1);
}

int	eat_esperluet(int *nb_malloc, int *i, char **line, char **cmd)
{
  char	*str;
  int	next;
  char	tab_sep[6];
  
  init_tabsep(tab_sep);
  str = *line;
  ++str;
  next = get_char_value(*str);
  if (next != NON_SEP)
    {
      ++(*line);
      --(*i);
      if (next == ESPERLUET)
	{
	  ++str;
	  next = get_char_value(*str);
	  if (next == NON_SEP)
	    return (1);
	  else
	    return (error_syntax(tab_sep[next], -1));
	}
      else
	return (error_syntax(tab_sep[next], -1));
    }
  return (eat_char(nb_malloc, i, line, cmd));
}

int	eat_pipe(int *nb_malloc, int *i, char **line, char **cmd)
{
  char	*str;
  int	next;
  char	tab_sep[6];
  
  init_tabsep(tab_sep);
  str = *line;
  ++str;
  next = get_char_value(*str);
  if (next != NON_SEP)
    {
      ++(*line);
      --(*i);
      if (next == PIPE)
	{
	  ++str;
	  next = get_char_value(*str);
	  if (next == NON_SEP)
	    return (1);
	  else
	    return (error_syntax(tab_sep[next], -1));
	}
      else
	return (error_syntax(tab_sep[next], -1));
    }
  return (eat_char(nb_malloc, i, line, cmd));
}

int	eat_quote(int *nb_malloc, int *i, char **line, char **cmd)
{
  eat_char(nb_malloc, i, line, cmd);
  ++(*i);
  ++(*line);
  for (; (**line != '\''); ++(*i), ++(*line))
    if (**line == '\\')
      {
	eat_char(nb_malloc, i, line, cmd);
	++(*i);
	++(*line);
      }
    else
      eat_char(nb_malloc, i, line, cmd);
  eat_char(nb_malloc, i, line, cmd);
  return (0);
}

int	eat_double_quote(int *nb_malloc, int *i, char **line, char **cmd)
{
  eat_char(nb_malloc, i, line, cmd);
  ++(*i);
  ++(*line);
  for (; (**line != '\"'); ++(*i), ++(*line))
    if (**line == '\\')
      {
	eat_char(nb_malloc, i, line, cmd);
	++(*i);
	++(*line);
      }
    else
      eat_char(nb_malloc, i, line, cmd);
  eat_char(nb_malloc, i, line, cmd);
  return (0);
}
