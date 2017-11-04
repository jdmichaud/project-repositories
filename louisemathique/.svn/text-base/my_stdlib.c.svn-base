/*
** my_stdlib.c for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct 28 18:02:34 2001 jean-daniel michaud
** Last update Mon Oct 29 18:40:55 2001 jean-daniel michaud
*/

#include "stdlib.h"
#include "errors.h"
#include "my_stdlib.h"

void	*xmalloc(unsigned int size)
{
  void	*ptr;

  if (size == 0)
    return (NULL);
  if ((ptr = malloc(size)) == NULL)
    errors(SYS_ERR_VAL);
  return (ptr);
}

void	free_p(void *p1, void *p2, void *p3, void *p4)
{
  if (p1)
    free(p1);
  if (p2)
    free(p2);
  if (p3)
    free(p3);
  if (p4)
    free(p4);
}
