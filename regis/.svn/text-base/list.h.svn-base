/*
** list.h for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 14:29:15 2001 jean-daniel michaud
** Last update Thu Dec  6 15:37:25 2001 jean-daniel michaud
*/

#ifndef LIST_H_
# define LIST_H_

typedef int	(*t_cmpfunc)(void *e1, void *e2);
typedef void	(*t_freefunc)(void *e1);

void	hadd(t_list **list, void *elem);
void	qadd(t_list **list, void *elem);
void	*dummy_pop(t_list **list);
void	lfree(t_list **list, t_freefunc ffree);

#endif
