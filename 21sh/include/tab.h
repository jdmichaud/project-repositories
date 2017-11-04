/*
** tab.h for  in
** 
** Made by (Florent Monbillard)
** Login   <monbil_f@epita.fr>
** 
** Started on  Mon Dec 31 02:46:06 2001 Florent Monbillard
** Last update Mon Dec 31 04:39:08 2001 Florent Monbillard
*/

#ifndef   TAB_H_
# define   TAB_H_

void	build_tab(char *, char **);
void	init_tab(char **, char **, int);
void	destroy_tab(char **);
int	end_tab(char **, char *);

#endif /* TAB_H_ */
