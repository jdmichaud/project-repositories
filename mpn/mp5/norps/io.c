/*
** io.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 10:10:28 2001 jean-daniel michaud
** Last update Tue Dec  4 05:13:15 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "io.h"
#include "list.h"

char		*getcmd(void)
{
  t_list	*list;
  char		c;

  printf(PROMPT);
  list = NULL;
  for (c = fgetc(stdin); c != '\n'; c = fgetc(stdin))
    push(&list, c);
  push(&list, 0);
  return (collapse(list));
}
