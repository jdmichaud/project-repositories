/*
** exec_arrow.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 23:41:17 2001 Jonathan APELBAUM
** Last update Mon Dec 31 13:48:34 2001 Jonathan APELBAUM
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h> 
#include "init_termcap.h" 
#include "x.h" 
#include "treat.h"
#include "exec_ctrl.h"
#include "exec_char.h"
#include "realloc.h"
#include "exec_arrow.h"
#include "change_line.h"
#include "historic.h"

void		exec_up(t_term_list *list)
{
  int		i;
  char		*temp;

  i = 0;
  list = list;
 
  exec_ctrla(list);
  exec_ctrlk(list);
  if ((temp = get_entry(1)))
    {
      for (i = 0; list->chaine[i] != '\0'; i++)
	list->chaine[i] = '\0';
      list->chaine = strdup(temp);
      list->curser = strlen(list->chaine);
      write(1, list->chaine, list->curser);
    }
  else
    tputs(xtgetstr("bl"), 1, my_write);
}


void		exec_down(t_term_list *list)
{
  int		i;
  char		*temp;

  exec_ctrla(list);
  exec_ctrlk(list);
  if ((temp = get_entry(2)))
    {
      for (i = 0; list->chaine[i] != '\0'; i++)
	list->chaine[i] = '\0';
      list->chaine = strdup(temp);
      list->curser = strlen(list->chaine);
      write(1, list->chaine, list->curser);
    }
  else
    tputs(xtgetstr("bl"), 1, my_write);
}


void		exec_left(t_term_list *list)
{
  int		len;


  if (list->curser != 0)
    {
      len = strlen("21sh >");
      if (left_for_line(list))
	{
	  tputs(xtgetstr("up"), 1, my_write);
	  for (len = 1; len != list->cols; len++)
	    tputs(xtgetstr("nd"), 1, my_write);
	  list->num_of_cols--;
	}
      else
	{
	  tputs(xtgetstr("le"), 1, my_write);
	  list->curser--;
	}
    }
}


void		exec_right(t_term_list *list)
{
  int		len;

  if (list->chaine[list->curser] != '\0')
    {
      len = strlen("21sh >");
       if (end_of_line(list))
	 {
	   tputs(xtgetstr("do"), 1, my_write);
	   list->curser++;
	   list->num_of_cols++;
	 }
      else
	{
	  tputs(xtgetstr("nd"), 1, my_write);
	  list->curser++;
	}
    }
}
