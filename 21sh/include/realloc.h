/*
** realloc.h for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 17:29:24 2001 Jonathan APELBAUM
** Last update Mon Dec 31 05:31:48 2001 Adrien Pestel
*/



#ifndef __REALLOC_H_
# define __REALLOC_H_


void	*my_malloc(unsigned int i);
char	*my_realloc_term(char *ptr, int new_size);
int   	test_malloc(char *test);

#endif
