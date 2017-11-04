/*
** sub.h for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Tue Oct 16 22:23:19 2001 Jean-Daniel Michaudf
** Last update Sat Oct 27 22:25:33 2001 jonathan mimouni
*/

#ifndef __EVALSTRSUB_H_
# define __EVALSTRSUB_H_

void		do_sub(char *str1, char *str2, char *base, char *res);
char		*subl(char *str1, char* str2, t_rules *rules);
void		retenue(char *str, char *base, int lenbase);
int		init(char *str1p, char *str2p, char **str1b, char **str2b);
char		*purge(char *str, t_rules *rules);

#endif /* __EVALSTRSUB_H_ */
