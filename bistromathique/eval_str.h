/*
** eval_str.h for bistromathique in ~/c/rendu/projs/bistromathique
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Sun Oct 21 18:43:18 2001 jonathan mimouni
** Last update Sun Oct 28 15:30:25 2001 jean-daniel michaud
*/

#ifndef __EVALSTR_H_
# define __EVALSTR_H_

char	*lplus(char *stra, char* strb, t_rules *rules);
char	*lmul(char *a, char* b, t_rules *rules);
char	*divl(char *a, char *b, t_rules *rules);
char	*init_divl(char *a, char *b, char **_a, char **_b);

#endif /* __EVALSTR_H_ */
