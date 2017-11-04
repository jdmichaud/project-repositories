/*
** parser.h for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Tue Dec 11 20:25:16 2001 Actarus Acta
** Last update Mon Dec 31 13:04:28 2001 jonathan mimouni
*/

#ifndef _PARSER_LINE_H_
# define _PARSER_LINE_H_

#define CMD_SIZE	20
#define DOT_COMMA	0
#define ESPERLUET	1
#define PIPE		2
#define QUOTE		3
#define DOUBLE_QUOTE	4
#define BACKSLASH	5
#define NON_SEP		6

t_list_cmd		*parser_line(char *line);
int			get_next_cmd(t_list_cmd **list, char **p_line);
int			get_char_value(char c);
void			init_tabsep(char *tabsep);

#endif

