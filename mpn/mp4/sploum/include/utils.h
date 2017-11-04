/*
** utils.h for sploum in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 23 22:18:29 2001 jean-daniel michaud
** Last update Mon Nov 26 14:57:20 2001 jean-daniel michaud
*/

#ifndef UTILS_H_
# define UTILS_H_

int	getmax(t_file *file);
int	my_nbrlen(int nbr);
char	*dec2hex(int nbr);
void	help(int whence);
void	my_getstr(char *str);

#endif
