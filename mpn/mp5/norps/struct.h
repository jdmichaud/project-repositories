/*
** struct.h for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec  2 06:18:27 2001 jean-daniel michaud
** Last update Mon Dec  3 21:34:45 2001 jean-daniel michaud
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define	MAX_PARAMS	4

typedef enum	e_type
{
  VOID = 1,
  CHAR = 2,
  SHORT = 3,
  INT = 4,
  UCHAR = 5,
  USHORT = 6,
  UINT = 7,
  PCHAR = 8,
  RIEN = 9
}		t_type;

typedef union		u_value
{
  char			*ptr;
  char			c;
  short			s;
  int			i;
  unsigned char		uc;
  unsigned short	us;
  unsigned int		ui;
  char			*str;
}			t_value;

typedef struct	s_params
{
  t_type	rtype;
  int		nbparams;
  t_type	type[MAX_PARAMS];
  t_value	value[MAX_PARAMS];
}		t_params;

typedef struct	s_vars
{
  char		*name;
  t_value	value;
  t_type	type;
  struct s_vars	*next;
}		t_vars;

typedef struct	s_libs
{
  char		*name;
  char		*aliasname;
  void		*handle;
  struct s_libs	*next;
}		t_libs;

typedef struct	s_func
{
  int		(*f)(t_libs **libs, t_vars **vars, char **cmd);
}		t_func;

#endif
