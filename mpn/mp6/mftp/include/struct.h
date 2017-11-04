/*
** struct.h for complètement_local in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Dec 13 10:56:55 2001 jean-daniel michaud

*/

#ifndef STRUCT_H_
# define STRUCT_H_

#define MFTP	"MFTP (complètement_local) v0.5 Copyright (C) 2001 JeDi\n"
#define PROMPT	"[READY ] "

#define ANONYMOUS	1
#define VERBOSE		2
#define VERSION		4

#define MAXSIZE		255
#define MAXLOGINSIZE	255
#define MAXHOSTNAMESIZE	255
#define MAXUSER		666
#define MAXARGS		10

#define TIMEOUT		90
#define MAXDIRSIZE	1024
#define EOL		10

#define ASCII_TYPE	1
#define EBCDIC_TYPE	2
#define IMAGE_TYPE	3
#define LOCAL_TYPE	4

#define	BUFFTRANS	1042

#define	DEBUG_
#define DEEPDEBUG_

typedef struct	s_server
{
  int		socket;
  int		port;
  int		dataport;
  int		datasocket;
  int		params;
  int		loglevel;
  int		actif;
  int		nbuser;
  int		maxuser;
}		t_server;

typedef struct	s_options
{
  int		loglevel;
  char		*logfile;
  int		options;
  int		port;
  int		maxuser;
}		t_options;

typedef struct	s_user
{
  char		*name;
  char		*homedir;
  int		socket;
  int		dataport;
  int		datasocket;
  int		datatype;
}		t_user;

typedef void            (*t_handler)(int nsig);
typedef int		(*t_ftpfnct)(char **argv, 
				     t_server *server, t_user *user);
typedef int		(*t_cnslfnct)(char **argv);

typedef struct	s_command
{
  char		*id;
  t_ftpfnct	fnct;
}		t_command;


typedef struct	s_debugcmd
{
  char		*id;
  t_cnslfnct	fnct;
}		t_debugcmd;

#endif /* !STRUCT_H_ */
