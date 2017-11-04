/*
** cmdline.c for  in 
** 
** Made by Jeremy AMSELLEM
** Login   <jeremy@epita.fr>
** 
** Started on  Tue Dec 18 18:57:51 2001 Jeremy AMSELLEM
** Last update Mon Dec 31 12:51:01 2001 jonathan mimouni
*/
#include <stdio.h>
#include <stdlib.h>
#include <struct.h>
#include <string.h>
#include <xmalloc.h>

#include "redo_line.h"
#include "cmdline.h"

/*ATTETION A CAT TMP > TITI | TOTO*/

/*
** fct qui prend un char *(la commande) et un *int (pour l'indice). elle va 
** mettre tout ce qu'il y a entre " ds un seul champs d'un t_line
** elle retourne un t_line remplis par tout ce qu'il y avait entre les 2 "
*/
t_line		*do_comment(char *str, int *i, char c)
{
  t_line	*temp;
  int		j;

  temp = xmalloc(sizeof (t_line));
  temp->commande = xmalloc(strlen(str) + 1);
  j = 0;
  temp->commande[j] = str[*i];
  for (j++, (*i)++; ((str[*i] != c) && (str[*i] != '\0')); (*i)++, j++)
    temp->commande[j] = str[*i];
  temp->commande[j++] = str[*i];
  (*i)++;
  temp->next = NULL;
  return (temp);
}


/*
** fct qui prend un char *(la commande) et un *int (pour l'indice). elle va 
** mettre ds un t_line le mot qui est separe par un ' '. elle retourne la 
** t_line remplie du prochain mot de la ligne de commande.
*/
t_line		*get_next_word(char *str, int *j)
{
  t_line	*temp;
  int		i;

  if ((str[*j] == '\"') || (str[*j] == '\'') || (str[*j] == '`'))
    return (do_comment(str, j, str[*j]));
  temp = xmalloc(sizeof (t_line));
  temp->commande = xmalloc(strlen(str) + 1);
  for (i = 0; ((str[*j] != '\0') && 
	       ((str[*j] != ' ') || (str[(*j - 1)] == '\\'))); (*j)++, i++)
    /* if (str[(*j - 1)] == '\\')
      temp->commande[--i] = str[*j];
      else */
      temp->commande[i] = str[*j];
  temp->commande[i] = '\0';
  temp->next = NULL;
  if (i != 0)
    return (temp);
  free(temp);
  return (NULL);
}


/*
** fct qui prend un char *(la commande) et un *int (pour l'indice). elle va 
** avance ds la chaine tant que le charactere est different d'espace.
** pourra etre changer par: tant que ce n'est pas un separateur.
*/
void	kill_space(char *str, int *j)
{
  while (str[*j] == ' ')
    (*j)++;
}

/*
** prend en parametre 2 t_line. elle va mettre le premier t_line a la fin du
** premier.
*/
void	push(t_line *temp, t_line *the_line)
{
  while (the_line->next != NULL)
    the_line = the_line->next;
  the_line->next = temp;
}

/*
** prend la commande refaite en paramtre. elle va appeler es differentes 
** fonctions pour pouvoir retourner la list t_line complete.
*/
t_line		*do_list_cmd(char *line)
{
  t_line	*the_line;
  t_line	*temp;
  int		i;

  the_line = NULL;
  for (i = 0; (line[i] != '\0'); kill_space(line, &i))
    if (the_line == NULL)
      the_line = get_next_word(line, &i);
    else
      {
	temp = get_next_word(line, &i);
	push(temp, the_line);
      }
  return (the_line);
}



