/*
** lexer.h for math in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Sat May 11 15:19:07 2002 jean-daniel michaud
** Last update Sun May 19 11:50:31 2002 GIZMO
*/

#ifndef __LEXER_H_
# define __LEXER_H_

#define MEOF	0
#define NUMBER	1

#define YY_DECL \
  int yylex (double *lval)
YY_DECL;

void	lex_open (const std::string &name);
void	lex_close (void);

#endif
