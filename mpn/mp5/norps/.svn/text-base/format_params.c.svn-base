/*
** format_params.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Dec  4 01:09:11 2001 jean-daniel michaud
** Last update Tue Dec  4 04:27:56 2001 jean-daniel michaud
*/

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "vars.h"
#include "libs.h"
#include "format_params.h"
#include "parse_error.h"

void	get_number(t_params *params, char *token)
{
  params->type[params->nbparams] = INT;
  params->value[params->nbparams].i = atoi(token);
}

void	get_hexa(t_params *params, char *token)
{
  unsigned int	ui;

  params->type[params->nbparams] = PCHAR;
  ui = strtol(&token[2], NULL, 16);
  params->value[params->nbparams].str = 0;
  params->value[params->nbparams].str += ui;
}

void	get_string(t_params *params, char *token)
{
  params->type[params->nbparams] = PCHAR;
  token[strlen(token) - 1] = '\0';
  params->value[params->nbparams].str = &token[1];
}

int		get_variable(t_params *params, t_vars *vars, char *token)
{
  t_vars	*var;

  if (!(var = get_value(vars, token)))
    {
      parse_error(10);
      return (0);
    }
  params->type[params->nbparams] = var->type;
  params->value[params->nbparams] = var->value;
  return (1);
}
