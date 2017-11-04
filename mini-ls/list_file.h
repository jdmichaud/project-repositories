/*
** list.h for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 31 12:29:29 2001 jean-daniel michaud
** Last update Tue Nov 20 01:46:55 2001 jean-daniel michaud
*/

#ifndef __LIST_FILE_H_
# define __LIST_FILE_H_

#define	NORMAL	1
#define	HIDDEN	2
#define	SPEC	4

struct			s_list_file
{
  char			*name;
  char			*path;
  struct stat		*sb;
  char			*owner;
  char			*group;
  /*
  mode_t		type;
  int			nlink;
  time_t		date;
  unsigned int		size;
  unsigned int		blocks;
  */
  struct s_list_file	*next;
};

typedef struct s_list_file	t_list_file;

void		free_list(t_list_file **list);
void		put_in_sort_list(t_list_file **list, t_list_file *elem);
void		add(t_list_file	**list, 
		    struct stat	*sb, 
		    char	*name, 
		    char	*path);
void		free_list_file(t_list_file **file);

#endif
