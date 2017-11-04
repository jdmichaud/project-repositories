(** This file describes the options of Poule **)

module Ast = Ast.Ast(FloatInt.FloatInt)
module Parser = Parser_line.Parser(Ast) 
module Printer = Printer.Printer(Ast) 
module Latex = Latex.Latex (Ast) 
module Env = Enviro.Enviro (Ast)
module Interpreteur = Interpreteur.Interpreteur (Ast)
			
module Options =
struct 

  (** The basic option with only the toplevel **)
  let option_ () = Toplevel.Toplevel.toplevel false

  (** Print the actual version of Poule **)
  let option_version () = 
    print_string "The Poule Intelligence, version 0.1";
    print_newline ()

  (** Print the names of the authors of Poule **)
  let option_authors () = 
    print_string "Metais Nicolas - metais_n@epita.fr ";
    print_newline ();
    print_string "Michaud Jean-Daniel - michau_j@epita.fr ";
    print_newline ();
    print_string "Mimouni Jonathan - mimoun_j@epita.fr ";
    print_newline ();
    print_string "Morlot Francois - morlot_f@epita.fr ";
    print_newline ()
      
  (** Explains you how to use Poule **)
  let option_help () = 
    print_string "Poule is a formal computation platform.";
    print_newline ();
    print_string "Usage: poule [options]";
    print_newline ();
    print_string "Options:";
    print_newline ();
    print_string "  --inline		Take an expression and evaluate it";
    print_newline ();
    print_string "  --help		Display this information";
    print_newline ();
    print_string "  --version		Display the project version";
    print_newline ();
    print_string "  --authors		Display the project authors";
    print_newline ();
    print_string "With no options, Poule launches a top level.";
    print_newline ()
      
  let option_latex file = Toplevel.Toplevel.toplevel true

  let option_inline line =
    try 
      let lexbuf_line = Lexing.from_string (line^"\n") in
      let (ast, exactEvaluation) = Parser.main Lexer_line.token lexbuf_line in
      let env = new Env.enviro in
	print_string 
	  (Printer.printer_ast 
	     (Interpreteur.interpreteur ast env exactEvaluation true));
	print_newline ()
    with 
	Parsing.Parse_error -> prerr_string "Parse error";
	  prerr_newline ();
	  flush stderr
	  
end
