{
  open Nndesc;;
}

let myfloat = ['0'-'9']*'.'['0'-'9']*
let myantifloat = '-'['0'-'9']*'.'['0'-'9']*

rule lexer = parse
        [' ' '\t' '\n''\r''\n'] { lexer lexbuf }     (* bye bye blanc *)
        | ',' { COMMA }
        | '|' { PIPE }
	| "#" { SEP }
	| "B:" { BIAIS}
        | myfloat { FLOAT (float_of_string (Lexing.lexeme lexbuf)) }
	|myantifloat{ FLOAT (float_of_string (Lexing.lexeme lexbuf)) }
        | eof { EOF }
{
}
