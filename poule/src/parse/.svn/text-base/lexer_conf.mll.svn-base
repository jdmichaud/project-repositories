{
  open Parser_conf;; 
}

rule token = parse
    '\n'		{ EOL }
  | eof			{ EOF }
  | [^'\n']*		{ EXP (Lexing.lexeme lexbuf) }
