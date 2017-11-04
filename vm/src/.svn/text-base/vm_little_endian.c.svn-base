/*
** vm_little_endian.c for  in 
** 
** Made by 
** Login   <bottie_r@epita.fr>
** 
** Started on  Sat Jan  5 03:04:35 2002 
** Last update Mon Jan  7 18:58:26 2002 GIZMO
*/

#include "my_struct.h"
#include "decode.h"

int		little_endian2(char *tab)
{
  int		res;

  res = 0;
  res = tab[1];
  res = res << 4;
  res += tab[0];
  return (res);
}

int		little_endian4(char *tab)
{
  int		res;

  res = 0;
  res = tab[3];
  res = res << 4;
  res += tab[2];
  res = res << 4;
  res += tab[1];
  res = res << 4;
  res += tab[0];
  return (res);
}

