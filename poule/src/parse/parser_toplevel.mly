%token <string> EXP
%token EOL

%type <string> line

%start line

%%

line: EXP EOL  	 			{ $1 ^ "\n"};
  
