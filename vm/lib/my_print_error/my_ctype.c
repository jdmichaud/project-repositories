/*
** my_ctype.c for my_tiny_printf in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  1 11:57:46 2001 jean-daniel michaud
** Last update Wed Nov 28 17:54:22 2001 jean-daniel michaud
*/

#include "my_ctype.h"

int	my_isalpha(char c)
{
  if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
    return (1);
  return (0);
}

int	my_isdigit(char c)
{
  if ((c >= '0') && (c <= '9'))
    return (1);
  return (0);
}

int	my_isalphanum(char c)
{
  if (my_isalpha(c) || my_isdigit(c))
    return (1);
  return (0);
}

int	is_dir(const char *s)
{
  if (s[0] == '%')
    {
      if ((s[1] == 'd') || (s[1] == 'i'))
	return (1);
      if (s[1] == 'u')
	return (2);
      if (s[1] == 's')
	return (3);
      if (s[1] == 'c')
	return (4);
      if (s[1] == 'x')
	return (5);
      if (s[1] == 'o')
	return (6);
    }
  return (0);
}
