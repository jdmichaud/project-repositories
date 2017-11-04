/*
** my_malloc.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sat Nov  3 20:24:52 2001 jonathan mimouni
** Last update Mon Dec 31 13:40:11 2001 Jonathan APELBAUM
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "init_termcap.h"
#include "realloc.h"
#include "xmalloc.h"


int		test_malloc(char *test)
{
  int		i;

  for (i = 1; *test != '\0'; test++, i++)
    ;
  if (i%LENGTH_MALLOC == LENGTH_MALLOC - 1)
    return(0);
  return(1);
}

char	*my_realloc_term(char *ptr, int new_size)
{
  char	*res;

  if ((res = xmalloc(new_size * sizeof (char))) == 0)
  {
    exit(0);
    write(2, "word to long\n", 13);
  }
  strcpy(res, ptr);
  return (res);
}
