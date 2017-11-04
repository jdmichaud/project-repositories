/*
** eval_expr.h for eval_expr in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct  7 15:57:13 2001 jean-daniel michaud
** Last update Sun Oct  7 23:22:03 2001 jean-daniel michaud
*/

#ifndef	__EVALEXPR_H_
#define	__EVALEXPR_H_

#include <stdlib.h>
#include <unistd.h>

struct		pile
{
  int		val;
  struct pile	*next;
};

typedef struct pile	t_pile;

int		eval_expr(char **str);
int		signe(char **str);
unsigned int	is_op(char c);
unsigned int	my_is_digit(char c);
int		my_atoi(char *str);
char		*get_number(char **str);

/*
** Pour les piles
*/

int		push(t_pile **p, int a);
int		pop(t_pile **p);
int		collapse(t_pile *p);

void		my_printnbr(int nbr);
void		my_printdigit(int d);
void		my_printchar(char c);

#endif

