/*
** div2.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sun Oct 14 22:47:35 2001 Jean-Daniel Michaudf
** Last update Thu Oct 25 16:38:15 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromathique.h"
#include "eval_str_sub2.h"
#include "utils_str.h"

int	rang(char c, char *base)
{
  int	i;
  
  for (i = 0; c != base[i]; ++i)
    ;
  return (i);
}

char	*realloc_revstr(char **strb, int size)
{
  char	*res;
  int	i;
  char	*str;

  str = *strb;
  res = malloc(size * sizeof (char));
  for (i = 0; str[i]; ++i)
    res[i] = str[i];
  for (; i < size; ++i)
    res[i] = '0';
  res[i] = '\0';
  return (res);
}

int	sup(char *str1, char *str2, char *base)
{
  int	i;

  for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); ++i)
    ;
  if (!((str1[i] == '\0') && (str2[i] == '\0')))
    {
      if (str1[i] == '\0')
	return (0);
      else
	return (1);
    }
  --i;
  for (; ((str1[i] == base[0]) && (str2[i] == base[0])); --i)
    ;
  for (; ((str1[i] == str2[i]) && (i > 0)); --i) 
    ;
  return (rang(str1[i], base) >= rang(str2[i], base));
}

char	*complement(char *str, t_rules *rules, int lenbase)
{
  int	i;
  
  for (i = 0; str[i] != '\0'; ++i)
    str[i] = rules->base[lenbase - rang(str[i], rules->base) - 1];
  return (str);
}

char	*add_moins(char *str, char c)
{
  char *strtmp;
  int  i;

  strtmp = malloc((my_strlen(str) + 2) * sizeof (char));
  *strtmp = c;
  for (i = 0; str[i] != '\0'; ++i)
    strtmp[i + 1] = str[i];
  strtmp[i + 1] = '\0';
  free(str);
  return (strtmp);
}





