/*
** my_atoi.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Sep 25 21:56:08 2001 jean-daniel michaud
** Last update Mon Nov 12 11:55:45 2001 jean-daniel michaud
*/

#include "utils.h"
#include "my_printf.h"
#include "my_strdup.h"

int	my_atoi(char *str)
{
  int	cpt;
  int	mul;
  int	res;
  
  res = 0;
  for (cpt = 0; str[cpt + 1] != 0; ++cpt);
  mul = 1;
  while (cpt >= 0)
    {
      if (str[cpt] == '-')
	res *= -1;
      else
	  res += (str[cpt] - 48) * mul;
      mul *= 10;
      --cpt;
    }
  return (res);
}

char	my_dtoc(long int i)
{
  char	c;

  c = i;
  return (c);
}

int		is_spec(char c)
{
  static char	spec_tab[] = { '\a', '\b', '\e', '\n', '\f', 
			       '\r', '\t', '\v', '\0', '\\', '\"', '\'' };
  static char	char_tab[] = { 'a', 'b', 'e', 'n', 'f',
			       'r', 't', 'v', '0', '\\', '"', '\'' };
  int		i;

  for (i = 0; (i < MAX_SPEC) && (c != spec_tab[i]); ++i)
    ;
  if (c == spec_tab[i])
    {
      my_printf("\\");
      my_printf("%c", char_tab[i]);
      return (0);
    }
  return (1);
}

char	*my_strcat(char *s, char *append)
{
  int	size;
  int	i;

  size = my_strlen(s);
  for (i = 0; append[i] != '\0'; ++i)
    s[size + i] = append[i];
  s[i] = '\0';
  return (s);
}
