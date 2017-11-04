{
open Problem_parser        (* The type token is defined in clause_parser.mli *)
}

rule token = parse
    ['{']		 { LBRACE }
  | ['}']		 { RBRACE }
  | [';']		 { SEMI }
  | ['a'-'z' 'A'-'Z' '0'-'9' '|' '(' ')' ' ' '\t' '\n' ',']+		 
    { EXP(Lexing.lexeme lexbuf) }
