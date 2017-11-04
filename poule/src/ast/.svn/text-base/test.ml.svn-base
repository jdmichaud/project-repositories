let rec print_lcpl l = 
  match l with
      [] -> () 
    | a::q -> begin
	print_string "(";
	Printer.printer_exp (fst a);
	print_string ",";
	Printer.printer_exp (snd a);
	print_string ")";
	print_lcpl q
      end
	  
let _ = 
  let toto = entity Ast.Binop(Plus,Elt(Id(Identifier("x"))), Elt(Integer("1")))
	           Identifier("x") in
  let poly = getPoly in
    print_lcpl poly
    
