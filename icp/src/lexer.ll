%{
#include <iostream>
#include <string>
#include <errno.h>
#include "lexer.h"
  using namespace std;
%}
%option nounput noyywrap

%%
		
<INITIAL>
{
[-]{0,1}[0-9]+[.][0-9]+	*lval = strtod(yytext, NULL); return (NUMBER);
[-]{0,1}[0-9]+		*lval = strtod(yytext, NULL); return (NUMBER);
["\t"|" "]*			;
"\n"				;
.			std::cerr << "Not a valid file of point" << std::endl;
<<EOF>>			return (MEOF);
}
%%

void	lex_open (const std::string &name)
{
    yyin = fopen (name.c_str (), "r");
    
    if (!yyin)
	{
	    std::cerr << "cannot open `" <<
		name << "': " << strerror (errno) << std::endl;
	    exit (1);
	}
}

void	lex_close (void)
{
    fclose (yyin);
}
