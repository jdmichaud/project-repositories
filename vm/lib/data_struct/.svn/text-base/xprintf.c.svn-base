/*
** xprintf.c
** 
** Made by julien hattab
** Login   hattab_j@epita.fr
** 
** Started on  Wed Dec 19 16:03:53 2001 Julien Hattab
** Last update Wed Dec 19 16:21:31 2001 julien hattab
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define BUF_SIZE	2048

void	xprintf(const int out, const int val,
		const char *mess, ...)
{
  char	buf[BUF_SIZE];
  va_list argp;
  
  va_start(argp, mess);
  vsprintf(buf, mess, argp);
  va_end(argp);
  write(out, buf, strlen(buf));
  exit(val);
}

