/*
** parser_list_cmd.h for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Dec 22 15:18:03 2001 jonathan mimouni
** Last update Mon Dec 31 13:09:31 2001 jonathan mimouni
*/

#ifndef _PARSER_LIST_CMD_H_
# define _PARSER_LIST_CMD_H_

struct				s_execute
{
  char				*id;
  int				(*f)(t_command *command);
};

typedef struct s_execute	t_execute;

#define NB_NON_PROCESS	9

int		parser_list_cmd(t_list_cmd *list_cmd);
int		exec(t_command *command);
int		exec_exit(t_command *command);
int		f_cd(t_command *command);
int		exec_env_var(t_command *command);
void		treat_quote(t_command *cmd);
t_list_cmd	*get_next_list_cmd(t_list_cmd *list_cmd, int err);
int		is_meta(char *);

#endif
