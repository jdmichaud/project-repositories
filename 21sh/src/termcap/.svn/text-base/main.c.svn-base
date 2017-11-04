/*
** main.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Tue Dec 18 17:49:05 2001 Jonathan APELBAUM
** Last update Mon Dec 31 00:53:32 2001 Jonathan APELBAUM
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
#include "x.h"


int			main(void)
{
  t_term_list		*list;
  t_term_config		original_term_config;
  struct sigaction	*my_sig;

  non_canonical_mode(&original_term_config);
  list = init_struct();
  init_size_term(list);
  init_sig(my_sig);
  list->prompt = strdup("21sh >");
  treat_char(list);
  xtcsetattr(STDIN_FILENO, TCSAFLUSH, &original_term_config);
  write(1, "\n", 1);
  write(1, list->chaine, strlen(list->chaine));
  write(1, "\n", 1);
  free(list);
  return (0);
}

