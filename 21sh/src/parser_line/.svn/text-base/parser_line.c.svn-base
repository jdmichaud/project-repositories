/*
** parser.c for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Tue Dec 11 20:24:59 2001 Actarus Acta
** Last update Mon Dec 31 03:24:15 2001 jonathan mimouni
*/

#include <stdlib.h>
#include <ctype.h>
#include "list_cmd.h"
#include "parser_line.h"
#include "eat.h"
#include "eat2.h"
#include "my_malloc.h"

static int	(*f[7])(int *nb_malloc, int *i, char **line, char **cmd) =
{
  eat_dot_comma,
  eat_esperluet,
  eat_pipe,
  eat_quote,
  eat_double_quote,
  eat_backquote,
  eat_char
};

void		init_tabsep(char *tabsep)
{
  tabsep[0] = ';';
  tabsep[1] = '&';
  tabsep[2] = '|';
  tabsep[3] = '\'';
  tabsep[4] = '\"';
  tabsep[5] = '\\';
}

int		get_char_value(char c)
{
  int		i;
  char		tab_sep[6];

  init_tabsep(tab_sep);
  for (i = 0; (i < 6) && (c != tab_sep[i]); ++i)
    ;
  return (i);
}

int		get_next_cmd(t_list_cmd **list, char **p_line)
{
  char		*cmd;
  int		nb_malloc;
  int		i;
  int		char_value;
  int		sep;
  char		*line;
  
  cmd = my_malloc(CMD_SIZE);
  line = *p_line; 
  for (sep = 0, nb_malloc = 1, i = 0; ((*line != '\0') && (!sep)); ++i, ++line)
    {
      char_value = get_char_value(*line);
      if ((sep = f[char_value](&nb_malloc, &i, &line, &cmd)) == -1)
	{
	  free(cmd);
	  return (0);
	}
    }
  cmd[i] = '\0';
  if (sep == 0)
    char_value = -1;
  list_cmd_append(list, cmd, char_value);
  *p_line = line;
  return (1);
}

t_list_cmd	*parser_line(char *line)
{
  t_list_cmd	*list;

  list = NULL;
  while (*line != '\0')
    {
      for (; (isspace(*line)) && (*line != '\0'); ++line)
	;
      if (*line == '\0')
	return (list);
      else
	if (!get_next_cmd(&list, &line))
	  {
	    list_cmd_free(&list);
	    return (NULL);
	  }
    }
  return (list);
}


/* en sortie 

si la list est vide alors 
  si line[0] == '\0' alors
    rien faire
sinon
  si list->cmd[0] == ";"
    return (error_synthax(";"))
  sinon
    l'expression etait valide
*/
    
























































































































