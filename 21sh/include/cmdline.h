/*
** cmdline.h for  in 
** 
** Made by Jeremy AMSELLEM
** Login   <jeremy@epita.fr>
** 
** Started on  Wed Dec 12 14:01:04 2001 Jeremy AMSELLEM
** Last update Mon Dec 31 02:41:52 2001 jean-daniel michaud
*/

#ifndef __CMDLINE_H_
# define __CMDLINE_H_

#include "struct.h"

struct			s_line
{
  char			*commande;
  struct s_line		*next;
};
typedef struct s_line	t_line;


t_line		*do_list_cmd(char *line);
t_line		*get_next_word(char *str, int *j);
void		kill_space(char *str, int *j);
void		print_list(t_line *line);
void		push(t_line *temp, t_line *the_line);
void		free_t_line(t_line **line);
void		look_guill(char *old_line, int i, t_guill *guill);
char		*redo_line_ou(char *old_line, t_guill *guill);
t_line		*do_comment(char *str, int *i, char c);
t_command	*do_struct(t_line *line);

#endif
