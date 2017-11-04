/*
** eval_str_div.h for bistromathique in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct 25 08:35:06 2001 jean-daniel michaud
** Last update Sat Oct 27 22:02:59 2001 jean-daniel michaud
*/

#ifndef __EVALSTRDIV_H_
# define __EVALSTRDIV_H_

char	**generate(char **mul_tab, char *b, t_rules *rules);
char	do_divl(char **tmp, char *b, t_rules *rules, char **mul_tab);
void	init_do_divl(char *b, char *_tmp, char **rev_b, char **rev_tmp);
int	_sup(char *str1, char *str2, char *base);
void	do_a_thing(char *__tmp, char **tmp, unsigned int j);

#endif
