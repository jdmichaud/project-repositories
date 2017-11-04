/*
** my_ctype2.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec  2 13:36:17 2001 jean-daniel michaud
** Last update Mon Dec  3 16:11:40 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "struct.h"
#include "my_ctype2.h"
#include "parse_func.h"
#include "my_ctype.h"

char	*is_affectation(char *cmd)
{
  char	*token;
  char	*first;

  first = get_next_word(&cmd);
  token = get_next_word(&cmd);
  if (token && is_id(first) && !strcmp(token, "="))
    return (first);
  return (NULL);
}
