/*
** list.h aka sujet_j6.txt aka sujet_dur.txt
** 
** Made by (cyril diakhate & les acu)
** Login   ** 
** Started on  Tue Oct  2 09:55:29 2001 des gens chiants
** Last update Sun Oct  7 15:22:55 2001 jean-daniel michaud
*/

#ifndef	LIST_H_
#define	LIST_H_

#include <stdlib.h>

struct		s_list {
  struct s_list	*next;
  int		fd;
  void		*elem;
};
typedef struct s_list	t_list;
typedef int		(*t_cmpfunc)(void *e1, void *e2);

void		list_put(t_list **list, int fd, void *elem);
void		*list_find_elm_eq(t_list *list, void *elem, t_cmpfunc cmp);
t_list		*list_find_node(t_list *list, void *elem, t_cmpfunc cmp);
void		list_free(t_list **list);

#endif
