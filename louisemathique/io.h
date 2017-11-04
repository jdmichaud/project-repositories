/*
** io.h for louisemathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 23:21:27 2001 Jean-Daniel Michaudf
** Last update Sun Oct 28 21:59:09 2001 jean-daniel michaud
*/

#ifndef __IO_H_
# define __IO_H_

t_node		*get_number(FILE *fd, char c);
t_node		*creat_op_node(char c);
t_stack		*get_expr(t_stack *stack);

#endif
