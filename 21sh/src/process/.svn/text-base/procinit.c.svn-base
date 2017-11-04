/*
** procinit.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec 12 11:21:45 2001 jean-daniel michaud
** Last update Sun Dec 30 15:28:04 2001 jean-daniel michaud
*/

#include <stdio.h>

#include "list.h"
#include "struct.h"
#include "process.h"
#include "xmalloc.h"

extern t_glprocess	*gl_process;

void			procinit(void)
{
  init_signals();
  gl_process = xmalloc(sizeof (t_glprocess));
  gl_process->process = NULL;
  gl_process->laststatus = 0;
}
