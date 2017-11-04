/*
** is_func.h for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec  3 22:28:08 2001 jean-daniel michaud
** Last update Mon Dec  3 23:10:15 2001 jean-daniel michaud
*/

#ifndef IS_FUNC_H_
# define IS_FUNC_H_

int	is_func_with_var(t_libs *libs, char *cmd);
int	is_func_with_libs(t_libs *libs, char *cmd);
int	is_func_with_type(t_libs *libs, char *cmd);

#endif
