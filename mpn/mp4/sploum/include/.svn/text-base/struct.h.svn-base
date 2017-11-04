/*
** struct.h for  in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 22 17:31:31 2001 jean-daniel michaud
** Last update Tue Nov 27 15:32:08 2001 jean-daniel michaud
*/

#ifndef STRUCT_H_
# define STRUCT_H_

struct			s_file
{
  char		*name;
  int		size;
  struct stat	*sb;
  struct s_file	*next;
};
typedef struct s_file	t_file;

struct			s_dir
{
  char		*name;
  DIR		*dir;
  t_file	*files;
  int		actual;
  int		total;
  int		max_name_len;
  struct s_dir	*next;
};
typedef struct s_dir	t_dir;

typedef struct		s_curinfo
{
  int			fline;
  int			posx;
  int			posy;
  int			total;
  int			mode;
}			t_curinfo;

struct			s_win
{
  WINDOW		*w;
  t_dir			*content;
  unsigned char		**code;
  char			*filename;
  int			tag;
  t_curinfo		*info;
};
typedef struct s_win	t_win;

#endif
