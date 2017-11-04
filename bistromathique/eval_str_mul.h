/*
** eval_str_mul.h for bistromathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Oct 24 15:32:39 2001 jean-daniel michaud
** Last update Wed Oct 24 15:51:30 2001 jean-daniel michaud
*/

#ifndef __EVALSTRMUL_H_
# define __EVALSTRMUL_H_

void	init_str_for_lmul(char *a, char **b, t_rules *rules);
void	free_str_used_in_lmul(char *a, char *b, 
			      char *c, char *d);
void	init_res_for_lmul(char **nbr_a, char **nbr_b, 
			  char **res, t_rules *rules);
void	 my_small_revstr(char **nbr_a, char *reva, int j);

#endif /* __EVALSTRMUL_H_ */
