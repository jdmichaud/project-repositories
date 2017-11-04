%{
%}

%token          COMMA
%token		PIPE
%token <float>	FLOAT
%token <int>	INT
%token          BIAIS
%token		SEP
%token          EOF
  
%start main
%type <(float list list * float) list * (float list * float) list > main 
%type <(float list list * float) list> tlall
%type <(float list * float) list> nnall
%type <float list list> tllists
%type <float list> tllist nnlist
%% 
  

main :	tlall  SEP  nnall  {($1,$3)}
;

tlall: tllists BIAIS FLOAT { [($1,$3)] }  
| tllists BIAIS FLOAT tlall { ($1,$3) :: $4 }
;

tllists: tllist { [$1] }
| tllist tllists {  $1 :: $2 }
;

tllist: FLOAT	{ [$1] }
| FLOAT COMMA tllist { $1 :: $3 }   
;

nnall: nnlist BIAIS FLOAT {[($1,$3)]}
| nnlist BIAIS FLOAT nnall{ ($1, $3):: $4 }
;

nnlist: FLOAT { [$1] }
| FLOAT nnlist { $1 :: $2 }
;
