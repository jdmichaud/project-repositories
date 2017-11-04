/*
** tree.h for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Oct 26 00:00:26 2001 Jean-Daniel Michaudf
** Last update Mon Oct 29 17:49:15 2001 jean-daniel michaud
*/

#ifndef __TREE_H
# define __TREE_H

/*
** Definiion dy type t_node
*/

enum	e_type
{
  NODE_OP,
  NODE_NUM
};

typedef enum e_type	t_type;

struct			s_op_node
{
  char			c;
  struct s_node		*left;
  struct s_node		*right;
};

typedef struct s_op_node	t_op_node;

struct	s_num_node
{
  mpq_t	value;  
};

typedef struct s_num_node	t_num_node;

union		u_node
{
  t_op_node	op;
  t_num_node	num;
};

typedef union u_node	t_node_u;

struct		s_node
{
  t_type	type;
  t_node_u	elm;
};

typedef struct s_node	t_node;

struct		s_fils
{
  t_node	*right;
  t_node	*left;
};

typedef struct s_fils	t_fils;

/*
** Definitions des fonctions du type t_tree
*/

void	free_node(t_node *node);
t_node	*create_node(t_type type, char c, mpq_t num, t_fils *fils);
void	show_tree(t_node *tree, FILE* fd);
mpq_t	*calc_tree(t_node *tree);

#endif



