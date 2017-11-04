/*
** div.c for bistromathique in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Sun Oct 14 21:41:28 2001 Jean-Daniel Michaudf
** Last update Sun Oct 28 16:02:10 2001 jonathan mimouni
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "eval_str_sub.h"
#include "eval_str_sub2.h"
#include "eval_str_sub3.h"
#include "utils_str.h"
#include "utils2.h"
#include "utils3.h"

int	init(char *str1p, char *str2p, char **str1b, char **str2b)
{
  int	imax;
  int	str1_base;  
  int	str2_base;
  char	*str1;
  char	*str2;

  *str1b = my_strdup(str1p);
  *str2b = my_strdup(str2p);
  str1 = *str1b;
  str2 = *str2b;
  my_revstr(str1, str1);
  my_revstr(str2, str2);
  str1_base = my_strlen(str1);
  str2_base = my_strlen(str2);
  if (str1_base > str2_base)
    imax = str1_base;
  else
    imax = str2_base;
  *str1b = realloc_revstr(&str1, imax + 1);
  *str2b = realloc_revstr(&str2, imax + 1);
  return (imax);
}

void	retenue(char *str, char *base, int lenbase)
{
  if (str[0] != '\0')
    {
      if  (str[0] == base[lenbase])
	{
	  str[0] = base[0];
	  retenue(&str[1], base, lenbase);
	}
      else
	str[0] = base[rang(str[0], base) + 1];
    }
}

char		*purge(char *str, t_rules *rules)
{
  char		*tmp;
  unsigned int	size;
  unsigned int	i;
  
  for (i = (str[0] == '-'); str[i] == '0'; ++i)
    ;
  size = my_strlen(&str[i] + 1);
  if (str[0] == '-')
    ++size;
  tmp = malloc(size * sizeof (char));
  if (str[0] == '-')
    {
      tmp[0] = '-';
      my_strcpy(&tmp[1], &str[i]);
    }
  else
    my_strcpy(tmp, &str[i]);
  free(str);
  return (tmp);
}

void	do_sub(char *str1, char *str2, char *base, char *res)
{
  int	 tmp;
  int	lenbase;

  lenbase = my_strlen(base);
  if (rang(str1[0], base) < rang(str2[0], base))
    {
      tmp = rang(str1[0], base) + lenbase;
      res[0] = base[tmp - rang(str2[0], base)];
      retenue(&str2[1], base, lenbase);
    }
  else
    res[0] = base[rang(str1[0], base) - rang(str2[0], base)];
}

char	*subl(char *str1p, char* str2p, t_rules *rules)
{
  int	i;
  int	imax;
  int	issup;
  int	base_size;
  char	*res;
  char	*str1;
  char	*str2;

  if ((res = if_zero(str1p, str2p, rules)) != NULL)
    return (res);
  base_size = my_strlen(rules->base);
  imax = init(str1p, str2p, &str1, &str2);
  issup = sup(str1, str2, rules->base);
  res = malloc(imax * sizeof (char));
  for (i = 0; i < imax; ++i)
    do_sub(&str1[i], &str2[i], rules->base, &res[i]);
  res[i] = '\0';
  my_revstr(res, res);
  if (!issup)
    res = less_t_zero(res, rules, base_size);
  res = purge(res, rules);
  free_p(str1, str2, NULL, NULL);
  if (!*res)
    *res = rules->base[0];
  return (res);
}




