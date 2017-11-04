#include <stdlib.h>
#include "bistromathique.h"
#include "utils_parser.h"
#include "utils.h"
#include "utils2.h"
#include "pile.h"
#include "pile2.h"
#include "parser_pile.h"
#include "errors.h"

void	parser_pile_op(t_rules *rules, t_pile_str **p_str, 
		       t_pile_op **p_op, char **op)
{
  if (**op == rules->op[5])
    {
      ++(rules->nb_par);
      push_op(p_op, **op);
    }
  else
    if (**op == rules->op[6])
      {
	if (rules->nb_par == 0)
	  errors(rules, 0);
	--(rules->nb_par); 
	while (head_op(*p_op) != rules->op[5])
	  eval_pile(rules, p_str, p_op);
	pop_op(p_op);
      }
    else
      {
	while (priority(rules, **op) <= priority(rules, head_op(*p_op)))
	  eval_pile(rules, p_str, p_op);
	push_op(p_op, **op);
      }  
  ++(*op);
}

char		*parser_pile(t_rules *rules)
{
  t_pile_op	*pile_op;
  t_pile_str	*pile_str;
  
  pile_op = NULL;
  pile_str = NULL;
  if (is_hpop(rules, *(rules->expr)))
    errors(rules, 2);
  else
    if ((*(rules->expr) == rules->op[0]) || (*(rules->expr) == rules->op[1]))
      hpop_lpop(rules, &pile_str, &pile_op, &rules->expr);      
  parse_expr(rules, &pile_str, &pile_op, &rules->expr);
  return (pop_all(rules, &pile_str, &pile_op));
}

void	parse_expr(t_rules *rules, t_pile_str **p_str, t_pile_op **p_op, 
		    char **expr)
{
  while (*(rules->expr) != '\0')
    if (is_op(rules, **expr))
      if (is_hpop(rules, **expr))
	if (is_hpop(rules, *(*expr - 1)))  
	  errors(rules, 2);
	else
	  parser_pile_op(rules, p_str, p_op, expr); 
      else
	if (is_hpop2(rules, **expr))  
	  parser_pile_op(rules, p_str, p_op, expr); 
	else
	  if (is_hpop2(rules, *(*expr - 1)))
	    if ((*(*expr - 1)) != rules->op[6])
	      hpop_lpop(rules, p_str, p_op, expr);
	    else
		nbr_lpop(rules, p_str, p_op, expr);
	  else
	    nbr_lpop(rules, p_str, p_op, expr);
    else
      push_str(p_str, get_next_number(rules, 0, expr));
}





