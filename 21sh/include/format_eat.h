/*
** format_eat.h
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Mon Dec 31 11:44:06 2001 Adrien Pestel
** Last update Mon Dec 31 11:45:10 2001 Adrien Pestel
*/



#ifndef		FORMAT_EAT_H_
#  define	FORMAT_EAT_H_

char	*format_eat_quotes(char **str);
char	*format_eat_backslash(char **str);
char	*format_eat_dollar(char **str);
int	xstrlen(char *str);
char	*strconcat(char *left, char *right);

#endif		/* !FORMAT_EAT_H_ */
