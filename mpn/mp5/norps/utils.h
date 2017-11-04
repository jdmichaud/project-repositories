/*
** utils.h for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 12:29:21 2001 jean-daniel michaud
** Last update Mon Dec  3 21:35:49 2001 jean-daniel michaud
*/

#ifndef UTILS_H_
# define UTILS_H_

char	*make_filename(char *name);
int	stop(t_libs **libs, t_vars **vars, char **cmd);
int	isnumber(char *str);
t_vars	*affect(t_params *params, long int r);

#endif
