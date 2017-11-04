/*
** cfg_parsefunc.c for  in 
** 
** Made by julien gein
** Login   <gein_j@epita.fr>
** 
** Started on  Fri Jan 11 09:58:07 2002 julien gein
** Last update Fri Jan 11 09:58:18 2002 julien gein
*/

unsigned int	isspc(char c)
{
  return (c == ' ' || c == '\t' || c == '\n');
}

unsigned int	ispar(char c)
{
  return (c == '(' || c == ')');
}

unsigned int	issep(char c)
{
  return (c == ':' || c == '=' || c == ',' || ispar(c));
}

unsigned int	isid(char c)
{
  return (!issep(c));
}

void	spcjump(char **s)
{
  while (**s && isspc(**s))
    (*s)++;
}
