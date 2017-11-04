/*
** list_env_var.h for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Fri Dec  7 21:43:00 2001 Actarus Acta
** Last update Mon Dec 31 13:03:33 2001 jonathan mimouni
*/

#ifndef _LIST_CMD_H_
# define _LIST_CMD_H_

struct				s_list_cmd
{
  char				*cmd;
  int				separator;
  struct s_list_cmd		*next;
};

typedef struct s_list_cmd	t_list_cmd;

void			list_cmd_append(t_list_cmd **list, char *cmd, int sep);
void			list_cmd_free(t_list_cmd **list);
void			list_cmd_print(t_list_cmd *list);

#endif
