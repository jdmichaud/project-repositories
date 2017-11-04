/*
** list.h for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 14:29:15 2001 jean-daniel michaud
** Last update Wed Dec 12 11:29:31 2001 jean-daniel michaud
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  void		*elem;
  struct s_list	*next;
  struct s_list	*prec;
}		t_list;

typedef int             (*t_cmpfunc)(void *e1, void *e2);
typedef int             (*t_freefunc)(void *e1);

void	hadd(t_list **list, void *elem);
void	qadd(t_list **list, void *elem);
void	add_sort(t_list **list, void *elem, t_cmpfunc cmp);
int	lsize(t_list *list);
void	lfree(t_list **list, t_freefunc ffree);

#endif
