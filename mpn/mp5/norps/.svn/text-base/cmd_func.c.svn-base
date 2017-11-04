/*
** cmd_func.c for norps in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat Dec  1 08:15:03 2001 jean-daniel michaud
** Last update Tue Dec  4 05:31:45 2001 jean-daniel michaud
*/

#include "struct.h"
#include "cmd_func.h"
#include "vars.h"
#include "libs.h"
#include "parse_error.h"
#include "parse_func.h"

int	open_libs(t_libs **libs, t_vars **vars, char **cmd)
{
  char	*name;
  char	*aliasname;
  char	*tmp;
  char	*str;

  str = *cmd;
  name = get_next_word(cmd);
  if (!name)
    {
      parse_error(9);
      return (1);
    }
  if ((tmp = get_next_word(cmd)) && strcmp(tmp, AS_ID))
    parse_error(6);
  else
    if (tmp)
      {
	aliasname = get_next_word(cmd);
	add(libs, name, aliasname);
      }
    else
      add(libs, name, name);
  return (1);
}

int	close_libs(t_libs **libs, t_vars **vars, char **cmd)
{
  char	*tmp;
  
  tmp = get_next_word(cmd);
  if (!tmp)
    {
      parse_error(7);
      return (1);
    }
  del(libs, tmp);
  return (1);
}

int	unset_vars(t_libs **lib, t_vars **vars, char **cmd)
{
  char	*id;

  id = get_next_word(cmd);
  if (!id)
    {
      parse_error(7);
      return (1);
    }
  if (!del_vars(vars, id))
    parse_error(8);
  return (1);
}

int		print(t_libs **lib, t_vars **vars, char **cmd)
{
  t_vars	*val;
  
  if ((val = get_value(*vars, *cmd)))
    {
      if (val->type == VOID)
	printf("0x%x\n", val->value.ptr);
      else
	printf("%i\n", val->value.i);
      return (1);
    }
  printf("error: variable non definie\n");
  return (1);
}

