#include <stdio.h>
#include <stdlib.h>
#include "bistromathique.h"
#include "karatsuba.h"
#include "eval_str_plus.h"
#include "my_printnbr_base.h"
#include "utils_str.h"
#include "eval_str.h"
#include "eval_str_sub.h"
#include "order.h"
#include "utils3.h"

char	*add_k_zero(char *ab, char zero, int k)
{
  char	*res;
  int	i;
  int   j;
  int	len;
  
  len = my_strlen(ab);
  j = len + k + 1;
  res = malloc(j);
  for (i = 0; i < len; ++i)
    res[i] = ab[i];
  for (; k > 0; --k, ++i)
    res[i] = zero;
  res[i] = '\0';
  return (res);
}

void	init_kara(char *a, char *b, t_rules *rules, char *ab[3])
{
  int	tmp;
  
  tmp = b_pos(a[0], rules->base)*b_pos(b[0], rules->base);
  ab[0] = my_printnbr_base(tmp, rules->len_base, rules);
  tmp = b_pos(a[1], rules->base)*b_pos(b[1], rules->base);
  ab[1] = my_printnbr_base(tmp, rules->len_base, rules);
  tmp = (b_pos(a[0], rules->base) - b_pos(a[1], rules->base)) * 
    (b_pos(b[0], rules->base) - b_pos(b[1], rules->base));
  ab[2] = my_printnbr_base(tmp, rules->len_base, rules);
}

char	*kara(char *a, char *b, int k, t_rules *rules)
{
  char	*ab[3];
  char	*arg[3];
  char	*res;
  int	i;
  char	*plus;
  char	*moins;
  char	*tmp2;
  
  init_kara(a, b, rules, ab);
  arg[0] = add_k_zero(ab[0], rules->base[0], 2 * k);
  plus = order_lplus(ab[0], ab[1], rules);
  moins = order_subl(plus, ab[2], rules);
  arg[1] = add_k_zero(moins, rules->base[0], 2 * k - 1);
  arg[2] = add_k_zero(ab[1], rules->base[0], 2 * k - 2);
  tmp2 = order_lplus(arg[0], arg[1], rules);
  res = order_lplus(tmp2, arg[2], rules);
  free_p(plus, moins, tmp2, NULL);
  for (i = 0; i < 3; ++i)
    {
      free(arg[i]);
      free(ab[i]);
    }
  return (res);
}



