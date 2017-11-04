{
  open Parser_toplevel;; (* The token type is defined in parser_toplevel.mli *)
  exception Eof;;
}

rule token = parse
    '\n'		{ EOL }
  | eof			{ raise Eof }
  | [^'\n']*		{ EXP (Lexing.lexeme lexbuf) }
