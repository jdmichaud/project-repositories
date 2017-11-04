/*
** my_atoi.h for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Nov 11 13:51:00 2001 jean-daniel michaud
** Last update Mon Nov 12 11:12:48 2001 jean-daniel michaud
*/

#ifndef MY_ATOI_H_
# define MY_ATOI_H_

#define	MAX_SPEC	11

int	my_atoi(char *str);
char	my_dtoc(long int i);
int	is_spec(char c);
char	*my_strcat(char *s, char *append);

#endif
