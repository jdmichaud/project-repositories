/*
** list_args.h for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 14 15:15:56 2001 jean-daniel michaud
** Last update Fri Nov 16 22:14:15 2001 jean-daniel michaud
*/

#ifndef LIST_ARGS_H_
# define LIST_ARGS_H_

struct			s_list_args
{
  char			*name;
  DIR			*dir;
  int			is_file;
  t_list_file		*link;
  struct s_list_args	*next;
};

typedef struct s_list_args	t_list_args;

void		add_file(t_list_args **list, char *name);
void		add_dir(t_list_args **list, DIR *dir, char *name);
void		free_list_args(t_list_args **list);
void		ls_on_dir(t_list_args *list);
void		add_dir_end(t_list_args **list, DIR *dir, char *name);

#endif
