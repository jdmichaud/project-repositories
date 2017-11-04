/*
** parser.h for lddump in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Thu Nov 29 21:20:00 2001 jean-daniel michaud
** Last update Tue Dec  4 01:16:27 2001 jean-daniel michaud
*/

#ifndef PARSER_H_
# define PARSER_H_

#define MAX_KW		14
#define MAX_FN		7
#define MAX_ARGS	4

#define	OPEN		1
#define CLOSE		2
#define LIBS		3
#define VARS		4
#define UNSET		5
#define PRINT		6
#define QUIT		7

typedef enum	e_argtype
{
  STRING,
  INTEGER,
  AS,
  SEPARATOR
}		t_argtype;

typedef struct	s_keyword
{
  char		*id;
  int		argc;
  t_argtype	argtype[MAX_ARGS];
}		t_keyword;

int		get_first_word(char **cmd, char **word);
int		parse(t_libs **libs, t_vars **vars, char *cmd);
t_vars		*function(t_libs *libs, t_vars *vars, char *cmd, int type);
t_params	*format_params(t_vars *vars, char *cmd, int type);

#endif
