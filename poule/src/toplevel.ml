open Sys;;
open Cmd_line;;

module Toplevel =
struct 
  module Ast = Ast.Ast (FloatInt.FloatInt)
  module Parser = Parser_line.Parser (Ast) 
  module Env = Enviro.Enviro (Ast)
  module Printer = Printer.Printer(Ast) 
  module Latex = Latex.Latex (Ast) 
  module Interpreteur = Interpreteur.Interpreteur (Ast)

  let envCreation configurationFile =
    let env = new Env.enviro in
    let env_conf = Lexing.from_channel (open_in configurationFile) in
    let conf_list = Parser_conf.conf Lexer_conf.token env_conf in
    let rec conf_rec l =
      match l with
	  [] -> env
	| h::t ->
	    (try 
	       let lexbuf = Lexing.from_string h in
	       let line = Parser_toplevel.line Lexer_toplevel.token lexbuf in
	       let lexbuf_line = Lexing.from_string line in
	       let (ast,b) = 
		 Parser.main Lexer_line.token lexbuf_line in
	       let res = Interpreteur.interpreteur ast env false false in ()
	     with 
		 Parsing.Parse_error -> 
		   prerr_string 
		   (configurationFile^": Parse error in configuration file");
		   prerr_newline ();
	       | Lexer_toplevel.Eof -> ());
	    conf_rec t;
    in
      conf_rec conf_list

  let toplevel latexOutput = 
      let env = envCreation "./poule.conf" in
	while true do
	  try
	    let lexbuf = Lexing.from_string (cmd_c ()) in
	    let line = Parser_toplevel.line Lexer_toplevel.token lexbuf in
	    let lexbuf_line = Lexing.from_string line in
	    let (ast, exactEvaluation) = 
	      Parser.main Lexer_line.token lexbuf_line in
	    let res = Interpreteur.interpreteur ast env exactEvaluation true in
	      if latexOutput then
		begin
		  print_string (Latex.latexPrinter res);
		  print_newline ()
		end
	      else
		begin
		  print_string (Printer.printer_ast res);
		  print_newline ()
		end
	  with 
	      Lexer_toplevel.Eof -> exit 0; ()
	    | Parsing.Parse_error -> print_string "Parse error"; 
		print_newline ();
	done
	
end
