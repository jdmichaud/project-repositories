/*
** 21sh.c for 21sh in ~/c/rendu/projs/21sh/src
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 09:13:00 2001 jean-daniel michaud
** Last update Mon Dec 31 15:15:08 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <signal.h>
#include <termios.h>
#include "init_termcap.h"
#include "def.h"
#include "struct.h"
#include "x.h"
#include "end.h"
#include "process.h"
#include "list_cmd.h"
#include "parser_line.h"
#include "parser_list_cmd.h"
#include "treat.h"
#include "init.h"
#include "21sh.h"

int			main(void)
{
  int			i;
  int			exit_read;
  t_list_cmd		*list_cmd;
  t_term_list		*list_term;
  t_term_config         original_term_config;
  
  init_21sh(&list_cmd);
  list_term = init_term();
  for (i = 0, exit_read = 0; (!exit_read); ++i)
    { 
      i = non_canonical_mode(&original_term_config);
      treat_char(list_term);
      printf("\n");
      list_cmd = parser_line(list_term->chaine);
      exit_read = parser_list_cmd(list_cmd);
      if (i)
	return (0);
      list_term = init_term();
    } 
  list_cmd_free(&list_cmd);
  end_21sh(&original_term_config);
  return (0);
}


