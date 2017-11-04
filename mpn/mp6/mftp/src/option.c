/*
** option.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:11:55 2001 jean-daniel michaud

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "option.h"
#include "list.h"
#include "error.h"
#include "xmalloc.h"
#include "log.h"

int		logoption(t_options *options, char *argv[])
{
  int		i;
  int		j;
  t_list	*list;

  for (i = 1; argv[i]; ++i)
    if ((argv[i][0] == '-') && (argv[i][1] == 'U'))
      {
	options->loglevel = 0;
	for (j = 2, list = NULL; argv[i] && (argv[i][j] != 0) &&
	       isdigit(argv[i][j]); ++j)
	  push(&list, argv[i][j]);
	if (list)
	  options->loglevel = atoi(collapse(list));
	for (j = 0, list = NULL, ++i; argv[i] && (argv[i][j] != 0) &&
	       isalnum(argv[i][j]); ++j)
	  push(&list, argv[i][j]);
	if (argv[i] && argv[i][j] == 0)
	  options->logfile = collapse(list);
	else
	  usage();
      }
  return (0);
}

int		portoption(t_options *options, char *argv[])
{
  int		i;
  int		j;
  t_list	*list;
  
  for (i = 1; argv[i]; ++i)
    if ((argv[i][0] == '-') && (argv[i][1] == 'p'))
      {
	for (j = 0, list = NULL; (argv[i + 1][j] != 0) &&
	       isdigit(argv[i + 1][j]); ++j)
	  push(&list, argv[i + 1][j]);
	if (argv[i + 1][j] == 0)
	  options->port = atoi(collapse(list));
	else
	  usage();
      }
    else
      if ((argv[i][0] == '-') && (argv[i][1] == 'm'))
	{
	  for (j = 0, list = NULL; (argv[i + 1][j] != 0) &&
		 isdigit(argv[i + 1][j]); ++j)
	    push(&list, argv[i + 1][j]);
	  if (argv[i + 1][j] == 0)
	    options->maxuser = atoi(collapse(list));
	  else
	    usage();
	}
  return (0);
}

int		otheroptions(t_options *options, char *argv[])
{
  int		i;

  for (i = 1; argv[i]; ++i)
    if (argv[i][0] == '-')
      {
	if (argv[i][1] == 'a')
	  options->options |= ANONYMOUS;
	else
	  if (argv[i][1] == 'V')
	    options->options |= VERSION;
	  else
	    if (argv[i][1] == 'v')
	      {
		options->options |= VERBOSE;
		log(-3, NULL);
	      }
	    else
	      if ((argv[i][1] != 'U') && (argv[i][1] != 'p') 
		  && (argv[i][1] != 'm'))
		{
		  fprintf(stderr, "Unkown options -%s\n", argv[i]);
		  usage();
		}
      }
  return (0);
}

void		funkyoptions(t_options *options, char *argv[])
{
  int		i;

  for (i = 1; argv[i]; ++i)
    if (argv[i][0] == '-')  
      if (!strcmp(&argv[i][1], "quiet"))
	close(1);
}

t_options	*getoptions(char *argv[])
{
  t_options	*options;

  options = xmalloc(sizeof (t_options));
  options->loglevel = -10;
  options->logfile = NULL;
  options->options = 0;
  options->maxuser = MAXUSER;
  options->port = -1;
  log(4, "get options");
  logoption(options, argv);
  portoption(options, argv);
  otheroptions(options, argv);
  funkyoptions(options, argv);
  return (options);
}
