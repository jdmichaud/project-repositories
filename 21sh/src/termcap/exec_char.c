/*
** exec_char.c for  in 
** 
** Made by Jonathan APELBAUM
** Login   <apelba_j@epita.fr>
** 
** Started on  Wed Dec 19 23:37:56 2001 Jonathan APELBAUM
** Last update Mon Dec 31 13:40:49 2001 Jonathan APELBAUM
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include "init_termcap.h"
#include "realloc.h"
#include "exec_char.h"
#include "change_line.h"
#include "exec_ctrl.h"
#include "x.h"
#include "completion.h"
#include "treat.h"
#include "xmalloc.h"


void		exec_backspace(t_term_list *list)
{
  char		*temp;
  int		middle;
  int		end;
  
  if (list->curser != 0)
    { 
      for (temp = list->chaine, end = 0; temp[end] != '\0'; end++)
	;
      middle = list->curser;
      list->num = temp[middle - 1];
      cote(list);
      while (middle <= end)
	{
	  temp[middle - 1] = temp[middle];
	  middle++;
	}
      list->curser -= 1;
      print_backspace(list);
    }
}


void		print_backspace(t_term_list *list)
{
  int		end;

  if (back_for_line(list))
    {
      tputs(xtgetstr("dc"), 1, my_write);
      tputs(xtgetstr("up"), 1, my_write);
      for (end = 1; end != list->cols; end++)
	tputs(xtgetstr("nd"), 1, my_write);
      list->num_of_cols--;
    }
  else
    {
      tputs(xtgetstr("le"), 1, my_write);
      tputs(xtgetstr("dc"), 1, my_write);
    }
}


void		exec_tabe(t_term_list *list)
{
  char		**result;
  int		j;

  result = get_completion(list->chaine);
  if (result)
    {
      if (result[0] && (result[1] == NULL))
	for (j = list->curser; result[0][j] != NULL; j++)
	  {
	    list->num = result[0][j];
	    exec_char(list);
	  }
      else
	{
	  for (j = 0; result[j] != NULL; j++)
	    {		
	      write(1, "\n", 1);
	      write(1, result[j], strlen(result[j]));
	    }
	  write(1, "\n", 1);
	  print_prompt(list);
	  write(1, list->chaine, strlen(list->chaine));
	}
    }
  else
    tputs(xtgetstr("bl"), 1, my_write);
}


void		exec_enter(t_term_list *list)
{
  int		end;
  char		*temp;

  if (list->cote == 0)
    list->finish = 1;
  else
   {
     for (end = 0; list->chaine[end] != '\0'; end++)
       ;
     free(list->prompt);
     list->prompt = strdup(">");   
     write(1, "\n", 1);
     temp = list->chaine;
     list->chaine = xmalloc(sizeof (char) * LENGTH_MALLOC);
     *(list->chaine) = '\0';
     list->num_of_cols = 1;
     list->num = 0;
     list->curser = 0;
     treat_char(list);
     list->chaine = my_strcat(temp, list->chaine);
   }
}

char		*my_strcat(char *temp1, char *temp2)
{
  int		len1;
  int		len2;
  int		i;

  for (len1 = 0; temp1[len1] != '\0'; len1++)
    ;
  temp1[len1] = '\n';
  temp1 = my_realloc_term(temp1, strlen(temp1) + strlen(temp2));
  for (len2 = len1 + 1, i = 0; temp2[i] != '\0'; i++, len2++)
    temp1[len2] = temp2[i];
  temp1[len2] = temp2[i];
  return (temp1);
}

