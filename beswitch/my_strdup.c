/*
** my_strdup.c for my_strdup in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 19:39:14 2001 jean-daniel michaud
** Last update Sun Nov 11 17:52:18 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_strdup.h"

unsigned int	my_strlen(char *str)
{
  int	i;

  for (i = 0; str[i] != 0; ++i)
    ;
  return (i);
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
