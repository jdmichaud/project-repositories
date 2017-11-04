/*
** libs.h for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:16:37 2001 jean-daniel michaud
** Last update Sun Dec  2 14:26:27 2001 jean-daniel michaud
*/

#ifndef LIBS_H_
# define LIBS_H_

void	add(t_libs **libs, char *name, char *aliasname);
void	del(t_libs **libs, char *aliasname);
int	show_libs(t_libs **libs, t_vars **vars, char **cmd);
void	free_libs(t_libs *lib);
t_vars	*callf(t_libs	*libs, 
	       char	*aliasname, 
	       char	*funcname, 
	       t_params	*params);

#endif
