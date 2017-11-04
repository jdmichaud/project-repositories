/*
** change_line.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Mon Dec 31 03:07:30 2001 Jonathan APELBAUM
** Last update Mon Dec 31 12:35:55 2001 Florent Monbillard
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h> 
#include "init_termcap.h" 
#include "x.h" 
#include "exec_char.h"
#include "realloc.h"
#include "exec_arrow.h"
#include "change_line.h"

int		end_of_line(t_term_list *list)
{
  int		len;

  len = strlen(list->prompt);
  if ((list->curser + len) == (list->cols * list->num_of_cols + 1))
    return(1);
  else
    return(0);
}

int		left_for_line(t_term_list *list)
{
  int		len;

  len = strlen(list->prompt);
  if ((list->curser + len) == (list->cols * (list->num_of_cols - 1)))
    return(1);
  else
    return(0);
}

int		back_for_line(t_term_list *list)
{
  int		len;

  len = strlen(list->prompt);
  if ((list->curser + len + 1) == (list->cols * (list->num_of_cols - 1)))
    return(1);
  else
    return(0);
}
