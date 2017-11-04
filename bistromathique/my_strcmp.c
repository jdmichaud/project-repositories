/*
** my_strcmp.c for my_strcmp in /c/rendu/piscine/j3/
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Sep 26 23:27:41 2001 jean-daniel michaud
** Last update Fri Oct 26 12:23:08 2001 jean-daniel michaud
*/

#include "utils_str.h"
#include "my_strcmp.h"
  
int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	size;

  if (my_strlen(s1) >= my_strlen(s2))
    size = my_strlen(s2);
  else
    size = my_strlen(s1);
  for (i = 0; ((i < size) && (s1[i] == s2[i])); ++i)
    ;
  if (s1 == s2)
    return (0);
  else
    return (s1[i] - s2[i]);
}
