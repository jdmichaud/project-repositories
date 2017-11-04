/*
** user.c for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 09:18:33 2001 jean-daniel michaud

*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#ifdef __sun
#include <crypt.h>
#endif

#include "struct.h"
#include "list.h"
#include "user.h"
#include "xmalloc.h"
#include "files.h"

void		adduser(char *name, char *passwd, char *homedir)
{
  FILE		*fpasswd;
  char		*secret;

  fpasswd = fopen(PASSFILE, "a");
  fwrite(name, strlen(name), 1, fpasswd);
  fwrite(":", 1, 1, fpasswd);
  secret = crypt(passwd, passwd);
  fwrite(secret, strlen(secret), 1, fpasswd);
  fwrite(":", 1, 1, fpasswd);
  fwrite(homedir, strlen(homedir), 1, fpasswd);
  fwrite("\n", 1, 1, fpasswd);
  fclose(fpasswd);
}

void		deluser(char *name)
{

}

char		*gnw(FILE *file)
{
  t_list	*list;
  char		*tmp;
  char		c;

  list = NULL;
  if (feof(file))
    return (NULL);
  for (c = fgetc(file); (c != EOF) && (c != ':') && (c != '\n'); 
       c = fgetc(file))
    push(&list, c);
  push(&list, 0);
  tmp = collapse(list);
  return (tmp);
}

void		gotonextline(FILE *file)
{
  char		c;
  
  for (c = fgetc(file); (c != EOF) && (c != '\n'); )
    c = fgetc(file);
}

int		getuser(char *name, char *passwd, t_user *user)
{
  FILE		*fpasswd;
  char		*tmp;
  char		*secret;
  int		bad;
    
  fpasswd = fopen(PASSFILE, "r");
  bad = 1;
  while (bad && !feof(fpasswd))
    {
      tmp = gnw(fpasswd);
      if (tmp && !strcmp(tmp, name))
	bad = 0;
      else
	gotonextline(fpasswd);
    }
  if (bad)
    return (2);
  tmp = gnw(fpasswd);
  secret = crypt(passwd, passwd);
  if (strcmp(secret, tmp))
    return (1);
  tmp = gnw(fpasswd);
  user->name = name;
  user->homedir = tmp;
  user->datatype = ASCII_TYPE;
  return (0);
}
