/*
** bistromathique.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 17:05:12 2001 jean-daniel michaud
** Last update Fri Oct 26 16:14:26 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bistromathique.h"
#include "parser_pile.h" 
#include "parser.h"
#include "karatsuba.h"
#include "free.h"

int		main()
{
  t_rules	*rules;

  rules = parse_in();
  printf("%s", parser_pile(rules));
  free_all(rules);
  return (0);
}







