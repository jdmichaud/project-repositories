/*
** errors.c for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Wed Dec 12 18:00:26 2001 jonathan mimouni
** Last update Thu Dec 13 10:48:51 2001 jonathan mimouni
*/

#include <stdio.h>
#include "errors.h"

int		error_syntax(char c, int error_value)
{
  fprintf(stderr, "Syntax error: \"%c\" unexpected\n", c);
  return (error_value);
}
