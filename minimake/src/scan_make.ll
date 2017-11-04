%{
//
// scan_make.ll for minimake in 
//
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
// 
// Started on  Sat Feb 16 07:37:02 2002 jean-daniel michaud
// Last update Sun Feb 24 16:04:03 2002 jean-daniel michaud
//

using namespace std;

#include <iostream>
#include <string>
#include <errno.h>
#include <assert.h>
#include <string.h>
#include "graph.hh"
#include "parse.hh"
#include "parse_make.h"

#define YY_NEVER_INTERACTIVE 1

extern Graph	graph;
const char	*value;

%}
%option noyywrap stack
%x PCOMMENT PPRE PACTION PVARDEC PVAR

spaces	[\t ]*
name	[a-zA-Z_\.][a-zA-Z0-9_\.]*
id	[^\n=\\#\t]*
action  [^:\n$]*
var	[^\n]*

%%
<INITIAL>
{
  "#"		{ BEGIN(PCOMMENT); }
  
  ":"		return (COLON);
  [\t ]*"="	{ BEGIN(PVARDEC); return (EQ); }
  "\n"		return (CR);
  "$"		{ yy_push_state(PVAR); }
  "\\"		return (BACKSLASH);
  {name}	{
    yylval->str = new string (); 
    yylval->str->append(yytext, yyleng);
    return (NAME);
  }
  \t		{ BEGIN(PACTION); }
  {spaces}	;
  <<EOF>>	return (EOF);
}
<PCOMMENT>
{
  "\n"		{ BEGIN(INITIAL); return (CR); }
  .		;
}
<PPRE>
{
  {name}	{
    yylval->str = new string (); 
    yylval->str->append(yytext, yyleng);
    return (NAME);
  }
  "\n"		BEGIN(PACTION);
  [\t ]*	;
}
<PACTION>
{
  {action}	{ 
    yylval->str = new string (); 
    yylval->str->append(yytext, yyleng);
    return (ACTION);
  }
  "$"		{ yy_push_state(PVAR); }  
  "\n"		{ BEGIN(INITIAL); }
}
<PVARDEC>
{
  {var}		{
    yylval->str = new string ();
    yylval->str->append(yytext, yyleng);
    return (VARDEC);
  }
  "\n"		{ BEGIN(INITIAL); return (CR); }
}
<PVAR>
{
  "("		;
  [^\n()]+	{ value = graph.getValue(yytext); }
  ")"		{

    if (value)
      for (unsigned i = strlen(value) - 1; i; --i)
	unput(value[i]);
    yy_top_state(); yy_pop_state();
  }
}

%%

void	scan_open(const string &name)
{
  yyin = fopen(name.c_str(), "r");

  if (!yyin)
    {
      cerr << "cannot open `" << name << "': " << strerror(errno) << endl;
      exit (1);
    }
}

void	scan_close(void)
{
  fclose(yyin);
}
