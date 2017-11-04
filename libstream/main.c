#include <stdlib.h>
#include <stdio.h>
#include "libstream.h"
#include "defines.h"

int main ()
{
  int c;
  my_file *passwd;
  my_file *toto;

  passwd = my_fopen("/etc/passwd", "r");
  toto = my_fopen("./toto", "w");
  while ((c = my_fgetc(passwd)) != MY_EOF)
    my_fputc(c, toto);
  my_fclose(toto);
  my_fclose(passwd);
  return (0);
}
