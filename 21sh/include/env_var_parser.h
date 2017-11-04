/*
** env_var_parser.h for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Dec 29 19:43:10 2001 jonathan mimouni
** Last update Mon Dec 31 13:01:48 2001 jonathan mimouni
*/

#ifndef _ENV_VAR_PARSER_H_
# define _ENV_VAR_PARSER_H_

int	parser_env_var_set(t_command *cmd);
int	parser_env_var_export(t_command *cmd);
int	parser_env_var_unset(t_command *cmd);
int	format_env_var(t_command *cmd);

#endif
