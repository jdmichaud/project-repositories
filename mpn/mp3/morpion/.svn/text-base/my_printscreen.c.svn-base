/*
** my_printscreen.c for morpion in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  1 11:50:00 2001 jean-daniel michaud
** Last update Mon Nov  5 16:06:29 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_printnbr.h"
#include "my_printstr.h"
#include "my_printchar.h"
#include "my_printnbr_base.h"
#include "my_ctype.h"
#include "init.h"
#include "my_printscreen.h"

int		my_tiny_printscreen(const char *format, ...)
{
  int		i;
  int		dir_id;
  va_list	arg;
 
  va_start(arg, format);
  for (i = 0; *format; format++)
    if ((dir_id = is_dir(format++)) != 0)
      {
	if (dir_id < 5)
	  i += tab[dir_id].f(&arg);
	if (dir_id == 5)
	  i += my_printnbr_base(va_arg(arg, unsigned int), BASE10);
	if (dir_id == 6)
	  i += my_printnbr_base(va_arg(arg, unsigned int), BASE8);
      }
    else
      if ((*(--format) == '%') && (*(format + 1) == '%'))
	i += my_printchar(*(++format));
      else
	i += my_printchar(*format);
  va_end(arg);
  return (i);
}
