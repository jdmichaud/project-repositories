/*
** eat.h for  in 
** 
** Made by jonathan mimouni
** Login   <mimoun_j@epita.fr>
** 
** Started on  Wed Dec 12 16:49:47 2001 jonathan mimouni
** Last update Mon Dec 31 13:01:07 2001 jonathan mimouni
*/

#ifndef _EAT_H_
# define _EAT_H_

int	eat_dot_comma(int *nb_malloc, int *i, char **line, char **cmd);
int	eat_esperluet(int *nb_malloc, int *i, char **line, char **cmd);
int	eat_pipe(int *nb_malloc, int *i, char **line, char **cmd);
int	eat_quote(int *nb_malloc, int *i, char **line, char **cmd);
int	eat_double_quote(int *nb_malloc, int *i, char **line, char **cmd);

#endif
