/*
** my_strlen.c for libstream in 
** 
** Made by Jean-Daniel Michaudf
** Login   <jedi@epita.fr>
** 
** Started on  Wed Oct 17 21:47:49 2001 Jean-Daniel Michaudf
** Last update Wed Oct 17 21:55:57 2001 Jean-Daniel Michaudf
*/

unsigned int my_strlen(const char *str)
{
  int i;
  
  for (i = 0; str[i] != '\0'; ++i)
    ;
  return (i);
}
