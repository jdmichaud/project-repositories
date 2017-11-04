/*
** match.c for match in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Oct  4 15:01:29 2001 jean-daniel michaud
** Last update Thu Oct  4 15:27:27 2001 jean-daniel michaud
*/

void	*malloc(unsigned int);

unsigned int	match(char *string, char *pattern)
{
  if (*string == *pattern)
    return (*string ? match(string + 1, pattern + 1) : 1);
  else
    if ((*pattern == '*') && (*string))
      return (match(string + 1, pattern) || match(string, pattern + 1));
    else
      return (0);
}
