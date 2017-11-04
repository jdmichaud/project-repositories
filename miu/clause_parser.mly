/* File parser.mly */
  
%token <string> CST VAR
%token OR COMMA NOT NOT TRUE FALSE
%token LPAREN RPAREN LBRACE RBRACE
%token EOL
%token EOF

%start exp             /* the entry point */
    
%type <Type_t.t> exp clause predicate predicates_arg
%type <Type_t.t> symbol

%%
    exp: clause EOF { $1 };
    
    clause: { Type_t.Empty }
  | predicate { $1 }
  | clause OR predicate { Type_t.Or ($1, $3) };
    
    predicate: TRUE { Type_t.True }
  | FALSE { Type_t.False }
  | CST { Type_t.SCst $1 }
  | VAR { Type_t.Var $1 }
  | NOT predicate { Type_t.Not $2 }
  | CST LPAREN predicates_arg RPAREN { Type_t.Cst ($1, $3) };

    predicates_arg: symbol { $1 }
  | predicates_arg COMMA predicate { Type_t.Arg ($1, $3) };

    symbol: CST { Type_t.SCst $1 }
  | VAR { Type_t.Var $1 };
%%
