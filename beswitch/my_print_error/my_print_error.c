/*
** my_printf.c for my_tiny_printf in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  1 11:50:00 2001 jean-daniel michaud
** Last update Fri Nov  9 19:37:48 2001 jean-daniel michaud
*/

#include <stdarg.h>

#include "my_print_error.h"
#include "my_printfnbr.h"
#include "my_printfstr.h"
#include "my_printfchar.h"
#include "my_printfnbr_base.h"
#include "my_ctype.h"
#include "init.h"

int		my_print_error(const char *format, ...)
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
	  i += my_printenbr_base(va_arg(arg, unsigned int), BASE16);
	if (dir_id == 6)
	  i += my_printenbr_base(va_arg(arg, unsigned int), BASE8);
      }
    else
      if ((*(--format) == '%') && (*(format + 1) == '%'))
	i += my_printechar(*(++format));
      else
	i += my_printechar(*format);
  va_end(arg);
  return (i);
}
