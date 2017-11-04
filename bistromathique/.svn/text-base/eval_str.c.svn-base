/*
** eval_str.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  9 17:07:17 2001 jean-daniel michaud
** Last update Sun Oct 28 15:35:27 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>
#include "bistromathique.h"
#include "eval_str_sub.h"
#include "utils_str.h"
#include "my_printnbr_base.h"
#include "eval_str.h"
#include "eval_str_div.h"
#include "eval_str_div2.h"
#include "eval_str_mul.h"
#include "eval_str_sub2.h"
#include "eval_str_plus.h"
#include "karatsuba.h"
#include "utils2.h"
#include "utils3.h"

char	*lplus(char *stra, char* strb, t_rules *rules)
{
  char	*result;
  char	*save;
  char	*a;
  char	*b;
  int	retenue;
  
  a = malloc(my_strlen(stra) + 1);
  b = malloc(my_strlen(strb) + 1);
  my_revstr(a, stra);
  my_revstr(b, strb);
  result = malloc(max(my_strlen(a), my_strlen(b)) + 1);
  save = result;
  retenue = lplus_main1(a, b, &result, rules);
  end_plus(retenue, result, save, rules->base);
  free(a);
  free(b);
  return (save);
}

char	*lmul(char *a, char* b, t_rules *rules)
{
  int	cpt[4];
  char	*res;
  char	*reva;
  char	*revb;
  char	*nbr_a;
  char	*nbr_b;
  char	*tmp;

  init_str_for_lmul(a, &reva, rules);
  init_str_for_lmul(b, &revb, rules);
  init_res_for_lmul(&nbr_a, &nbr_b, &res, rules);
  tmp = res;
  for (cpt[1] = 0, cpt[2] = 1; reva[cpt[1]] != '\0'; cpt[1] += 2, ++cpt[2])
    {
      my_small_revstr(&nbr_a, reva, cpt[1]);
      for (cpt[0] = 0, cpt[3] = cpt[2]; revb[cpt[0]] != '\0'; 
	   cpt[0] += 2, ++cpt[3], res = tmp)
	{
	  my_small_revstr(&nbr_b, revb, cpt[0]);
	  tmp = lplus(kara(nbr_a, nbr_b, cpt[3], rules), res, rules);
	  free(res);
	}
    }
  free_str_used_in_lmul(nbr_a, nbr_b, reva, revb);
  return (purge(res, rules));
}


char	*init_divl(char *a, char *b, char **_a, char **_b)
{
  *_a = malloc((my_strlen(a) + 1) * sizeof (char));
  *_b = malloc((my_strlen(b) + 1) * sizeof (char));
  my_revstr(*_a, a);
  my_revstr(*_b, b);
  return (my_strdup(a));
}

char	*divl(char *a, char *b, t_rules *rules)
{
  char	**mul_tab;
  char	*res;
  char	*rp;
  char	*tmp;
  char	*_a;
  char	*_b;
  char	*save4free;
  int	i;

  tmp = init_divl(a, b, &_a, &_b);
  if (!(sup(_a, _b, rules->base)))
    res = my_strdup_fc(rules->base[0]);
  mul_tab = generate(mul_tab, b, rules);
  save4free = tmp;
  res = malloc(my_strlen(a) + 1);
  rp = res;
  my_revstr(_a, tmp);
  my_revstr(_b, b);
  for (i = 0; sup(_a, _b, rules->base) && its_end(&res, tmp, rules, b); 
       my_revstr(_a, tmp), my_revstr(_b, b), rp[i] = '\0', rp = res)
    rp[i++] = do_divl(&tmp, b, rules, mul_tab);
  if (!sup(_a, _b, rules->base))
    rest(&res, tmp, rules);
  free_p(_a, _b, save4free, NULL);
  return (res);	
}

