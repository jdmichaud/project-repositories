/*
** cmdline2.c for 21sh in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Dec 31 02:33:34 2001 jean-daniel michaud
** Last update Mon Dec 31 12:31:46 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "xmalloc.h"
#include "redo_line.h"
#include "cmdline.h"
#include "do_struct_process.h"

void		free_t_line(t_line **line)
{
  t_line	*prev;
  
  while (*line != NULL)
    {
      prev = *line;
      *line = (*line)->next;      
      free(prev->commande);
      free(prev);
    }
  *line = NULL;
}
 
/*
** cette fonction prend un t_line en argument. elle va appeler les differentes
** fonctions qui vont remplir la structure. renvoie la structure t_command 
** remplie avec s'il y a une redirection un ->next.
*/
t_command	*do_struct(t_line *line)
{
  int		i;
  t_command	*commande;
  
  for (i = 0, commande = init_commande(line); (line != NULL); 
       line = line->next, i = 0)
    if (detect_redirection(&line, commande) == 1)
      ;
    else     
      if (!strcmp(line->commande, "&"))
	commande->background = 1;
      else
	if (!strcmp(line->commande, "|"))
	  {
	    commande->next = do_struct(line->next);
	    return (commande);
	  }
	else
	  {
	    i = add_str_in_list(commande, line);
	    if (i == 0)
	      line = line->next->next;
	    commande->argc += i;
	  }
  free(line);
  return (commande);
}


void	look_guill(char *old_line, int i, t_guill *guill)
{
  if (old_line[i] == '\"')
    if (guill->guill == 1)
      guill->guill--;
    else
      guill->guill++;
  else
    if (old_line[i] == '\'')
      if (guill->quote == 1)
	guill->quote--;
      else
	guill->quote++;
    else
      if (old_line[i] == '`')
      {
	if (guill->back_quote == 1)
	  guill->back_quote--;
	else
	  guill->back_quote++;
      }
  
}


/*
** cette fct prend la ligne de commande en parametre et va appeler les 
** differentes fct qui vont rajouter des espaces
** elle retourne une nouvelle chaine avec les espaces, et free l'ancienne 
** chaine
*/
char		*redo_line(char *old_line)
{
  char		*res;
  t_guill	*guill;

  guill = xmalloc(sizeof (t_guill));
  guill->guill = 0;
  guill->quote = 0;
  guill->back_quote = 0;
  old_line = redo_line_space(old_line, guill);
  old_line = redo_line_ou(old_line, guill);
  old_line = redo_line_et(old_line, guill);
  old_line = redo_line_inf(old_line, guill);
  res = redo_line_sup(old_line, guill);
  free(old_line);
  free(guill);
  return (res);
}

/*
** imprime la t_line; A ENLEVER<<<=======
*/
void	print_list(t_line *line)
{
  for (; (line != NULL); line = line->next)
    printf("[%s]  ", line->commande);
  printf("\n");
}
