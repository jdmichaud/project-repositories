(* interpreter.ml *)

open Resolution;;

module type S =
sig
  val eval : string -> bool -> out_channel -> int
  val toplevel : unit -> unit
end

module Make (Fs : Formal_system.FORMAL_SYSTEM) : S =
struct
  let eval input b output = 
    let lexbuf = Lexing.from_string input in
    let result = Problem_parser.problem Problem_lexer.token lexbuf in
    let s = Stream.of_list result in 
    let clauses = Fs.of_stream s in 
      match (Fs.prove [] clauses) with
	  true -> 1
	| false -> 0
      
  let rec toplevel () = 
    try
      let lexbuf = Lexing.from_channel stdin in
	while true do
	  print_string "Ready\n";
	  flush stdout;
	  let result = Parser.input Lexer.token lexbuf in
	    match (eval result false stdout) with
		0 -> print_string "*** Problem true\n"
	      | 1 -> print_string "*** Problem false\n"
	      | 2 -> print_string "*** mmm, Dont know\n"
	      | _ -> print_string "***\n"
	done
    with
	Parsing.Parse_error -> 
	  print_string "miu interpreter: Parse error\n";
	  toplevel ()
      | Failure str ->
	  print_string "miu interpreter: Stop\n"
	  
end


