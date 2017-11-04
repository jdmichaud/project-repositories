/*
** list_sort.c for list_sort in ~/c/rendu/piscine/j6
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Oct  2 21:23:15 2001 jean-daniel michaud
** Last update Wed Oct  3 02:20:36 2001 jean-daniel michaud
*/

#include "list.h"
#define	NULL	0

void	*malloc(unsigned int);

void		list_sort(t_list **list, t_cmpfunc cmp)
{
  t_list	*l;
  void		*tmp;
  int		stop;

  stop = 1;
  if (*list != NULL)
    {
      while (stop)
	{
	  stop = 0;
	  for (l = *list; l->next != NULL; l = l->next)
	    if (cmp(l->elem, l->next->elem) > 0)
	      {
		stop = 1;
		tmp = l->elem;
		l->elem = l->next->elem;
		l->next->elem = tmp;
	      }
	}
    } 
}
