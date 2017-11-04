/*
** format.h
**
** Made by (Adrien Pestel)
** Login   <pestel_a@epita.fr>
** 
** Started on  Sun Dec 30 21:56:28 2001 Adrien Pestel
** Last update Mon Dec 31 11:43:58 2001 Adrien Pestel
*/



#ifndef		FORMAT_H_
#  define	FORMAT_H_

typedef char	*(*t_func)(char **str);

struct		s_format
{
  char		c;
  t_func	funky;
};

typedef struct s_format	t_format;

char		*format(char *str);
char		*format_append_chars(char *res, char **str);
int		is_special(char c);

#endif		/* !FORMAT_H_ */
