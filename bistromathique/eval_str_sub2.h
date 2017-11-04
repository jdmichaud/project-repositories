/*
** eval_str_sub2.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 19:06:55 2001 jonathan mimouni
** Last update Wed Oct 24 15:52:28 2001 jean-daniel michaud
*/

#ifndef __EVALSTRSUB2_H_
# define __EVALSTRSUB2_H_

int	rang(char c, char *base);
char	*realloc_revstr(char **strb, int size);
char	*complement(char *str, t_rules *rules, int lenbase);
int	sup(char *str1, char *str2, char *base);
char	*add_moins(char *str, char c);

#endif /* __EVALSTRSUB2_H_ */
