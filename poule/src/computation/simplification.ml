open Astsig;;
open FloatInt;;

module Simplification(A:Astsig) =
struct
  
  module Ast = A
  module Ent = Entity.Entity(A)
  module Printer = Printer.Printer(A)
  module Algo = Algorithme.Algorithme(A)
  open Ast

  let rec comp_ast (f1, a1, e1) (f2, a2, e2) =
    if (e1 <> e2) then (e1 < e2)
    else
      match a1 with
	  Elt (Id (Identifier x)) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> (x < y)
	       | _ -> true)
	| Funccall(Identifier(f),e) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> f < g 
	       | _ -> true)
	| Min a -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall (f, g) -> false
	       | Min b -> comp_ast (f1, a, e1) (f1, b, e2)  
	       | _ -> true)
	| Binop (Plus, a, c) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> false
	       | Min(a) -> false
	       | Binop(Plus,b,d) -> comp_ast (f1,a,e1) (f1,b,e2) 
		   && not(comp_ast (f1,c,e1) (f1,d,e2))
	       | _ -> true)
	| Binop (Minus, a, c) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> false
	       | Binop (Plus, d, b) -> false
	       | Min a -> false
	       | Binop (Minus, b, d) -> comp_ast (f1, a, e1) (f1, b, e2) 
		   && not(comp_ast (f1,b,e1) (f1,d,e2))
	       |_ -> true)
	| Binop (Times, a, c) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> false
	       | Binop (Plus, d, b) -> false
	       | Binop (Minus, d, b) -> false
	       | Min a -> false
	       | Binop (Times, b, d) -> comp_ast (f1,a,e1) (f1,b,e2) 
		   && not(comp_ast (f1,b,e1) (f1,d,e2))
	       |_ -> true)
	| Binop (Div, a, c) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> false
	       | Min a -> false
	       | Binop (Plus, d, b) -> false
	       | Binop (Minus, d, b) -> false
	       | Binop (Times, d, b) -> false
	       | Binop(Div, b, d) -> comp_ast (f1,a,e1) (f1,b,e2) 
		   && not(comp_ast (f1,b,e1) (f1,d,e2))
	       |_ -> true)
	| Binop (Power, a, c) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall (Identifier g, h) -> false
	       | Min a -> false
	       | Binop (Plus, d, b) -> false
	       | Binop (Minus, d, b) -> false
	       | Binop (Times, d, b) -> false
	       | Binop (Power, b, d) -> comp_ast (f1,a,e1) (f1,b,e2) 
		   && not(comp_ast (f1,b,e1) (f1,d,e2))
	       | _ -> true)
	| Funcdec (Full (a, b, c, d), e) -> 
	    (match a2 with
		 Elt (Id (Identifier y)) -> false
	       | Funccall ((Identifier g), h) -> false
	       | Min a -> false
	       | Binop (Plus, f, g) -> false
	       | Binop (Minus, f, g) -> false
	       | Binop (Times, f, g) -> false
	       | Binop (Power, f, g) -> false
	       | Funcdec (Full (f, g, h, i), j) -> 
		   comp_ast (f1, c, e1) (f1, h, e2) 
	       | _ -> true)
	| _ -> false

  let rec sort_fact l =
    match l with
	[] -> [] 
      | [a] -> [a]
      | (r, b, c)::w ->
	  let (l1,l2) = List.partition (comp_ast (r,b,c)) w in
	    (sort_fact l1)@[(r,b,c)]@(sort_fact l2)

  let comp_ast2 (a, b) (c, d) =
    comp_ast (1, a, b) (1, c, d)
      
  let rec sort2 l =
    match l with
	[] -> []
      | [a] -> [a]
      | (b, c)::w ->
	  let (l1,l2) = List.partition (comp_ast2 (b,c)) w in
	    (sort2 l1)@[(b, c)]@(sort2 l2)

  let rec putmoins l =
      match l with
	  [] -> [] 
	|(p, v)::q -> (p, Min v)::(putmoins q)

  let rec put_infact ast =
    match ast with
	Elt x as e -> [(e, Elt (Integer (M.of_string_integer "1")))]
      | Funccall (f, g) as e -> 
	  [(e, (Elt (Integer (M.of_string_integer "1"))))]
      | Binop (Times, c, b) -> (put_infact c)@(put_infact b)
      | Binop (Div, c, b) -> (put_infact c)@(putmoins (put_infact b))
      | Binop (Power, c, b) -> [(c, b)]
      | e -> [(e, (Elt (Integer (M.of_string_integer "1"))))]	 

  let get_fact l v =
    let rec get_fact_rec l v ast =
      match l with
	  [] -> ast
	| (t, x)::q when (t = v) -> 
	   get_fact_rec q v (Ast.Binop(Ast.Plus, ast, x))
	| a::q -> get_fact_rec q v ast
    in
      get_fact_rec l v (Elt (Integer (M.of_string_integer "0")))

  let rec remove_fact l v =
    match l with
	[] -> []
      | (t, x)::q when (t = v) -> remove_fact q v 
      | (x, y)::q -> (x, y)::(remove_fact q v )
	    
  let rec fact_simpl l =
    match l with
	[] -> []
      |(var, t)::q -> let ast = get_fact l var in
	  (var, ast)::(fact_simpl (remove_fact q var))
  
  let get_term l v e=
    let rec get_term_rec l v e ast=
      if (e <> Elt(Integer(M.of_string_integer "0")))  then
	match l with
	    [] -> ast
	  | (t, x, y)::q when ((x = v) && (y = e)) -> 
	      get_term_rec q v e (Ast.Binop(Ast.Plus, ast, t))
	  | a::q -> get_term_rec q v e ast
      else
	match l with
	    [] -> ast
	  | (t, x, y)::q when (y = e)-> 
	      get_term_rec q v e (Ast.Binop(Ast.Plus, ast, t))
	  | a::q -> get_term_rec q v e ast
    in
      get_term_rec l v e (Elt(Integer(M.of_string_integer "0")))

  let rec remove_term l v e =
    if (e <> Elt (Integer (M.of_string_integer "0"))) then
      match l with
	  [] -> []
	| (t, x, y)::q when ((x = v) && (y = e))-> remove_term q v e
	| (x, y, z)::q -> (x, y, z)::(remove_term q v e)
    else
       match l with
	  [] -> []
	| (t, x, y)::q when (y = e)-> remove_term q v e
	| (x, y, z)::q -> (x,y,z)::(remove_term q v e)
	    
  let rec term_simpl l =
    match l with
	[] -> []
      |(t, var, exp)::q -> let ast = get_term l var exp in
	  (ast,var,exp)::(term_simpl (remove_term q var exp))
  
  let rec dumb_simpl ast =
    match ast with
      | Binop (Times, b, a) when b = Elt(Integer(M.of_string_integer "0")) -> 
	  dumb_simpl b
      | Binop (Times, a, b) when b = Elt(Integer(M.of_string_integer "0")) -> 
	  dumb_simpl b
      | Binop (Times, a, b) when b = Elt(Integer(M.of_string_integer "0")) -> 
	  dumb_simpl b
      | Binop(Times, a, b) when b = Elt(Integer(M.of_string_integer "1")) -> 
	  dumb_simpl a
      | Binop(Times, b, a) when b = Elt(Integer(M.of_string_integer "1")) -> 
	  dumb_simpl a
      | Binop (Times, a, b) -> 
	  (match (a, b) with
	       (Elt (Integer x), Elt (Integer y)) ->
		 Elt(Integer(M.mul_integer x y))
	     | (Elt (Float x), Elt (Float y)) ->
		 Elt(Float(M.mul_real x y))
	     | _ ->
		 let a1 = dumb_simpl a in
		 let b1 = dumb_simpl b in
		   if a1 = b1 then 
		     Binop(Power,a1, Elt(Integer(M.of_string_integer "2")))
		   else
		     (match (a1, b1) with
			  (Elt (Integer x), Elt (Integer y)) ->
			    Elt(Integer(M.mul_integer x y))
			| (Elt (Float x), Elt (Float y)) ->
			    Elt(Float(M.mul_real x y))
			| _ -> Binop (Times, a1, b1)))
      | Binop (Plus, b, a) when b = Elt(Integer(M.of_string_integer "0")) -> 
	  dumb_simpl a
      | Binop( Plus, a, b) when a = b -> 
	  dumb_simpl (Binop(Times, Elt(Integer(M.of_string_integer "2")), 
			    dumb_simpl a))
      | Binop (Plus, a, b) -> 
	  (match (a, b) with
	       (Elt (Integer x), Elt (Integer y)) ->
		 Elt (Integer (M.add_integer x y))
	     | (Elt (Float x ), Elt (Float y)) ->
		 Elt (Float (M.add_real x y))
	     | _ ->
		 let a1 = dumb_simpl a in
		 let b1 = dumb_simpl b in
		   if a1 = b1 then 
		     dumb_simpl
		       (Binop
			  (Times, Elt(Integer(M.of_string_integer "2")), a1))
		   else
		     (match (a1, b1) with
			  (Elt (Integer x), Elt (Integer y)) ->
			    Elt (Integer (M.add_integer x y))
			| (Elt (Float x), Elt (Float y)) ->
			    Elt (Float (M.add_real x y))
			| _ -> Binop (Plus, a1, b1)))

      (** Ajout JD **)

      | Binop (Minus, b, a) when b = Elt(Integer(M.of_string_integer "0")) -> 
	  Min (dumb_simpl a)
      | Binop (Minus, a, b) when a = b -> 
	  Elt (Integer (M.of_string_integer "0"))
      | Binop (Minus, a, b) -> 
	  (match (a, b) with
	       (Elt (Integer x), Elt (Integer y)) ->
		 Elt (Integer (M.sous_integer x y))
	     | (Elt (Float x ), Elt (Float y)) ->
		 Elt (Float (M.sous_real x y))
	     | _ ->
		 let a1 = dumb_simpl a in
		 let b1 = dumb_simpl b in
		   if a1 = b1 then 
		     Elt (Integer (M.of_string_integer "0"))
		   else
		     (match (a1, b1) with
			  (Elt (Integer x), Elt (Integer y)) ->
			    Elt (Integer (M.sous_integer x y))
			| (Elt (Float x), Elt (Float y)) ->
			    Elt (Float (M.sous_real x y))
			| _ -> Binop (Plus, a1, b1)))

      (** Fin Ajout JD **)

      | Binop (Div, b, a) when b = Elt(Integer(M.of_string_integer "0"))-> 
	  dumb_simpl b
      | Binop(Div, a, b) when b = Elt(Integer(M.of_string_integer "1")) -> 
	  dumb_simpl a
      | Binop (Div, a, b) -> 
	  (match (a,b) with
	       (Elt (Float x), Elt (Float y)) -> Elt(Float(M.div_real x y))
	     | _ ->
		 let a1 = dumb_simpl a in
		 let b1 = dumb_simpl b in
		   if a1 = b1 then 
		     Elt(Integer(M.of_string_integer "1"))
		   else
		     (match (a1,b1) with
			  (Elt (Float x), Elt (Float y)) ->
			    Elt (Float (M.mul_real x y))
			| _ -> Binop(Div,a1,b1)))
      | Binop (Power, b, c) when c = Elt(Integer(M.of_string_integer "1")) -> 
	  dumb_simpl b
      | Binop (Power, b, c) when b = Elt(Integer(M.of_string_integer "1")) -> 
	  dumb_simpl b
      | Binop (Power, b, c) when c = Elt(Integer(M.of_string_integer "-1")) -> 
	  Binop (Div, Elt (Integer (M.of_string_integer "1")), dumb_simpl b)
      | Binop (Power,b,c) when c = Min(Elt(Integer(M.of_string_integer "1"))) 
	  -> Binop (Div, Elt (Integer (M.of_string_integer "1")), dumb_simpl b)
      | Binop (Power, b, c) when c = Elt (Integer (M.of_string_integer "0")) ->
	  Elt (Integer (M.of_string_integer "1"))
      | Binop (Power, a, b)  ->
	  (match (a, b) with
	       (Elt (Integer x), Elt (Integer y)) ->
		 Algo.ei x y 
	     | _ -> 
		 let a1 = dumb_simpl a in
		 let b1 = dumb_simpl b in
		   (match (a1, b1) with
			(Elt (Integer x), Elt (Integer y)) ->
			  Algo.ei x y;
		      | _ -> Binop (Power, a1, b1)))
	  (*| Binop (a, b, c) -> (Binop (a, dumb_simpl b, dumb_simpl c))*)
      | Min a -> 
	  (match a with
	       Elt (Integer x) -> Elt (Integer (M.opp_integer x))
	     | Elt (Float x) -> Elt (Float (M.opp_real x))
	     | Min x -> dumb_simpl x
	     | x -> Min (dumb_simpl x))
      | a -> a


	 
  let rec facttoast l =
    let rec facttoastrec a acu=
	match a with 
	    []  -> acu
	  | (b, v)::t -> facttoastrec t (Binop(Times,
					       Binop (Power, b, v),
					       acu)) 
      in
      if l = [] then Elt (Integer (M.of_string_integer  "0"))
      else
	let (b, v) = List.hd l in
	  facttoastrec (List.tl l) (Binop(Power,b,v))


  let rec print_fact l =
    match l with
	[] ->()
      | (x, y)::q -> 
	  print_string ("("^(Printer.printer_exp x)^
	  ","^(Printer.printer_exp y)^")");
	  print_fact q
	  
  let rec simpl_term ast=
    let ent = new Ent.entity ast in
    let l = term_simpl (ent#getPoly) in
    let rec simpl_list l =
      match l with
	  [] -> []
	| (t, x, b)::q ->
	    let x1 =dumb_simpl x in
	    match x1 with 
		Binop (Times, d, e) -> 
		  (dumb_simpl t, simpl_fact 
		     (Binop (Times, d, e)), b)::(simpl_list q)
	      | Binop (Div, d, e) -> 
		  (dumb_simpl t, simpl_fact 
		     (Binop (Div, d, e)), b)::(simpl_list q)
	      | v -> (dumb_simpl t, v, b)::(simpl_list q)
    in
      ent#setPoly (sort_fact (simpl_list l));
      ent#getAst

  and simpl_fact ast=
    let f = put_infact ast in
    let l = fact_simpl f in
    let rec simpl_list l =
      match l with
	  [] -> []
	|(x,t)::q ->
	    let x1 =dumb_simpl x in
	      match x1 with
		| Binop(Plus,d,e)
		  -> (simpl_term (Binop(Plus,d,e)),dumb_simpl t)::(simpl_list q)
		| Binop(Minus,d,e)
		  -> (simpl_term (Binop(Minus,d,e)),dumb_simpl t)::(simpl_list q)
		| v -> (v,dumb_simpl t)::(simpl_list q)
      		    
    in
      facttoast (simpl_list l)
  
  let simplifyExp exp =
    let ast2 = simpl_term exp in
    let ast3 = simpl_fact (dumb_simpl ast2) in
    let ast4 = simpl_term (dumb_simpl ast3) in
    let ast_old = ref(simpl_fact (dumb_simpl ast4)) in
    let astr = ref(dumb_simpl (!ast_old)) in
      while (!astr <> !ast_old) do
	ast_old :=  !(astr);
	astr := (dumb_simpl (!ast_old));
      done;
      !astr
    
  let simplify ast =
    match ast with
	Exp exp -> Exp (simplifyExp exp)
      | Assign assign -> ast

end
