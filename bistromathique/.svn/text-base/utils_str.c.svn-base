/*
** utils_str.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 01:23:29 2001 jonathan mimouni
** Last update Sat Oct 27 10:05:18 2001 jonathan mimouni
*/

#include <stdlib.h>
#include <stdio.h>
#include "utils_str.h"

int	max(int a, int b)
{
  if (a <= b)
    return (b);
  else
    return (a);
}


char	*my_strcpy(char *dest, char *src)
{
  char	*res;

  if (!src)
    dest = NULL;
  else
    for (res = dest; *src != '\0'; ++src, ++res)
      *res = *src;
  *res = '\0';
  return (dest);
}

char	*my_strdup(char *s)
{
  char	*str;
  int	size;
  int	i;

  size = my_strlen(s) + 1;
  if ((str = malloc(size * sizeof (char))) == 0)
    return (0);
  for (i = 0; s[i] != '\0'; str[i] = s[i++])
    ;
  str[i] = '\0';
  return (str);
}

int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != '\0'; ++i)
    ;
  return (i);
}

void		my_revstr(char *dest, char *src)
{
  unsigned int	i;
  unsigned int	j;
  char		c;

  if (dest != src)
    my_strcpy(dest, src);
  j = my_strlen(dest);
  if (0 == j)
    return;
  for (i = 0; i < --j; ++i)
    {
      c = dest[i];
      dest[i] = dest[j];
      dest[j] = c;
    }
}




