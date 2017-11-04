open Ast
open Printer

let rec print_lcpl l = 
  match l with
      [] -> () 
    | a::q -> begin
	match a with
	    (c,d,e) ->
	    print_string "(";
	  printer_exp (c);
	  print_string ",";
	  printer_exp (d);
	  print_string ",";
	  printer_exp (e);
	  print_string ")";
	  print_lcpl q
      end
	  
let _ = 
  let toto = new Entity.entity (Ast.Binop(Ast.Times,Elt(Id(Identifier("x"))), Elt(Id(Identifier("y"))))) in
  let poly = toto#getPoly in
    print_lcpl poly
    
