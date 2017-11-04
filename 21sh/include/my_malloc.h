/*
** my_malloc.h for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Dec 23 16:42:36 2001 jonathan mimouni
** Last update Mon Dec 31 13:03:59 2001 jonathan mimouni
*/

#ifndef _MY_MALLOC_H_
# define _MY_MALLOC_H_

void    *my_malloc(unsigned int i);
char    *my_realloc(char *ptr, int new_size);
void    my_free(void *pa, void *pb, void *pc, void *pd);

#endif
