/*
** my_strncmp.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Thu Nov  8 00:47:57 2001 GIZMO
** Last update Thu Nov  8 00:50:16 2001 GIZMO
*/

#include "my.h"

int		my_strncmp(char *s1, char *s2, int n)
{
  unsigned char us1;
  unsigned char us2;

  us1 = *s1;
  us2 = *s2;
  while ((us1 != '\0') && (us2 != '\0') && (us1 == us2) && (n > 0))
    {
      us1 = *(s1++);
      us2 = *(s2++);
      n--;
    }
  return (us1 - us2);
}
