/*
** main.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Tue Dec 18 17:49:05 2001 Jonathan APELBAUM
** Last update Mon Dec 31 12:30:10 2001 Jonathan APELBAUM
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h> 
#include <string.h>
#include <signal.h>
#include "init_termcap.h"
#include "exec_char.h"
#include "exec_arrow.h"
#include "exec_ctrl.h"
#include "exec_ctrl_sup_m.h"
#include "treat.h"
#include "realloc.h"
#include "historic.h"

static const t_char batt[] = define_list_of_char;



void		treat_char(t_term_list *list)
{
  print_prompt(list);
  do
    recup_char(list);
  while (!list->finish);
  hiadd(list->chaine);
}


int	my_write(int c)
{
  write(1, &c, 1);
  return (0);

}

void		print_prompt(t_term_list *list)
{
  write(1, list->prompt, strlen(list->prompt));
}
