/*
** treat.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Thu Dec 20 01:57:44 2001 Jonathan APELBAUM
** Last update Mon Dec 31 13:56:43 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>
#include <signal.h>
#include "init_termcap.h" 
#include "exec_char.h"
#include "exec_arrow.h"
#include "realloc.h"
#include "x.h"
#include "change_line.h"
#include "treat.h"
#include "xmalloc.h"


int                 gl_sig_var;



void		exec_char(t_term_list *list)
{
  char		*temp;
  char		for_write;

  if ((list->num >= 32) && (list->num <= 127))
    {
      temp = list->chaine;
      if (!test_malloc((list->chaine)))
	list->chaine = my_realloc_term(list->chaine, 
				  LENGTH_MALLOC + strlen(list->chaine));
      list->chaine = push_curser(list, list->curser);
      list->curser += 1;
      for_write = list->num;
      cote(list);
      tputs(xtgetstr("im"), 1, my_write);
      if (end_of_line(list))
	list->num_of_cols ++;
      write(1, &for_write, strlen(&for_write));
      tputs(xtgetstr("ei"), 1, my_write);
    }
}


char		*push_curser(t_term_list *list, int i)
{
  int		end;
  char		*temp;
  
  for (temp = list->chaine, end = 0; temp[end] != '\0'; end++)
    ;
  while (end != i)
    {
      temp[end + 1] = temp[end];
      end--;
    }
  temp[i + 1] = temp[i];
  temp[i] = list->num;
  return(temp);
}


void	parser(int l)
{
  gl_sig_var = 1;
  l = l;
}

void	init_sig(void)
{
  struct sigaction *my_sig;
  
  my_sig = xmalloc(sizeof (struct sigaction)); 
  sigemptyset(&my_sig->sa_mask);
  my_sig->sa_handler = parser;
  my_sig->sa_flags = 0;
  sigaction(SIGWINCH, my_sig, 0);
}


void		cote(t_term_list *list)
{
  if (list->cote == 0)
    {
      if ((list->num == '\'') || (list->num == '\"') || (list->num == '`'))
	list->cote = list->num;
    }
  else
    if (list->num == list->cote)
      list->cote = 0;
}
