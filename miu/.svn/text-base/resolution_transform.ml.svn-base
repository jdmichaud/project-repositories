
exception Contradiction
exception Proved
exception Seche
	
let qwerty c = 
  let rec translate c =
    match c with
	Type_t.Empty | Type_t.Notcutted -> "-"
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

let clause_of_t l =
  let rec sort_predicats predicat couples =
    let (ai, bi) = couples in
      match predicat with
	  (Type_t.Not a)::b -> sort_predicats b (a::ai, bi)
	| a::b -> sort_predicats b (ai, a::bi)
	| [] -> (ai, bi)
  in
    Type_t.Clause (sort_predicats l ([], []))
      
let rec atomize c =
  match c with
      Type_t.Or (c1, c2) -> atomize c1@atomize c2
    | Type_t.Cst (str, c) -> [Type_t.Cst (str, c)]
    | Type_t.Not c -> [Type_t.Not (c)]
    | _ -> []
	
let rec make_clauses formules =
  match formules with
      h::q -> clause_of_t (atomize (h))::make_clauses q
    | [] -> []
	
let rec divide ast = 
  match ast with
      Type_t.And (q1, q2) -> 
	(match q1 with
	     Type_t.And (c1, c2) -> 
	       (match q2 with
		    Type_t.And (c3, c4) ->
		      (divide q1)@(divide q2)
		  | _ -> (divide q1)@[q2])
	   | _ -> (match q2 with
		       Type_t.And (c3, c4) ->
			 [q1]@(divide q2)
		     | _ -> [q1]@[q2]))
    | _ -> []

let rec coupure clause1 clause2 =
  let tranche clause =
    match clause with
	Type_t.Clause (a, b) -> 
	  let rec doublon list1 list2 =
	    match list1 with
		h::q ->
		  let rec doublon_ elm list = 
		    match list with
			x::xs -> if (x = elm) then x::(doublon_ elm xs)
			else  doublon_ elm xs
		      | [] -> []
		  in
		    (doublon_ h list2)@(doublon q list2)
	      | [] -> []
	  in 
	  let db = doublon a b in
	  let rec suppr list1 list2 =
	    match list1 with
		h::q -> 
		  let rec suppr_ elm list =
		    match list with
			x::xs when (x = elm) -> suppr_ elm xs
		      | x::xs -> x::suppr_ elm xs
		      | [] -> []
		  in
		    suppr_ h list2
	      | [] -> list2
	  in
	    ((suppr db a), (suppr db b))
      | _ -> ([Type_t.Empty], [Type_t.Empty]) 
  in
    match (clause1, clause2) with
	(Type_t.Clause (a1, a2), Type_t.Clause (b1, b2)) ->
	  let res = Type_t.Clause (a1@b1, a2@b2) in
	  let res2 = Type_t.Clause (tranche res) in
	    if (res = res2) then
	      Type_t.Notcutted
	    else
	      res2
      | _ -> Type_t.Empty
	  
let rec unify clause1 clause2 =
  let rec unify_ pred1 pred2 =
    let rec unify__ arg1 arg2 =
      match (arg1, arg2) with
	  (Type_t.Var v, Type_t.SCst c) 
	| (Type_t.SCst c, Type_t.Var v) ->
	    print_string ("substitute "^c^" to "^v^"\n");
	    [(Type_t.Var v, Type_t.SCst c)]
	| (Type_t.Arg (a1, a2), Type_t.Arg (b1, b2)) ->
	    (unify__ a1 b1)@(unify__ a2 b2)
	| _ -> []
    in
      match (pred1, pred2) with
	  (Type_t.Cst (name1, arg1), Type_t.Cst (name2, arg2)) 
	  when (name1 = name2) ->
	    unify__ arg1 arg2
	| _ -> []

 in
    match (clause1, clause2) with
	(Type_t.Clause (a1, a2), Type_t.Clause (b1, b2)) -> 
	  let rec apply l1 l2 =
	    match (l1, l2) with
		(x::xs, y::ys) -> (unify_ x y)@(apply [x] ys)@(apply xs [y])
	      | _ -> []
	  in
	    (apply a1 b1)@(apply a1 b2)@(apply a2 b1)@(apply a2 b2)
      | _ -> []

let rec substitued clause subs =
  let rec substitued_ list var cst =
    let rec substitued__ arg var cst =
      match arg with
	  Type_t.Arg (a, b) -> 
	    Type_t.Arg((substitued__ a var cst), (substitued__ b var cst))
	| Type_t.Var v when (v = var) -> Type_t.SCst cst
	| (Type_t.Var v as qi) -> qi
	| (Type_t.SCst c as cs) -> cs
	| _ -> Type_t.Empty
    in
      match list with
	  h::q -> 
	    let res = match h with 
		Type_t.Cst (name, arg) -> 
		  let toto = substitued__ arg var cst in
		    (Type_t.Cst (name, toto))::(substitued_ q var cst)
	      | _ -> [Type_t.Empty] in res
	| [] -> []
  in
    match (clause, subs) with
	(Type_t.Clause (a, b), h::q) -> 
	  let res = match h with
	      (Type_t.Var var, Type_t.SCst cst) -> 
		Type_t.Clause ((substitued_ a var cst),
			       (substitued_ b var cst))
	    | _ -> Type_t.Empty in res
      | _ -> Type_t.Empty
	  
	      
let contradiction clause =
  match clause with
      Type_t.Clause ([], []) -> raise Contradiction
    | Type_t.Empty -> raise Proved
    | _ -> ()

let conclusion clause1 clause2 =
  match (clause1, clause2) with
      (Type_t.Clause (a1, a2), Type_t.Clause (b1, b2))
      when (((a1 = b2) & ((List.length a2 = 0) & (List.length b1 = 0))) or
	    ((a2 = b1) & ((List.length a1 = 0) & (List.length b2 = 0)))) ->
	raise Contradiction
    | (Type_t.Clause (a1, a2), Type_t.Clause (b1, b2))
	when ((a1 = b1) & (a2 = b2)) -> 
	raise Proved
    | _ -> ()

let rec substitute clauses = 
  print_string "\n";
  let rec subst clause queue =
    match queue with
	h::q -> 
	  print_string ("\nUsing rule: "^(qwerty clause)^"\n");
	  print_string ("Using rule: "^(qwerty h)^"\n");
	  conclusion h clause;
	  (let unified1 = substitued clause (unify clause h) in
	     print_string ("Unified rule: "^(qwerty unified1)^"\n");
	     let new1 = coupure unified1 h in
	       if not ((new1 = Type_t.Notcutted) or (new1 = Type_t.Empty)) 
	       then begin
		 print_string ("Generated rule: "^(qwerty new1)^"\n");
		 subst new1 q;
		 ()
	       end
	       else ());
	  (let unified2 = substitued h (unify h clause) in
	     print_string ("Unified rule: "^(qwerty unified2)^"\n");
	     let new2 = coupure unified2 clause in
	       if not ((new2 = Type_t.Notcutted) or (new2 = Type_t.Empty)) 
	       then 
		 begin
		   print_string ("Generated rule: "^(qwerty new2)^"\n\n");
		   subst new2 q;
		   ()
		 end
	       else ());
	  subst h q;
	  ()
      | [] -> ()
  in
    match clauses with
	h::q -> subst h q;
	  substitute q; 
	  ()
      | [] -> raise Seche
	
