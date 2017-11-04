/*
** init.h for my_tiny_printf in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov  4 19:03:40 2001 jean-daniel michaud
** Last update Sun Nov  4 19:25:13 2001 jean-daniel michaud
*/

#ifndef __INIT_H_
# define __INIT_H_

struct	s_func
{
  int	(*f)(va_list *arg);
};

typedef struct s_func	t_func;

static  t_func	tab[] = 
{
  {0},
  {my_printnbr},
  {my_printnbr_unsigned},
  {my_printstr},
  {my_printchar_from_arg},
};

#endif
