/*
** libs_error.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:54:25 2001 jean-daniel michaud
** Last update Sat Dec  1 10:57:26 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "libs_error.h"

static char	*tab_libs_error[] =
{
  "libs error: librairie inconnue ",
};

void	libs_error(int n)
{
  if (n > MAX_LIBS_ERROR)
    printf("libs error\n");
  else
    printf("%s\n", tab_libs_error[n - 1]);
}
