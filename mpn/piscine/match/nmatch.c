/*
** nmatch.c for nmatch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 15:22:40 2001 jean-daniel michaud
** Last update Thu Oct  4 15:28:02 2001 jean-daniel michaud
*/

void	*malloc(unsigned int);

unsigned int	nmatch(char *string, char *pattern)
{
  if (*string == *pattern)
    return (*string ? nmatch(string + 1, pattern + 1) : 1);
  else
    if ((*pattern == '*') && (*string))
      return (nmatch(string + 1, pattern) + nmatch(string, pattern + 1));
    else
      return (0);
}
