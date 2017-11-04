{
  open Parser_line
  exception Eof 
}

rule token = parse
    eof					{ raise Eof }
  | [' ''\t']				{ token lexbuf }
  | '\n'				{ EOL }
  |"INTER"				{ INTER }
  |"UNION"				{ UNION }
  |"WITH"				{ WITH }
  |"AND"				{ AND }
  |"INF"				{ INF }
  |"|->"				{ ARROW }
  |['0'-'9']+				{ INTEGER (Lexing.lexeme lexbuf) }
  |['0'-'9']*['.']['0'-'9']+		{ FLOAT (Lexing.lexeme lexbuf) }
  |['A'-'Z''a'-'z']+			{ ID (Lexing.lexeme lexbuf) }
  |"**"                                 { TIMECARTH }
  |'('					{ LPAREN }
  |')'					{ RPAREN }
  |'{'					{ LBRACE }
  |'}'					{ RBRACE }
  |'['					{ LBRACKET }
  |']'					{ RBRACKET }
  |'|'					{ PIPE }
  |','					{ COMMA }
  |'.'					{ DOT }
  |':'					{ COLON }
  |';'					{ SEMICOLON }
  |'+'					{ PLUS }
  |'-'					{ MINUS }
  |'*'					{ TIMES }
  |'/'					{ DIVIDE }
  |'^'					{ POWER }
  |'='					{ EQUAL }
  |'>'					{ SUP }
  |'\\'					{ WITHOUT }
  | _					{ EOL }
 
