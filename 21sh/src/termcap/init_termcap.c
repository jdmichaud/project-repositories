/*
** init.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 11:55:53 2001 Jonathan APELBAUM
** Last update Mon Dec 31 15:04:04 2001 jean-daniel michaud
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
#include "exec_ctrl.h"
#include "exec_ctrl_sup_m.h"
#include "treat.h"
#include "x.h"
#include "historic.h"
#include "xmalloc.h"


static const t_char batt[] = define_list_of_char;
static const t_char batt_arrow[] = define_list_of_arrow;
int                 gl_sig_var;


t_term_list		*init_struct(void)
{
  t_term_list		*list;

  list = xmalloc(sizeof (t_term_list));
  list = xmalloc(sizeof (struct s_term_list));
  memset(list, 0, sizeof (struct s_term_list));
  list->chaine = xmalloc(sizeof (char) * LENGTH_MALLOC);
  list->chaine[0] = '\0';
  list->copy = xmalloc(sizeof (char) * LENGTH_MALLOC);
  list->copy[0] = '\0';
  list->num_of_cols = 1;
  get_entry(0);
  return (list);
}

int			non_canonical_mode(t_term_config *original_term_config)
{
  t_term_config		new_term_config;
  
  char		*term;
  char		bp[1024];

  if ((term = getenv("TERM")) == NULL)
    exit(1);
  if (tgetent(bp, term) != 1)
    exit(1);
  if (!xtcgetattr(STDIN_FILENO, original_term_config))
    return (1);
  xtcgetattr(STDIN_FILENO, &new_term_config);
  new_term_config.c_lflag &= ~(ICANON); 
  new_term_config.c_lflag &= ~(ECHO);
  new_term_config.c_cc[VMIN] = 1; 
  new_term_config.c_cc[VTIME] = 0;
  xtcsetattr(STDIN_FILENO, TCSAFLUSH, &new_term_config);
  return (0);
}


void			init_size_term(t_term_list *list)
{
  struct winsize	size;
  int			cursor;
  int			i;
  
  gl_sig_var = 0;
  if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*) &size)<0) 
    gl_sig_var = 0;
  list->rows = size.ws_row;
  list->cols = size.ws_col;
  cursor = list->curser;
  if (list->chaine[0] != '\0')
    {
      exec_ctrla(list);
      exec_ctrlk(list);
      exec_ctrly(list);
      for (i = 0; i < cursor; i++)
	exec_right(list);
    }
}

char		recup_char(t_term_list *list)
{
  int	       	i;

  read(0, &list->num, 1);
  if (gl_sig_var == 1)
    init_size_term(list);
  else
    {
      for (i = 0; (batt[i].value != list->num) &&
	     (batt[i].value != 0); i++)
	;
      recup_arrow(list, i);
    }
  return (list->num);
}


void		recup_arrow(t_term_list *list, int i) 
{


  if (batt[i].value == ARROW)
    {
      read(1, &list->num, 1);
      read(1, &list->num, 1);
      for (i = 0; (batt_arrow[i].value != list->num) &&
	     (batt_arrow[i].value != 0); i++)
	;
      batt_arrow[i].func(list);
    }
  else
    {
      if (batt[i].value != 0)
	list->num = batt[i].value;
      batt[i].func(list);
    }
}
