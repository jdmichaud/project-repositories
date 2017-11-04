/*
** match.h for  in
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Fri Dec 21 18:56:27 2001 Florent Monbillard
** Last update Mon Dec 31 02:29:44 2001 Florent Monbillard
*/

#ifndef   MATCH_H_
# define   MATCH_H_

int	got_a_star(char *, char *, int (*fct)(char *, char *));
int	got_an_ip(char *, char *, int (*fct)(char *, char *));
int	got_a_bracket(char *, char *, int (*fct)(char *, char *));
int	got_a_braces(char *, char *, int (*fct)(char *, char *));
int	match(char *, char *);

#endif /* MATCH_H_ */
