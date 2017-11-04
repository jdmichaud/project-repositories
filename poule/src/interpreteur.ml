
open Astsig
module Interpreteur (Ast:Astsig) =
  struct
    open Ast
    
    module Simpl = Simplification.Simplification(Ast)
    module Printer = Printer.Printer(Ast)
    module Sub = Substitution.Substitution (Ast)	       
    module Eval = Eval.Eval(Ast)
    module Deriv = Derivate.Derivate (Ast)
    module Ent = Entity.Entity (Ast)		    
    module Env = Enviro.Enviro (Ast)	   
    module Chk = Check.Check (Ast)
		 
    exception Builtin

    let rec put_with f l =
      match l with
	  [] -> ()
	|a::q -> match a with
	      Assignexp (Identifier i, e) -> 
		(match i with
		   | "derivate" -> f#setDeriv (Env.Ent(new Ent.entity e));
		       put_with f q
		   | "primitive" -> f#setPrim (Env.Ent(new Ent.entity e));
		       put_with f q
		   | "replacable" -> 
		       (match e with
			  | Funcdec (Poly (_, Elt (Integer (id))), []) 
			      when id = M.of_string_integer "0" ->
 			      f#setReplacable false;
				put_with f q
			  | Funcdec (Poly (_, Elt (Integer (id))), [])
			      when id = M.of_string_integer "1" ->
			      f#setReplacable true;
				put_with f q
			  | _ -> put_with f q)
		   |_ -> put_with f q)
	    | _ -> put_with f q
		

    let evalsimpl ast env eval =
      if eval then
	try
	  Eval.evalAst env (Sub.substitute ast env)
	with
	    Eval.Div_zero -> print_string "Division by 0"; 
	      print_newline ();
	      ast
	  | Eval.Late_type_error ->print_string "Late Type error"; 
	      print_newline ();
	      ast
	  | Sub.ArgNbr -> print_string "Bad parameters number";
	      print_newline ();
	      ast
	  | Sub.Incompatible_type -> ast
      else
	try
	  Simpl.simplify (Sub.substitute ast env)
	with
	    Sub.FuncArgNbr(s) -> 
	      print_string ("Bad arg number for"^s);
	      print_newline ();
	      ast

    let builtins f env eval =
      match f with
	  Funccall (Identifier(s),args) ->
	     (match s with
		  "derivate" -> 
		    (try
		       (Simpl.simplifyExp
			  (Deriv.derivate 
			     (Simpl.simplify 
				(Sub.substitute 
				   (Exp(List.hd args)) env)) (List.tl args) 
			     env))
		     with 
			 Deriv.DerExce -> print_string "Can't derive";
			   f
		       | Sub.FuncArgNbr s -> 
			   print_string ("Bad arg number for"^s);
			   print_newline ();
			   f)
		| "rearm" -> env#rein (); f
		| "env" -> env#showEnv; f
		|_ ->  f)
	| _ ->  f

    let interpreteur ast env eval substitute =
      try
	if substitute then begin
	  Chk.checkFunccallOnly ast env;
	  Chk.check_ast (Sub.substitute ast env) env
	end
	else
	  Chk.check_ast ast env;
	match ast with
	    Exp e -> 
	      (match e with
		   Funccall(a,b) -> 
		     evalsimpl (Exp(builtins e env eval)) env eval 
		 | _ -> evalsimpl ast env eval)
	  | Assign e -> 
	      (match e with
	           Assignexp (i, a) -> 
		     (match a with 
			  Funcdec (x, y) -> env#addFun i x;
			    put_with (env#getFun i) y;
			    ast
			| _ -> Chk.checkAssign i a; env#addVar i a; ast)
		 | Assignens (i, a) -> Chk.checkAssignSet i a; 
		     env#addSet i a; 
		     ast)
	with 
	    Chk.TYPE_ERROR -> 
	      print_string "Type checking error";
	      print_newline ();
	      ast
	  | Chk.SET_ERROR -> 
	      print_string "Argument not in set";
	      print_newline ();
	      ast
	  | Chk.NOT_ELT -> 
	      print_string "Internal Error";
	      print_newline ();
	      ast
	  | Chk.RCRSV_DEF id -> 
	      print_string ("Recursive definition for "^id);	
	      print_newline ();
	      ast
	  | Sub.Incompatible_type -> ast
	  | Sub.ArgNbr -> 
	      print_string "Bad parameters number";
	      print_newline ();
	      ast
		
	    
  end
  
