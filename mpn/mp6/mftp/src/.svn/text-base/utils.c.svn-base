/*
** utils.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sun Dec 16 17:47:40 2001 jean-daniel michaud

*/

#include <stdio.h>
#ifndef __alpha
#include <sys/types.h>
#endif
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <glob.h>

#include "struct.h"
#include "utils.h"
#include "xmalloc.h"
#include "list.h"

char			*getip(int whence)
{
  int			i;
  char			*hostname;
  char			*ip;
  struct hostent	*entry;
  struct in_addr	*in_addr;
  
  hostname = xmalloc (sizeof (char) * MAXHOSTNAMESIZE);
  gethostname(hostname, MAXHOSTNAMESIZE);
  entry = gethostbyname(hostname);
  in_addr = (struct in_addr *) entry->h_addr_list[0];
  ip = inet_ntoa(*in_addr);
  fflush(stdout);
  if (whence)
    for (i = 0; ip[i]; ++i)
      if (ip[i] == '.')
	ip[i] = ',';
  free(hostname);
  return (ip);
}

int     nbrlen(int nbr)
{
  int   len;
  
  if (nbr == 0)
    return (1);
  for (len = 0; nbr != 0; nbr /= 10, len++)
    ;
  return (len);
}

char    *itoa(int nbr)
{
  int   i;
  int   j;
  int   len;
  char  *res;
  
  len = nbrlen(nbr);
  res = xmalloc((len + 1) * sizeof (char));
  i = 1;
  j = 0;
  if (nbr < 0)
    {
      i = -1;
      res[j++] = '-';
    }
  for (; (nbr / i) >= 10; i *= 10)
    ;
  while ((i >= 1) || (i <= -1))
    {
      res[j] = '0' + nbr / i;
      nbr = nbr % i;
      i /= 10;
      j++;
    }
  res[j] = '\0';
  return (res);
}

char			*port2char(int pport)
{
  char			*ret;

  ret = xmalloc(8 * sizeof (char));
  strcpy(ret, itoa(pport/256));
  strcat(ret, ",");
  strcat(ret, itoa(pport%256));
  return (ret);
}

int			char2port(char *pport)
{
  int			ret;
  char			c;
  t_list		*list;

  list = NULL;
  while ((c = *pport++) != ',')
    push(&list, c);
  ret = 256 * atoi(collapse(list));
  list = NULL;
  while ((c = *pport++))
    push(&list, c);
  ret += atoi(collapse(list));
  return (ret);
}

int			isregexp(char *str)
{
  static char		specchar[3] = {'*', '?', 0};
  int i;
  int j;

  if (!str)
    return (0);
  for (i = 0; str[i]; ++i)
    for (j = 0; specchar[j]; ++j)
      if (str[i] == specchar[j])
	return (1);
  return (0);
}

void    strup(char *dest, char *src)
{
  if (dest && src)
    for (; *src != '\0'; ++src, ++dest)
      {
	if ((*src > 96) && (*src < 123))
	  *dest = *src - 32;
	else
	  *dest = *src;
      }
}

char	**complete(char **argv)
{
  glob_t	g;
  char		*arg;
  char		*save = NULL;
  int i;

  if (argv[1])
    {
      if (!isregexp(argv[1]))
	{
	  arg = (char *) xmalloc (sizeof (char) * (strlen(argv[1]) + 3));
	  arg = strcpy (arg, argv[1]);
	  arg = strcat (arg, "*");
	  save = argv[1];
	  argv[1] = arg;
	}
      g.gl_offs = 2;
      glob(argv[1], GLOB_DOOFFS, NULL, &g);
      for (i = 0; g.gl_pathv[i]; ++i)
	fprintf(stderr, "argv[%i]=%s<", i, argv[i]);
      g.gl_pathv[0] = argv[0];
    }
  free(save);
  return (g.gl_pathv);
}
