/*
** get_next_line.h for get_next_line in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Oct  6 20:09:10 2001 jean-daniel michaud
** Last update Sun Oct  7 17:19:10 2001 jean-daniel michaud
*/

#ifndef __GETNEXTLINE_H_
#define __GETNEXTLINE_H_
#define	READ_SIZE	62

#include <unistd.h>
#include <stdlib.h>
#include "list.h"


char		*read_block(int fd);
unsigned int	need_read(char *buf);
char		*my_strndup_cr(char *str, int size);
unsigned int	my_strlen_cr(char *str);
char		*get_next_line(int fd);
void		my_strcpy_cr(char *dst, char *src);
char		*my_realloc_str(char *str, unsigned int size);
void		my_free(void *tmp);
char		*update(char *buf);

#endif
