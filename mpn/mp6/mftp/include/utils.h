/*
** utils.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec 16 17:46:46 2001 jean-daniel michaud

*/

#ifndef UTILS_H_
# define UTILS_H_

char	*getip(int whence);
char    *itoa(int nbr);
char	*port2char(int pport);
int     nbrlen(int nbr);
int	char2port(char *pport);
int	isregexp(char *str);
void    strup(char *dest, char *src);
char	**complete(char **argv);

#endif
