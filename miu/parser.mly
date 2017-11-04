%token <string> CMD
%token EOF

%start input             /* the entry point */

%type <string> input

%%
  input: EOF { "" }
| CMD EOF { $1 }
%%
