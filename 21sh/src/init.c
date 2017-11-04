/*
** init.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 10:57:32 2001 jean-daniel michaud
** Last update Mon Dec 31 13:57:17 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "struct.h"
#include "error.h"
#include "xmalloc.h"
#include "init_termcap.h"
#include "process.h"
#include "list_cmd.h"
#include "treat.h"
#include "init.h"
#include "historic.h"

void	init_21sh(t_list_cmd **list_cmd)
{
  load_historic(HISTORIC_FILE);
  putenv("PS1=21sh >");
  *list_cmd = NULL; 
  procinit();
}

t_term_list		*init_term(void)
{
  t_term_list		*list;

  list = init_struct();
  init_size_term(list);
  init_sig();
  list->prompt = strdup(getenv("PS1"));  
  return (list);
}
