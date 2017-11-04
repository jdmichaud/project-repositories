/*
** exec_ctrl_sup_m.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Fri Dec 21 11:53:21 2001 Jonathan APELBAUM
** Last update Mon Dec 31 11:41:58 2001 Jonathan APELBAUM
*/

   
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h> 
#include "init_termcap.h"
#include "realloc.h"
#include "exec_ctrl.h"
#include "exec_ctrl_sup_m.h"
#include "exec_char.h"
#include "exec_arrow.h"
#include "x.h"
#include "treat.h"


void		exec_ctrlu(t_term_list *list)
{
  while (list->curser != 0)
    exec_left(list);
  exec_ctrlk(list);
}


void		exec_ctrlw(t_term_list *list)
{
  int		end;
  int		i;

  for (end = 0; list->copy[end] != '\0'; end++)
    list->copy[end] = '\0';
  for (i = 0; list->curser != i; i++)
    list->copy[i] = list->chaine[i];
  list->copy[i] = '\0';
  for (i = 0; list->curser != 0; i++)
    exec_backspace(list);
}


void		exec_ctrly(t_term_list *list)
{
  int		i;

  
  for (i = 0; list->copy[i] != '\0'; i++)
    {
      list->num = list->copy[i];
      exec_char(list);
      list->copy[i] = '\0';
    }
}

void		exec_ctrlz(t_term_list *list)
{
  list = list;
  kill(0, SIGTSTP);
}


void	my_revstr(char *dest, char *src)
{
  unsigned int	i;
  unsigned int	j;
  char		c;

  if (dest != src)
    strcpy(dest, src);
  j = strlen(dest);
  if (0 == j)
    return;
  for (i = 0; i < --j; ++i)
    {
      c = dest[i];
      dest[i] = dest[j];
      dest[j] = c;
    }
  return;
}
