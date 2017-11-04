/*
** my_printf.c for my_tiny_printf in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov  1 11:50:00 2001 jean-daniel michaud
** Last update Tue Nov  6 23:40:55 2001 GIZMO
*/

#include <stdarg.h>

#include "my_printf.h"
#include "my_printfnbr.h"
#include "my_printfstr.h"
#include "my_printfchar.h"
#include "my_printfnbr_base.h"
#include "my_ctype.h"
#include "init.h"
#include "my_printf.h"

int		my_printf(const char *format, ...)
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
	  i += my_printfnbr_base(va_arg(arg, unsigned int), BASE16);
	if (dir_id == 6)
	  i += my_printfnbr_base(va_arg(arg, unsigned int), BASE8);
      }
    else
      if ((*(--format) == '%') && (*(format + 1) == '%'))
	i += my_printfchar(*(++format));
      else
	i += my_printfchar(*format);
  va_end(arg);
  return (i);
}
