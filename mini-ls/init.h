/*
** init.h for my_tiny_printf in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov  4 19:03:40 2001 jean-daniel michaud
** Last update Mon Nov 19 21:32:30 2001 jean-daniel michaud
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
  {my_printfnbr},
  {my_printfnbr_unsigned},
  {my_printfstr},
  {my_printfchar_from_arg},
};

#endif
