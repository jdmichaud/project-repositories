%{
  open Astsig;;

  module Parser(A:Astsig)=
  struct
    open A

  exception Test
%}
%token <string> INTEGER
%token <string> FLOAT
%token <string> ID
%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token LBRACKET
%token RBRACKET
%token PIPE
%token TIMECARTH
%token COMMA
%token DOT
%token COLON
%token SEMICOLON
%token PLUS
%token MINUS
%token TIMES
%token DIVIDE
%token POWER
%token EQUAL
%token SUP
%token INTER
%token UNION
%token WITHOUT
%token WITH
%token AND
%token ARROW
%token EOL
%token INF
%token EOF

%left ID
%left COLON
%left EQUAL
%left PLUS MINUS UNION WITHOUT
%left POWER TIMES DIVIDE INTER TIMECARTH
%left ARROW
%left RPAREN COMMA SEMICOLON
%left AND


%start main
%type <ast*bool> main
%type <ast> line
%type <elt> elt
%type <exp list> args
%type <set> ens
%type <set> assens
%type <elt list> ens_enum
%type <relation> relation
%type <assign list> optfun
%type <exp> funcdec 
%type <assign> assign
%type <assign> assignexp
%type <assign> assignens
%type <exp> exp

%%
main:
	line SEMICOLON EOL {($1,false)}
	| line SEMICOLON SEMICOLON EOL {($1,true)}
;

line:
        exp {Exp($1)}
	| assign {Assign($1)}
;

exp:
	elt {Elt($1)}
	| ID LPAREN RPAREN {Funccall(Identifier($1),[])}
	| ID LPAREN args RPAREN {Funccall(Identifier($1),$3)} 
	| exp PLUS exp {Binop(Plus,$1,$3)}
	| exp MINUS exp {Binop(Minus,$1,$3)}
	| exp TIMES exp {Binop(Times,$1,$3)}
	| exp DIVIDE exp {Binop(Div,$1,$3)}
	| exp POWER exp {Binop(Power,$1,$3)}
	| MINUS exp {Min($2)}
	| LPAREN exp RPAREN {$2}
	| funcdec {$1}
;


assign:
        assignens {$1}
	| assignexp {$1}
;


elt:
	INTEGER {Integer(A.M.of_string_integer $1)}
	| FLOAT {Float(A.M.of_string_real $1)}
	| ID { Id(Identifier($1))}
	| INF { Inf }
;

ens:

	ID {Idens (Identifier($1))}
	| LPAREN ens RPAREN {$2}
	| ens TIMECARTH ens {TimesCarth($1, $3)}
	| ens INTER ens {Inter($1, $3)}
	| ens UNION ens {Union($1, $3)}
	| ens WITHOUT ens {Without($1, $3)}
	| LBRACE RBRACE {Enum([])}
	| LBRACE ens_enum RBRACE {Enum($2)}
	| LBRACKET exp COMMA exp LBRACKET {Borned($2, true, $4, false)}
	| LBRACKET exp COMMA exp RBRACKET {Borned($2, true, $4, true)}
	| RBRACKET exp COMMA exp RBRACKET {Borned($2, false, $4, true)}
	| RBRACKET exp COMMA exp LBRACKET 
	    {Borned($2, false, $4, false)} 
	| LBRACKET PIPE exp COMMA exp PIPE LBRACKET 
	    {IntBorned($3, true, $5, false)}
	| LBRACKET PIPE exp COMMA exp PIPE RBRACKET 
	    {IntBorned($3, true, $5, true)}
	| RBRACKET PIPE exp COMMA exp PIPE RBRACKET 
	    {IntBorned($3, false, $5, true)}
	| RBRACKET PIPE exp COMMA exp PIPE LBRACKET 
	    {IntBorned($3, false, $5, false)} 
;

assens:

   	ens TIMECARTH ens {TimesCarth($1, $3)}
	| ens INTER ens {Inter($1, $3)}
	| ens UNION ens {Union($1, $3)}
	| ens WITHOUT ens {Without($1, $3)}
	| LBRACE RBRACE {Enum([])}
	| LBRACE ens_enum RBRACE {Enum($2)}
	| LBRACKET exp COMMA exp LBRACKET {Borned($2, true, $4, false)}
	| LBRACKET exp COMMA exp RBRACKET {Borned($2, true, $4, true)}
	| RBRACKET exp COMMA exp RBRACKET {Borned($2, false, $4, true)}
	| RBRACKET exp COMMA exp LBRACKET 
	    {Borned($2, false, $4, false)} 
	| LBRACKET PIPE exp COMMA exp PIPE LBRACKET 
	    {IntBorned($3, true, $5, false)}
	| LBRACKET PIPE exp COMMA exp PIPE RBRACKET 
	    {IntBorned($3, true, $5, true)}
	| RBRACKET PIPE exp COMMA exp PIPE RBRACKET 
	    {IntBorned($3, false, $5, true)}
	| RBRACKET PIPE exp COMMA exp PIPE LBRACKET 
	    {IntBorned($3, false, $5, false)} 
;

assignexp:
	ID EQUAL exp {Assignexp(Identifier($1),$3)}
;

assignens:
	ID COLON EQUAL assens {Assignens(Identifier($1),$4)}
;

ens_enum:
	elt {[$1]}
	| elt SEMICOLON ens_enum {$1::$3}
;

args:
	exp {[$1]}
	| exp COMMA args {$1::$3}
;

funcdec:
	LPAREN relation RPAREN {Funcdec($2,[])}
	| LPAREN relation WITH optfun RPAREN {Funcdec($2,$4)}
;

lvarid:
	ID {Identifier($1)::[]}
	| ID COMMA lvarid {Identifier($1)::$3}

relation:
	lvarid COLON ens ARROW exp COLON ens {Full($1,$3,$5,$7)}
	|lvarid ARROW exp {Poly($1,$3)}
;


optfun:
	ID EQUAL relation {[Assignexp(Identifier($1), 
					 Funcdec($3,[]))]}
	| ID EQUAL relation AND optfun {Assignexp(Identifier($1), 
					 Funcdec($3,[]))::$5}
;


%%


end
