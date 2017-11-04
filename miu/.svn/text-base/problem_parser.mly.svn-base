%token <string> EXP
%token LBRACE RBRACE COMMA SEMI

%start problem             /* the entry point */

%type <string list> theory problem

%%
  problem: LBRACE theory RBRACE EXP { $2@[$4] };
  
  theory: EXP { [$1] }
| EXP SEMI theory { [$1]@$3 };
      
%%
