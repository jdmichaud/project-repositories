/*
** my_showmem.c for my_showmem in ~/c/rendu/piscine/j5
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Oct  1 23:18:34 2001 jean-daniel michaud
** Last update Tue Oct  2 02:04:38 2001 jean-daniel michaud
*/


void	my_printchar(char c)
{
  write(1, &c, 1);
}


void	my_printnbr_base(int nbr, char *base)
{
  int	size_base;
  int	temp;
  int	div;

  for (size_base = 0; base[size_base] != 0; ++size_base)
    ;
  div = 1;
  if (nbr < 0)
    {
      my_printchar('-');
      div = -1;
    }
  while ((nbr / div) >= size_base)
    div *= size_base;
  while ((div >= 1) || (div <= -1))
  {
    temp = base[nbr / div] - 48;
    my_printchar(temp + 48);
    nbr %= div;
    div /= size_base;
  }
}


void	my_showmem(void *mem, unsigned int size)
{
  int	cpt;
  char	*c;
  int	i;

  c = mem;
  cpt = 0;
  for (i = 0; i < size; ++i)
    {
      if (cpt > 15)
	{
	  printf("\n");
	  cpt = 0;
	}
      ++cpt;
      if (c[i] < 10)
	my_printchar('0');      
      my_printnbr_base(c[i], "0123456789ABCDEF");
      my_printchar(' ');      
    }
}




