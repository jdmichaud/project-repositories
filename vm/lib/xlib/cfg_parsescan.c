/*
** cfg_parsescan.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 10:02:05 2002 julien gein
** Last update Fri Jan 11 10:31:02 2002 julien gein
*/

#include "display.h"
#include "my_print_error.h"

char		*gettk(char **s)
{
  char		*save;
  char		*res;
  t_endfct	end;
  
  spcjump(s);
  end = issep(**s) ? isid : issep;
  for (save = *s; **s && !end(**s) && !isspc(**s); (*s)++)
    ;
  if (*s == save)
    return (0);
  res = xmalloc(sizeof (char) * (*s - save + 1));
  my_strncpy(res, save, *s - save);
  res[*s - save] = '\0';
  spcjump(s);
  return (res);
}

unsigned int	isalnum(char c)
{
  return ((c >= 'a' && c <= 'z') ||
	  (c >= 'A' && c <= 'Z') ||
	  (c >= '0' && c <= '9'));
  
}

unsigned int	str_isalnum(char *s)
{
  while (*s)
    {
      if (!isalnum(*s))
	return (0);
      s++;
    }
  return (1);
}

t_list		*get_listerror(char *var, int err, t_list *list)
{
  const char	*msg[] =
  {
    "\tSyntax error: Variable expected. \'%s\' found\n",
    "\tSyntax error: \',\' expected between two vars\n",
    "\tSyntax error: \'%s\' expected in set function\n"
  };
  
  my_print_error(msg[err], var);
  if (list)
    list_free(&list);
  return (0);
}

t_list		*get_listargs(char **str, char *end)
{
  t_list	*list;
  char		*oldtk;
  char		*tk;
  int		start;
  
  start = **str;
  for (oldtk = 0, list = 0; ((tk = gettk(str)) && strcmp(tk, end)); )
    {
      if (!strcmp(tk, ","))
	list_append(&list, oldtk);
      else
	if (oldtk && strcmp(oldtk, ","))
	  return (get_listerror(0, CFG_COMAEXP, list));
      oldtk = tk;
    }
  if (!tk && (my_strcmp(end, "<EOL>") || !start))
    return (get_listerror(end, CFG_ENDEXP, list));
  list_append(&list, oldtk);
  return (list);
}
