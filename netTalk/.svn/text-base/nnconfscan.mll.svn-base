{
  open Nnconf;;
}

let myfloat = ['0'-'9']*'.'['0'-'9']*
let myint = ['0'-'9']*

rule lexer = parse
        [' ' '\t' '\n''\r''\n'] { lexer lexbuf }     (* bye bye blanc *)
        | ',' { COMMA }
        | '|' { PIPE }
	| "EPS=" {EPS}
	| "TL=" {TL}
	| "INPUT=" {INPUT}
	| "HIDDEN=" {HIDDEN}
	| "OUTPUT=" {OUTPUT}
        | myfloat { FLOAT (float_of_string (Lexing.lexeme lexbuf)) }
	| myint { INT (int_of_string (Lexing.lexeme lexbuf)) }
        | eof { EOF }
{
}
