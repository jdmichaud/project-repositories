/*
** my_cat.h for my_cat in ~/c/rendu/exos/cat
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 10 13:57:42 2001 jean-daniel michaud
** Last update Wed Oct 10 16:17:42 2001 jean-daniel michaud
*/

#ifndef __MYCAT_H_
# define __MYCAT_H_

# define READ_SIZE	1

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	cat(char *file);
int	catb(char *file);
int	cate(char *file);
int	catf(char *file);
int	cats(char *file);
int	catt(char *file);
int	catu(char *file);
int	catv(char *file);
int	catn(char *file);
void	my_printnbr(int nbr);
void    my_printdigit(int d);
int	call(char *file, char c);
void	my_printchar(char c);

#endif
