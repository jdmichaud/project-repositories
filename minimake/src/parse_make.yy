//
// parse_make.yy for minimake in 
 
// Made by jean-daniel michaud
// Login   <michau_j@epita.fr>
 
// Started on  Sat Feb 16 07:15:46 2002 jean-daniel michaud
// Last update Sun Feb 24 16:38:05 2002 jean-daniel michaud

%{								// -*- C++ -*-
#include <iostream>
#include <string>
#include <errno.h>
#include "graph.hh"
#include "var.hh"
#include "parse.hh"

using namespace std;

#define YYDEBUG	1
#define YYERROR_VERBOSE	1

#define YYPRINT(file, type, value)   yyprint (type, value)
#define yyerror(Msg)   parse_error (Msg)

list<string>	deps;
list<string>	actions;
list<string>	vars;
extern Graph	graph;


void parse_error (const char *msg);
static void yyprint (int type, const union yystype value);

%}
%union		yystype
{
  int		integer;
  string	*str;
}

%pure_parser
%start makefile

%token CR		"\n"
%token NAME		"NAME"
%token COLON		":"
%token ACTION		"ACTION"
%token TAB		"TAB"
%token EQ		"="
%token VARDEC		"DEC"
%token BACKSLASH	"\\"
%token ID		"ID"
%token DOLLAR		"$"
%token LPAREN		"("
%token RPAREN		")"

%right CR

%%
makefile :
    {}
  | makefile rule {}
  | makefile NAME EQ VARDEC CR { graph.addVar(Variable(*$<str>2, *$<str>4)); }
  | makefile CR {}
;

rule : 
  NAME COLON pre CR actions 
	{ 
	  graph.add(*$<str>1, actions, deps);
	  actions.clear();
	  deps.clear();
	}


actions :
    {}
  | actions ACTION { actions.push_front(*$<str>2); }
  | actions CR {}
;

pre : 
    {}
  | namelist {}
;

namelist : 
    NAME { deps.push_back(*$<str>1); }
  | namelist NAME { deps.push_back(*$<str>2); }
;

%%

void		parse_error(const char *msg)
{
  cout << msg << endl;
  exit(2);
}

static void	yyprint(int type, const union yystype value)
{
  switch (type)
    {
    case VARDEC: {
      cerr << " " << value.str->data();
      break;
    }
    case ACTION: {
      cerr << " " << value.str->data();
      break;
    }
    case NAME: {
      cerr << " " << value.str->data();
      break;
    }
    }
}
