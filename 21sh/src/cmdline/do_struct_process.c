/*
** do_struct_process.c for  in 
** 
** Made by AMSELLEM
** Login   <amsell_j@epita.fr>
** 
** Started on  Wed Dec 19 16:10:42 2001 AMSELLEM
** Last update Mon Dec 31 03:15:33 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "redo_line.h"
#include "cmdline.h"
#include "struct.h"
#include "do_struct_process.h"
#include "xmalloc.h"

/*
** fct qui compte le nbre d'element ds la liste t_line. Elle prend en parametre
** t_line qui est la ligne de commande decomposee en liste. Elle retourne le 
** nbre d'element dds la liste.
*/
int	nb_argcs(t_line *line)
{
  int	i;

  for (i = 0; (line != NULL); i++)
    line = line->next;
  return (i);
}


/*
** fonction qui prend en parametre une t_line qui est la ligne de comande 
** (servira pour compter le nbre de mots ds la commande. elle retourne une
** t_command malloquer et initialise.
*/
t_command	*init_commande(t_line *line)
{
  t_command	*command;
 
  command = xmalloc(sizeof (t_command));
  command->argc = 0;
  command->infile = NULL;
  command->outfile = NULL;
  command->errfile = NULL;
  command->append = 0;
  command->background = 0;
  command->next = NULL;
  command->argv = xmalloc((nb_argcs(line) + 1) * sizeof (char *));
  command->argv[0] = NULL;
  return (command);
}


/*
** fonction qui regarde si un mot est compose seulement de chiffres.
** prend un char * en parametre (le mot a analise) et 
** retourne 1 si le mot est un nombre sinon retourne 0.
*/
int	is_digit_word(char *str)
{
  int	i;

  for (i = 0; str[i] != NULL; i++)
    if (!isdigit(str[i]))
      return (0);
  return (1);
}



/*
** prend en parametre un t_command et un t_line. cette fonction va remplir la 
** structure t_command suivant la t_line. S'il y a une redirection elle va
** metrtre ds tel ou tel champ de la structure le prochain mot rencontre...
** elle retourne un integer: 1 si c une commande ou un argument, 0 si c une 
** redirection. C pour le compteur argc de la structure.
*/
int	add_str_in_list(t_command *command, t_line *src)
{
  int	i;

  for (i = 0; command->argv[i] != NULL; i++)
    ;
  if ((is_digit_word(src->commande) != 0) && (atoi(src->commande) == 2))
    {
      if (src->next && ((!strcmp(src->next->commande, ">")) ||
			(!strcmp(src->next->commande, ">>"))))
	{
	  command->errfile = strdup(src->next->next->commande);
	  command->argv[i + 1] = NULL;
	  return (0);
	}
      if (src->next && ((!strcmp(src->next->commande, "<")) ||
			(!strcmp(src->next->commande, "<<"))))
	{
	  command->errfile = strdup(src->next->next->commande);
	  command->argv[i + 1] = NULL;
	  return (0);
	}
    }
  else
    command->argv[i] = strdup(src->commande);
  command->argv[i + 1] = NULL;
  return (1);
}

int	detect_redirection(t_line **line, t_command *command)
{
  if ((!strcmp((*line)->commande, "<")) || (!strcmp((*line)->commande, "<<")))
    {
      if (!strcmp((*line)->commande, "<<"))
	command->append = 1;
      (*line) = (*line)->next;
      command->infile = strdup((*line)->commande);
      return (1);
    }
  if ((!strcmp((*line)->commande, ">")) || (!strcmp((*line)->commande, ">>")))
    {
      if (!strcmp((*line)->commande, ">>"))
	command->append = 1;
      (*line) = (*line)->next;
      command->outfile = strdup((*line)->commande);
      return (1);
    }
  return (0);
}

			/*EXEMPLE 1:   ls */
/*argc == 1		<-- nb d'argument + 1 pour la commande*/
/*infile == (null)*/
/*outfile == (null)*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ls*/
/*Next == NULL*/


			/*EX 2 : ls -la*/
/*argc == 2*/
/*infile == (null)*/
/*outfile == (null)*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ls*/
/*argv[1] == -la      <-- chaque mot est ds argv[i] comme ds le argv du  main*/
/*Next == NULL*/


			/*EX 3: ls > tmp*/
/*argc == 1*/
/*infile == (null)*/
/*outfile == tmp			<--*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ls*/
/*Next == NULL*/


			/*EX 4: ls tmp > tmp*/
/*argc == 2*/
/*infile == (null)*/
/*outfile == tmp			<--*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ls*/
/*argv[1] == tmp*/
/*Next == NULL*/

			/*EX 5: ls -la | more*/
/*argc == 2*/
/*infile == (null)*/
/*outfile == (null)*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ls*/
/*argv[1] == -la*/
/*Next == */
/*			<-- nouveau next == commande qui est derriere le |*/
/*	argc == 1*/
/*	infile == (null)*/
/*	outfile == (null)*/
/*	errfile == (null)*/
/*	apend == 0*/
/*	background == 0*/
/*	argv[0] == more*/
/*	Next == NULL*/


			/*EX6 : cat < tmp*/
/*argc == 1*/
/*infile == tmp		       <--*/
/*outfile == (null)*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == cat*/
/*Next == (null)*/


			/*EX 7: cat tmp 2> tata*/
/*argc == 2*/
/*infile == (null)*/
/*outfile == (null)*/
/*errfile == tata		<--*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == cat*/
/*argv[1] == tmp*/
/*Next == NULL*/


			/*EX 8: ns_send_msg amsell_j "coucou c moi"*/ /*1*/
			/*OU			     'coucou c moi'*/ /*2*/
			/*OU			     `coucou c moi`*/ /*3*/
/*argc == 3*/
/*infile == (null)*/
/*outfile == (null)*/
/*errfile == (null)*/
/*apend == 0*/
/*background == 0*/
/*argv[0] == ns_send_msg*/
/*argv[1] == amsell_j*/
/*argv[2] == "coucou c moi"*/ /*1*/
/*	     'coucou c moi'*/ /*2*/
/*	     `coucou c moi`*/ /*3*/
/*Next == NULL*/
/*on recoit "coucou c moi" (1)  il faudrat enlenver les ", ' ou `*/
/*	    'coucou c moi' (2)*/
/*	    `coucou c moi` (3)*/
