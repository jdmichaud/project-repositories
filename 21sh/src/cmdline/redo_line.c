/*
** redo_line.c for  in 
** 
** Made by AMSELLEM
** Login   <amsell_j@epita.fr>
** 
** Started on  Wed Dec 19 16:34:16 2001 AMSELLEM
** Last update Mon Dec 31 12:32:02 2001 Florent Monbillard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "redo_line.h"
#include "cmdline.h"
#include "xmalloc.h"

/*
** prend un char * en entree: la commande.
** cette fct va mettre des espaces en les pipe '|'
** elle retourne la chaine de char * avec les espaces
*/
char	*redo_line_ou(char *old_line, t_guill *guill)
{
  char	*res;
  int	i;
  int	j;

  res = xmalloc((2 * strlen(old_line)) + 1);
  for (i = 0, j = 0; old_line[i] != '\0'; j++, i++)
    {
      if (((old_line[i] == '|') && (old_line[i + 1] != ' ') && 
	  (old_line[i - 1] != '\\') && (old_line[i + 1] != '|')) &&
	  (guill->guill == 0) && (guill->quote == 0) && 
	  (guill->back_quote == 0))
	{
	  res[j++] = ' ';
	  res[j++] = old_line[i++];
	  res[j++] = ' ';
	}
      else
	look_guill(old_line, i, guill);
      res[j] = old_line[i];
    }
  res[j] = '\0';
  return (res);
}


/*
** prend un char * en entree: la commande.
** cette fct va mettre des espaces en les et : '&'
** elle retourne la chaine de char * avec les espaces
*/
char	*redo_line_et(char *old_line, t_guill *guill)
{
  char	*res;
  int	i;
  int	j;

  res = xmalloc((2 * strlen(old_line)) + 1);
  for (i = 0, j = 0; old_line[i] != '\0'; j++, i++)
    {
      if (((old_line[i] == '&') && (old_line[i + 1] != ' ') && 
	  (old_line[i - 1] != '\\') && (old_line[i + 1] != '&')) &&
	  (guill->guill == 0) && (guill->quote == 0) && 
	  (guill->back_quote == 0))
	{
	  res[j++] = ' ';
	  res[j++] = old_line[i++];
	  res[j++] = ' ';
	}
      else
	look_guill(old_line, i, guill);
      res[j] = old_line[i];
    }
  res[j] = '\0';
  return (res);
}


/*
** prend un char * en entree: la commande.
** cette fct va mettre des espaces en les redirections: '<'
** elle retourne la chaine de char * avec les espaces
*/
char	*redo_line_inf(char *old_line, t_guill *guill)
{
  char	*res;
  int	i;
  int	j;

  res = xmalloc((2 * strlen(old_line)) + 1);
  for (i = 0, j = 0; old_line[i] != '\0'; j++, i++)
    {
      if (((old_line[i] == '<') && (old_line[i + 1] != ' ') && 
	  (old_line[i - 1] != '\\') && (old_line[i + 1] != '<')) &&
	  (guill->guill == 0) && (guill->quote == 0) && 
	  (guill->back_quote == 0))
	{
	  res[j++] = ' ';
	  res[j++] = old_line[i++];
	  if (old_line[i + 1] == '<')
	    res[j++] = old_line[i++];
	  res[j++] = ' ';
	}
      else
	look_guill(old_line, i, guill);
      res[j] = old_line[i];
    }
  res[j] = '\0';
  return (res);
}


/*
** prend un char * en entree: la commande.
** cette fct va mettre des espaces en les redirections: '>'
** elle retourne la chaine de char * avec les espaces
*/
char	*redo_line_sup(char *old_line, t_guill *guill)
{
  char	*res;
  int	i;
  int	j;

  res = xmalloc((2 * strlen(old_line)) + 1);
  for (i = 0, j = 0; old_line[i] != '\0'; j++, i++)
    {
      if (((old_line[i] == '>') && (old_line[i + 1] != ' ') && 
	  (old_line[i - 1] != '\\') && (old_line[i + 1] != '>')) &&
	  (guill->guill == 0) && (guill->quote == 0) && 
	  (guill->back_quote == 0))
	{
	  res[j++] = old_line[i++];
	  res[j++] = ' ';
	}
      else
	look_guill(old_line, i, guill);
      res[j] = old_line[i];
    }
  res[j] = '\0';
  return (res);
}


/*
** prend un char * en entree: la commande.
** cette fct va mettre des espaces apres tous les characteres speciaux
** elle retourne la chaine de char * avec les espaces
*/
char	*redo_line_space(char *old_line, t_guill *guill)
{
  char	*res;
  int	i;
  int	j;

  res = xmalloc((2 * strlen(old_line)) + 1);
  for (i = 0, j = 0; old_line[i] != '\0'; j++, i++)
    {
      if (((old_line[i + 1] == '>') || (old_line[i + 1] == '<') ||
	   (old_line[i + 1] == '|') || (old_line[i + 1] == '&')) &&
	  (guill->guill == 0) && (guill->quote == 0) && 
	  (guill->back_quote == 0))
	{
	  res[j++] = old_line[i++];
	  res[j++] = ' ';
	}
      else
	look_guill(old_line, i, guill);
      res[j] = old_line[i];
    }
  res[j] = '\0';
  return (res);
}

