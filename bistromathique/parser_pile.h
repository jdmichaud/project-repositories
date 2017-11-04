/*
** parser_pile.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 17:02:15 2001 jonathan mimouni
** Last update Sat Oct 27 19:46:17 2001 jonathan mimouni
*/

#ifndef __PARSERPILE_H_
# define __PARSERPILE_H_

void	parser_pile_op(t_rules *rules, t_pile_str **p_str, 
		       t_pile_op **p_op, char **op);
char	*parser_pile(t_rules *rules);
void	parse_expr(t_rules *rules, t_pile_str **p_str, 
		   t_pile_op **p_op, char **expr);

#endif /* __PARSERPILE_H_ */
