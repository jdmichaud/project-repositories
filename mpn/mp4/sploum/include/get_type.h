/*
** get_type.h for mini-ls in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov 14 15:45:31 2001 jean-daniel michaud
** Last update Wed Nov 14 15:56:12 2001 jean-daniel michaud
*/

#ifndef GET_TYPES_H_
# define GET_TYPES_H_

int	is_file(char *path);
int	is_directory(char *path);
int	is_link(char *path);

#endif
