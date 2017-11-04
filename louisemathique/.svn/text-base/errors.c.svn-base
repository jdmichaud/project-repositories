/*
** errors.c for louisemathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Oct 28 18:07:10 2001 jean-daniel michaud
** Last update Mon Oct 29 17:37:07 2001 jean-daniel michaud
*/

#include <stdio.h>
#include "errors.h"

void	errors(int i)
{
  if (i == SYS_ERR_VAL)
    fputs(SYS_ERR, stderr);
  if (i == ARG_ERR_VAL)
    fputs(ARG_ERR, stderr);
  if (i == STK_ERR_VAL)
    fputs(STK_ERR, stderr);
  if (i == CAL_ERR_VAL)
    fputs(CAL_ERR, stderr);
  if (i == SYN_ERR_VAL)
    fputs(SYN_ERR, stderr);
  exit(i);
}
