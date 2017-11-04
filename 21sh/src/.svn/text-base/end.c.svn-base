/*
** end.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 12:01:54 2001 jean-daniel michaud
** Last update Mon Dec 31 14:23:06 2001 jean-daniel michaud
*/

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include "init_termcap.h"
#include "struct.h"
#include "end.h"
#include "process.h"
#include "x.h"

void		end_21sh(t_term_config *original_term_config)
{
  int		i;
  static char	*end_msg[9] = 
  {
    "---- Thanks for using 21sh... ----",
    " Authors: ",
    "             Amsellem Jeremy,",  
    "            Apelbaum Jonathan,",
    "           Michaud Jean-Daniel,",
    "          Mimouni Jonathan,",
    "         Monbillard Florent,",
    "        Pestel Adrien.",
    "---------------------------------"
  };

  xtcsetattr(STDIN_FILENO, TCSAFLUSH, original_term_config);
  stopall();
  for (i = 0; i < 9; ++i)
    printf("%s\n", end_msg[i]);
  printf("\n");
}

int		terminate(t_shell **shell)
{
  t_process	*tmp_p;
  t_process	*prec_tmp_p;

  if (*shell)
  {
    for (tmp_p = (*shell)->process; tmp_p; tmp_p = tmp_p->next)
    {
      prec_tmp_p = tmp_p;
      tmp_p = tmp_p->next;
    }
    if ((*shell)->command)
      free((*shell)->command);
    free(*shell);
    return (0);
  }
  return (1);
}
