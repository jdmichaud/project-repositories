/*
** my_ctype.h for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 19:05:50 2001 jean-daniel michaud
** Last update Sun Dec  2 15:45:31 2001 jean-daniel michaud
*/

#ifndef CTYPE_H_
# define CTYPE_H_

int	is_libs(t_libs *libs, char *name);
int	is_vars(t_vars *vars, char *name);
int	is_id(char *id);
int	is_func(t_libs *libs, char *cmd);
int	is_type(char *id);

#endif
