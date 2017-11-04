{
open Clause_parser        (* The type token is defined in clause_parser.mli *)
}

  rule token = parse
(*  [' ' '\t']     { token lexbuf }     (* skip blanks *) *)
(* | ['\n']         { Printf.printf ("eol\n"); EOL } *) 
  [',']		 { COMMA }
| ['|']          { OR }
| ['(']          { LPAREN }
| [')']          { RPAREN }
| ['{']		 { LBRACE }
| ['}']		 { RBRACE }
| "not"		 { NOT }
| "true"	 { TRUE }
| "false"	 { FALSE }
| ['A'-'Z']['A'-'Z' 'a'-'z' '_']* { VAR(Lexing.lexeme lexbuf) }
| ['a'-'z']+     { CST(Lexing.lexeme lexbuf) }
| eof		 { EOF }
| _|'\n'	 { token lexbuf }
