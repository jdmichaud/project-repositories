/*
** my_revstr.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Sep 26 21:29:29 2001 GIZMO
** Last update Sun Nov 11 22:37:22 2001 GIZMO
*/

#include "my.h"

void	my_revstr(char *dest, char *src)
{
  char	*rtmp;
  char	*ltmp;
  char  *save;
  char	c;

  for (save = dest; *src; src++, dest++)
    *dest = *src;
  *dest = '\0';
  rtmp = dest;
  ltmp = save;
  while (ltmp < --rtmp)
    {
      c = *ltmp;
      *ltmp = *rtmp; 
      *rtmp = c;
      ltmp++;
    }
}
