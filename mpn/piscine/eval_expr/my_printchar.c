/*
** my_printchar.c for my_printchar in ~/c/rendu/piscine/j2
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 20:40:49 2001 jean-daniel michaud
** Last update Sun Oct  7 23:23:20 2001 jean-daniel michaud
*/

#include "eval_expr.h"

void	my_printchar(char c)
{
  write(1, &c, 1);
}
