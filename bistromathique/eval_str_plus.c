/*
** eval_str_plus.c for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 18:40:40 2001 jonathan mimouni
** Last update Sat Oct 27 23:05:24 2001 jonathan mimouni
*/

#include "bistromathique.h"
#include "eval_str_plus.h"
#include "utils_str.h"

int	b_pos(char c, char *base)
{
  int	i;

  for (i = 0; (base[i] != c) && (base[i] != '\0'); ++i)
    ;
  if (base[i] == '\0')
    return (-1);
  else
    return (i);
}

void	end_plus(int retenue, char *result, char *save, char *base)
{
  if (retenue == 1)
    {
      *result = 1 + base[0];
      ++result;
    }
  *result = '\0';
  my_revstr(save, save);
}

int	lplus_main2(char *result, int tmp, char *base, int lenbase)
{
  int	retenue;

  if (tmp >= lenbase)
    {
      *result = base[tmp - lenbase];
      retenue = 1;
    }
  else
    {
      *result = base[tmp];
      retenue = 0;
    }
  return (retenue);
}
  
int	lplus_main1(char *a, char *b, char **result, t_rules *rules)
{
  int	retenue;
  int	tmp;
  
  for (retenue = 0; (*a != '\0') || (*b != '\0'); ++(*result))
    {
      if ((*a != '\0') && (*b != '\0'))  
	{
	  tmp = b_pos(*a, rules->base) + b_pos(*b, rules->base);
	  a = a + 1 - (b - b++);
	}
      else
	if (*b != '\0')
	  {
	    tmp = b_pos(*b, rules->base);
	    ++b;
	  }
	else
	  {
	    tmp = b_pos(*a, rules->base);
	    ++a;
	  }
      tmp += retenue;
      retenue = lplus_main2(*result, tmp, rules->base, rules->len_base);
    }
  return (retenue);
}





