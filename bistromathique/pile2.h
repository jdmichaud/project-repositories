/*
** pile2.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 19:00:55 2001 jonathan mimouni
** Last update Wed Oct 24 15:56:41 2001 jean-daniel michaud
*/

#ifndef __PILE2_H_
# define __PILE2_H_

void	print_pile_op(t_pile_op *pile);
void	print_pile_str(t_pile_str *pile);
void	eval_pile(t_rules *rules, t_pile_str **pile_str, t_pile_op **pile_op);
char	*pop_all(t_rules *rules, t_pile_str **pile_str, t_pile_op **pile_op);
char	head_op(t_pile_op *pile);

#endif /* __PILE2_H_ */
