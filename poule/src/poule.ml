open Options
open Options

let _ = 
  match Array.length Sys.argv with
      1 -> option_ ()
    | _ -> 
	let invalid_arg a = () in
	  Arg.parse [("--inline", Arg.String option_inline,
		      "take an equation in call line");
		     ("--latex", Arg.String option_latex,
		      "<filename> make a LaTeX output");
		     ("--version", Arg.Unit option_version,
		      "Print the project version");
		     ("--authors", Arg.Unit option_authors, 
		      "Print the project authors");
		     (*("--gtk", Arg.Unit option_gtk, 
		       "Run the gtk-graphic editor");*)
		     ("--help", Arg.Unit option_help, 
		      "Print the project help")]
	      invalid_arg "Usage: poule [options]\n"
		      
