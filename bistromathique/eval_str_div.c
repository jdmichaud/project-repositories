/*
** eval_str_div.c for bistromathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 08:40:06 2001 jean-daniel michaud
** Last update Sun Oct 28 16:01:46 2001 jonathan mimouni
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromathique.h"
#include "eval_str_sub2.h"
#include "eval_str_div2.h"
#include "eval_str_div.h"
#include "eval_str_sub.h"
#include "utils_str.h"
#include "my_strcmp.h"
#include "eval_str.h"
#include "utils2.h"
#include "utils3.h"

char	**generate(char **mul_tab, char *b, t_rules *rules)
{
  int	i;
  int	lenbase;
  char	*mul;

  lenbase = my_strlen(rules->base);
  mul_tab = malloc(lenbase * sizeof (char *));
  for (i = 1; i <= lenbase; ++i)
    {
      mul = my_strdup_fc(rules->base[i]);
      mul_tab[i - 1] = lmul(b, mul, rules);
      free(mul);
    }
  return (mul_tab);
}

void		init_do_divl(char *b, char *_tmp, char **rev_b, char **rev_tmp)
{
  *rev_b = malloc((my_strlen(b) + 1) * sizeof (char));
  *rev_tmp = malloc((my_strlen(_tmp) + 1) * sizeof (char));
  my_revstr(*rev_b, b);
  my_revstr(*rev_tmp, _tmp);
}

void		do_a_thing(char *__tmp, char **tmp, unsigned int j)
{
  unsigned int	size;
  unsigned int	i;
  unsigned int	mark_from_start;
  char		*_tmp;

  size = my_strlen(__tmp);
  _tmp = *tmp;
  for (i = j - size, mark_from_start = 0; i < j; ++i, ++mark_from_start)
    _tmp[i] = __tmp[mark_from_start];
  for (i = j - size; i > 0; ++(*tmp), --i)
    ;
}


int	_sup(char *str1, char *str2, char *base)
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

char		do_divl(char **tmp, char *b, t_rules *rules, char **mul_tab)
{
  char		*_tmp;
  char		*__tmp;
  char		*_b;
  unsigned int	i;
  unsigned int	j;
  char		*rev_tmp;
  char		*rev_b;

  for (_tmp = *tmp, _b = b, i = 0; _b[i]; ++i)
    ;
  init_do_divl(_b, _tmp, &rev_b, &rev_tmp);
  i += sup(rev_b, rev_tmp, rules->base) || !(my_strcmp(_tmp, b));
  _tmp = malloc(i * sizeof (char));
  _tmp[i] = '\0';
  for (j = i; i > 0; --i)
    _tmp[i - 1] = (*tmp)[i - 1];
  i = 0;
  __tmp = subl(_tmp, mul_tab[i], rules);
  my_revstr(rev_tmp, __tmp);
  for (; _sup(rev_tmp, rev_b, rules->base); free(__tmp), ++i,
	 __tmp = subl(_tmp, mul_tab[i], rules), my_revstr(rev_tmp, __tmp))
    ;
  do_a_thing(__tmp, tmp, j);
  free_p(rev_b, rev_tmp, NULL, NULL);
  return (rules->base[i + 1]);
}



