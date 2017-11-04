/*
** list.h for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Nov  7 15:47:07 2001 jean-daniel michaud
** Last update Thu Dec 13 14:28:58 2001 jean-daniel michaud
*/

#ifndef LIST_H_
# define LIST_H_

struct		s_list
{
  char		c;
  struct s_list	*next;
};

typedef struct s_list	t_list;

void		push(t_list **list, char c);
char		pop(t_list **list);
unsigned int	lsize(t_list *list);
char		*collapse(t_list *list);
void		free_list(t_list **list);

#endif
