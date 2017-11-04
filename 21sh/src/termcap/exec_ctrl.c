/*
** exec_ctrl.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Fri Dec 21 03:12:43 2001 Jonathan APELBAUM
** Last update Mon Dec 31 12:54:43 2001 Jonathan APELBAUM
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h> 
#include "init_termcap.h"
#include "realloc.h"
#include "exec_ctrl.h"
#include "exec_char.h"
#include "exec_arrow.h"
#include "x.h"
#include "treat.h"

void		exec_ctrla(t_term_list *list)
{
  while (list->curser != 0)
    exec_left(list);
}

void		exec_ctrlc(t_term_list *list)
{
  list = list;
  kill(0, SIGINT);
}

void		exec_ctrle(t_term_list *list)
{
  int		end;

  for (end = 0; list->chaine[end] != '\0'; end++)
    ;
  while (list->curser != end)
    exec_right(list);
}

void		exec_ctrlk(t_term_list *list)
{
  int		end;
  int		i;

  for (end = 0; list->copy[end] != '\0'; end++)
    list->copy[end] = '\0';
  tputs(xtgetstr("ce"), 1, my_write);
  for (end = list->curser, i = 0; list->chaine[end] != '\0'; end++, i++) 
   {
     list->num = list->chaine[end];
     cote(list);
     list->copy[i] = list->chaine[end];
     list->chaine[end] = '\0';
    }
  list->copy[i] = '\0';
}


void		exec_ctrll(t_term_list *list)
{
  char		*temp;
  int		end;
  
  tputs(xtgetstr("cl"), 1, my_write);
  print_prompt(list);
  for (temp = list->chaine, end = 0; temp[end] != '\0'; end++)
    ;
  write(1, list->chaine, strlen(list->chaine));
  tputs(xtgetstr("im"), 1, my_write);
  while (end != list->curser)
    {
      tputs(xtgetstr("le"), 1, my_write);
      end--;
    }
  tputs(xtgetstr("ei"), 1, my_write);
}
