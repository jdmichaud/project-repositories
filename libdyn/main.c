/*
** main.c for libdyn in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Tue Nov 27 17:29:00 2001 jean-daniel michaud
** Last update Sat Dec  1 08:53:38 2001 jean-daniel michaud
*/

#include <dlfcn.h>

int	main(void)
{
  char	*(*f)(int);
  void	*handle;
  char	*tmp;

  handle = dlopen("error_us.so", DL_LAZY);
  f = dlsym(handle, "get_msg_err");
  tmp = f(0);
  printf("%s\n", tmp);
  free(tmp);
  dlclose(handle);
}
