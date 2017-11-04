(*pp camlp4o *)
(* formal_system.ml *)

open Formal_system

module Resolution : FORMAL_SYSTEM =
  struct
    type t = Type_t.t
(* Conversions. *)
    let of_string s = 
      let lexbuf = Lexing.from_string s in
      let result = Clause_parser.exp Clause_lexer.token lexbuf in 
	result
 
    let to_string c = 
      let rec translate c =
	match c with
	    Type_t.Empty | Type_t.Notcutted -> ""
	  | Type_t.True -> "True"
	  | Type_t.False -> "False"
	  | Type_t.Cst (str, q) -> str^" ("^translate q^")"
	  | Type_t.SCst str -> str
	  | Type_t.Var str -> str
	  | Type_t.Not q -> "Not "^translate q
	  | Type_t.Or (q1, q2) -> translate q1^" Or "^translate q2
	  | Type_t.And (q1, q2) -> translate q1^" And "^translate q2
	  | Type_t.Arg (q1, q2) -> translate q1^", "^translate q2
	  | Type_t.Clause (q1, q2) -> 
	      let rec print_clause l sep =
		match l with
		    h::q when (List.length q < 1) -> translate h
		  | h::q -> translate h^sep^(print_clause q sep)
		  | [] -> ""
	      in
		(print_clause q1 " & ")^" -> "^(print_clause q2 " | ")
	  | Type_t.Theory (c1, c2) -> "{ "^translate c1^" }"^translate c2
	  | Type_t.Imp (c1, c2) -> translate c1^" -> "^translate c2
      in
	translate c

    let of_stream s = 
      let rec parse s = 
	match s with parser 
	    [< 'str ; queue >] -> 
	      let lexbuf = Lexing.from_string str in
	      let result = Clause_parser.exp Clause_lexer.token lexbuf in
	      let t = parse queue in
		if t = Type_t.Empty then
		  result
		else
		  Type_t.And (result, t)
	  | [<>] -> Type_t.Empty
      in
	parse s

    let to_stream (c : Type_t.t) = 
      let rec translate c =
	match c with
	    Type_t.Empty -> [<>]
	  | Type_t.True -> [< '"True" >]
	  | Type_t.False -> [< '"False" >]
	  | Type_t.Cst (str, q) -> [< '(str^" ("^(to_string q)^")") >]
	  | Type_t.SCst str -> [< 'str >]
	  | Type_t.Var str -> [< 'str >]
	  | Type_t.Not q -> [< '("Not "^(to_string q)) >]
	  | Type_t.Or (q1, q2) -> [< '(to_string q1) ; '(to_string q2) >]
	  | Type_t.And (q1, q2) -> [< '(to_string q1) ; '(to_string q2) >]
	  | Type_t.Arg (q1, q2) -> [< '((to_string q1)^", "^(to_string q2)) >]
	  | Type_t.Theory (q1, q2) -> [<  '(to_string q1) ;  '(to_string q2) >]
	  | Type_t.Imp (c1, c2) -> [< translate c1 ; translate c2 >]
	  | _ -> [<>]
      in
	translate c

(* Prove. *)

    let rec show_clauses l =
      match l with
	  h::q -> print_string ((to_string h)^"\n"); show_clauses q
	| [] -> ()
	    

   let prove l c = 
     try
       let formules = Resolution_transform.divide c in
       let clauses = Resolution_transform.make_clauses formules in
       let sub = Resolution_transform.substitute clauses in
	 true
     with
	 Resolution_transform.Contradiction -> 
	   print_string "Contradiction found\n";
	   false
       | Resolution_transform.Proved -> 
	   true
       | Resolution_transform.Seche -> 
	   false
	     
	     
   let prove_trace output l c = prove l c
				  
				  
  end;;
