/*
** my_strcapitalize.c for my_strcapitalize in ~/c/rendu/piscinne/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 21:57:36 2001 jean-daniel michaud
** Last update Tue Oct  2 02:35:56 2001 jean-daniel michaud
*/

int	my_islower(int c)
{
  if ((c > 96) && (c < 123))
    return (1);
  else
    return (0);
}

int	my_isalpha(int c)
{
  if (((c > 64) && (c < 91)) || (c > 96) && (c < 123))
    return (1);
  else
    return (0);
}

int	my_isalphanum(int c)
{
  int	cond1;
  int	cond2;
  int	cond3;

  cond1 = (c > 64) && (c < 91);
  cond2 = (c > 96) && (c < 123);
  cond3 = (c > 47) && (c < 59);
  if (cond1 || cond2 || cond3)
    return (1);
  else
    return (0);
}

void	my_strcapitalize(char *dest, char *src)
{
  int	i;
  int	cond;

  if (my_isalpha(src[0]))
    dest[0] = src[0] - 32;
  else
    dest[0] = src[0];    
  for (i = 1; src[i] != 0; ++i)
    {
      cond = ((my_isalphanum(src[i])) && !(my_isalphanum(src[i - 1])));
      if (cond && (my_islower(src[i])))
	  dest[i] = src[i] - 32;
      else
	  dest[i] = src[i]; 
    }
  dest[i] = '\0';
}
