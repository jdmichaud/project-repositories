(*pp camlp4o *)
open Resolution;;
open Interpreteur;;

module Cmd_line = Make (Resolution)

let main =
  try
    if (Array.length Sys.argv) > 1 then
      if (Sys.argv.(1) = "-e" && Array.length Sys.argv > 2) then
	begin
	  exit (Cmd_line.eval Sys.argv.(2) false stdout)
	end
      else
	begin
	  print_string "miu: unknown parameter\n";
	  2
	end
    else
      begin
	print_string "\n MIU 1.0\n\n";
	Cmd_line.toplevel ();
	0
      end
  with
      Parsing.Parse_error -> 
	print_string "miu: Parse error\n"; 
	exit 2
	  
      

