/*
** exec_char.h for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 23:38:57 2001 Jonathan APELBAUM
** Last update Mon Dec 31 03:35:24 2001 Jonathan APELBAUM
*/


#ifndef EXEC_CHAR_H_
# define EXEC_CHAR_H_



void		exec_backspace(t_term_list *list);
void		print_backspace(t_term_list *list);
void		exec_tabe(t_term_list *list);
void		exec_enter(t_term_list *list);
char		*my_strcat(char *temp1, char *temp2);


#endif
