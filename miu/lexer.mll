{
open Parser        (* The type token is defined in clause_parser.mli *)
}

rule token = parse
    eof				{ EOF }
  | _+|['\n']+			{ CMD(Lexing.lexeme lexbuf) }
