/*
** dbg_parse.h for  in 
** 
** Made by romain bottier
** Login   <bottie_r@epita.fr>
** 
** Started on  Fri Jan 11 16:09:16 2002 romain bottier
** Last update Fri Jan 11 16:17:36 2002 romain bottier
*/

#ifndef DBG_PARSE_H_
# define  DBG_PARSE_H_

typedef enum	e_error
{
  ERR_NBARGS	= 1,
  ERR_UNKCMD	= 2
}		t_error;

typedef		void	(*t_excmd)(t_vm *, t_list *);

typedef struct	s_cmd
{
  char		*name;
  char		*alias;
  unsigned int	nb_args[3];
  char		*help;
  t_excmd	cmd;
}		t_cmd;

char			*cmd_gettk(char **s);
unsigned int		test_cmd(char *cmd, unsigned int i);
unsigned int		test_args(char *cmd, t_list *list, unsigned int *idx);
void			cmd_parseline(t_vm *v, char *s);

#endif /* DBG_PARSE_H_ */
