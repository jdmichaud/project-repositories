%{
  open Network
%}

%token          COMMA
%token		PIPE
%token		EPS
%token		TL
%token		INPUT
%token		HIDDEN
%token		OUTPUT
%token <float>	FLOAT
%token <int>	INT
%token          EOF
  

%start main
%type <float * Network.network> main
%type <Network.network> rezal
%type <float> eps 
%% 
  

main :	eps rezal	{($1,$2)}
;

eps: EPS FLOAT {$2}
;

rezal: TL INT INPUT INT HIDDEN INT OUTPUT INT {Createnn.create $4 $2 $6 $8}
;
 
