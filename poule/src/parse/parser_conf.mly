%token <string> EXP

%token EOL
%token EOF

%type <string list> conf
%type <string list> txt

%start conf

%%

conf:
	txt EOF{$1}
;

txt:
  EOL {[]}
  | EOL txt {$2}
  | EXP EOL {[$1^"\n"]}
  | EXP EOL txt {($1^"\n")::$3}
;
