/*
** utils.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 16:47:57 2001 jonathan mimouni
** Last update Wed Oct 24 15:57:01 2001 jean-daniel michaud
*/

#ifndef __UTILS_H_
# define __UTILS_H_

int	is_alpha(t_rules *rules, char c);
int	is_digit(t_rules *rules, char c);
int	is_lpop(t_rules *rules, char c);
int	is_hpop(t_rules *rules, char c);
int	is_known(t_rules *rules, char c);

#endif /* __UTILS_H_ */
