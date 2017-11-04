#include <stdlib.h>
#include "bistromathique.h"
#include "utils_str.h"  
#include "eval_str_mul.h"    
#include "errors.h"

void	init_str_for_lmul(char *a, char **b, t_rules *rules)
{
  int	len;
  char	*reva;
  
  reva = *b;
  len = my_strlen(a);
  reva = malloc(len + 2);
  my_revstr(reva, a);
  if (len % 2 != 0)
    {
      reva[len] = rules->base[0];
      reva[len + 1] = '\0';
    }
  *b = reva;
}

void	init_res_for_lmul(char **a, char **b, 
			  char **c, t_rules *rules)
{
  char	*nbr_a;
  char	*nbr_b;
  char	*res;

  nbr_a = *a;
  nbr_b = *b;
  res = *c;
  if ((nbr_a = malloc(3)) == NULL)
    errors(rules, 3);
  if ((nbr_b = malloc(3)) == NULL)
    errors(rules, 3);
  if ((res = malloc(2)) == NULL)
    errors(rules, 3);
  res[0] = rules->base[0];
  res[1] = '\0';
  *a = nbr_a;
  *b = nbr_b;
  *c = res;
}

void	 my_small_revstr(char **a, char *reva, int j)
{
  char *nbr_a;

  nbr_a = *a;
  nbr_a[0] = reva[j + 1];
  nbr_a[1] = reva[j];
  *a = nbr_a;
}

void	free_str_used_in_lmul(char *a, char *b, 
			      char *c, char *d)
{
  free(a);
  free(b);
  free(c);
  free(d);
}
