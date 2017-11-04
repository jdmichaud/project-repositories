/*
** struct.h for 21sh in ~/c/rendu/projs/21sh
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 09:52:14 2001 jean-daniel michaud
** Last update Mon Dec 31 11:11:11 2001 jonathan mimouni
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include "list.h"

typedef void		(*t_handler)(int nsig);

typedef struct		s_command
{
  int			argc;
  char			*infile;
  char			*outfile;
  char			*errfile;
  int			append;
  char			**argv;
  int			separator;
  int			background;
  struct s_command	*next;
}			t_command;

typedef struct	s_cmdline
{
  char		*line;
  t_command	*list_cmd;
}		t_cmdline;

typedef struct		s_process
{
  int			id;
  int			pid;
  int			fd_in;
  int			fd_out;
  int			fd_err;
  int			status;
  int			suspended;
  int			background;
  int			where_is_the_pipe;
  int			argc;
  char			**argv;
  struct s_process	*fils;
  struct s_process	*next;
}			t_process;

typedef struct		s_glprocess 
{ 
  t_list		*process; 
  int			laststatus; 
}			t_glprocess; 

typedef struct	s_shell
{
  char		*prompt;
  char		*command;
  t_process	*process;
}		t_shell;

#endif
