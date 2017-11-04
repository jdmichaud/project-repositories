/*
** bistromathique.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 16:48:23 2001 jean-daniel michaud
** Last update Sun Oct 21 19:30:19 2001 jonathan mimouni
*/

#ifndef __BISTRO_H_
# define __BISTRO_H_

struct				s_pile_op
{
  struct s_pile_op		*next;
  char				elem;
};
typedef struct s_pile_op	t_pile_op;

struct				s_pile_str
{
  struct s_pile_str		*next;
  char				*elem;
};
typedef struct s_pile_str	t_pile_str;

struct			s_list
{
  struct s_list		*next;
  char			elem;
};

typedef struct s_list	t_list;

struct			s_rules
{
  int			len_base;
  int			len_expr;
  t_list		*(tab_errors[4]);
  char			*op;
  char			*base;
  char			*expr;
  char			*save_expr;
  int			nb_par;
};

typedef struct s_rules	t_rules;

void		bistro(t_rules rules, char *expr);

#endif /* !__BISTRO_H_ */



