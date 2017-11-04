%option noyywrap
%s NODES NODE EDGES EDGE
%{
/*
** parser.l for regis in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Wed Dec  5 15:28:03 2001 jean-daniel michaud
** Last update Sun Dec  9 07:18:51 2001 jean-daniel michaud
*/
  /*
  ** Entree valide
  ** 2$a;b#(a,b);(b,a)
  */

#include <string.h>  

#include "parser.h"
#include "defs.h"
%}
%%
<INITIAL>
{
  [' '\t\n]	;
  [0-9]+ {
    gl_str = strdup(yytext);
    return (F_REG);
  }
  \$		BEGIN(NODES);
  .		return (F_ERROR);
  <<EOF>>	return (EOF);
}
<NODES>
{
  [' '\t\n]	;
  [a-zA-Z][_a-zA-Z0-9]* {
    gl_str = strdup(yytext);
    return (F_NODES);
  }
  \;		;
  #		BEGIN(EDGES);
  .		return (F_ERROR);
  <<EOF>>	return (F_ERROR);
}
<EDGES>
{
  [' '\t\n]	;
  \(		BEGIN(EDGE);
  \;		;
  .		return (F_ERROR);
  <<EOF>>	return (EOF);
}
<EDGE>
{
  [' '\t\n]	;
  [a-zA-Z][a-zA-Z0-9_]* {
    gl_str = strdup(yytext);
    return (F_EDGE);
  }
  ,		;
  \)		BEGIN(EDGES);
  <<EOF>>	return (EOF);
}
%%
