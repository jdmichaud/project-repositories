/*
** parse_error.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Fri Nov 30 12:16:29 2001 jean-daniel michaud
** Last update Tue Dec  4 16:45:06 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "parse_error.h"

const static char	*tab_parse_error[] =
{
  "parse error: ')' innatendue ",
  "parse error: seul les pointeurs non types sont autorises ",
  "parse error: void doit etre un pointeur ",
  "parse error: ')' attendue ",
  "parse error: identifiant inconnu ",
  "parse error: as attendu ",
  "parse error: identifiant manquant ",
  "parse_error: variable inconnue ",
  "parse_error: donnez l'identifiant d'une librairie ",
  "parse_error: cette librairie n'est pas ete chargee ",
  "parse_error: Variable inconnue",
  "parse error: type inconnu"
};

void	parse_error(int n)
{
  if (n > MAX_PARSE_ERROR)
    printf("parse error\n");
  else
    printf("%s\n", tab_parse_error[n - 1]);
}
