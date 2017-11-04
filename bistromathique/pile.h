/*
** pile.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 16:56:00 2001 jonathan mimouni
** Last update Wed Oct 24 15:56:26 2001 jean-daniel michaud
*/

#ifndef __PILE_H_
# define __PILE_H_

void	push_op(t_pile_op **pile, char elem);
char	pop_op(t_pile_op **pile);
void	push_str(t_pile_str **pile, char *elem);
char	*pop_str(t_pile_str **pile);

#endif /* __PILE_H_ */
