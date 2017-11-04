open Astsig;;
open FloatInt;;

(* Module of the derivate function *)
module Derivate (A : Astsig)=
struct
  open A
  module Printer = Printer.Printer (A)
  module Entity = Entity.Entity (A)
  module Env = Enviro.Enviro (A)
  module Ast = A
  open Ast

  exception DerExce
  exception PasUnElt
  exception ArgNbr

  let rec replaceExp (id : id) id2 exp=
    match exp with
	Elt(Id(a)) when a = id -> id2
      | Elt(e) -> exp
      | Funccall(a,l) -> Funccall(a,List.map (replaceExp id id2) l)
      | Binop(o,a,b) -> Binop (o, replaceExp id id2 a, replaceExp id id2 b)
      | Funcdec(a,b) -> exp
      | Min (a) -> Min(replaceExp id id2 a)
	
  let rec replacelist lid lid2 exp =
    if (List.length lid) <> (List.length lid2) then
      raise ArgNbr
    else
      match (lid,lid2) with
	|([],[]) -> exp
	|(a::q, b::t) -> replacelist q t (replaceExp a b exp)
	|_ -> failwith "cas impossible" 

  (* isIn check if elt is in the list lid *)
  let rec isIn elt lid =
    match lid with
	h::q -> if (h = elt) then true else (isIn elt q)
      | [] -> false
	

  let put_in_elt e =
    match e with
	Elt(a) -> a
      | _ -> raise PasUnElt

  (* derivate is our function of derivation *)
  let derivate f l env =
    let lid = List.map put_in_elt l in
    (* derivate an exp *)
    let rec derivExp exp env =
      match exp with
	  Elt elt -> 
	    (match elt with
		 Integer (i) -> Elt (Integer (A.M.get_add_neutral ()))
	       | Float (f) -> Elt (Integer (A.M.get_add_neutral ()))
	       | Id (id) -> 
		   if (isIn elt lid) then 
		     Elt (Integer (A.M.get_mult_neutral ()))
		   else
		     Elt (Integer (A.M.get_add_neutral ()))
	       | Inf -> Elt (Integer (A.M.get_add_neutral ())))
	    
	| Funccall (Identifier id, lexp) when (List.length lexp) = 1 -> 
	    (Binop (Times, (derivExp (List.hd lexp) env), 
		    (try 
		       let d = ((env#getFun(Identifier id))#getDeriv) in
			 (match d with
			      Env.Null -> Funccall (Identifier (id^"'"), lexp)
			    | Env.Ent entity -> 
				let rel = entity#getAst in
				  match rel with
				      Funcdec (Full (lid, _, e,_),_) ->
					replacelist (lid) lexp e
				    | Funcdec (Poly (lid, e),_) ->
					replacelist (lid) lexp e
				    | _ -> rel)
		     with 
			 Not_found -> Funccall (Identifier (id^"'"), lexp))))
	| Funccall (Identifier id, lexp) -> Funccall (Identifier(id^"'"), lexp)
	| Binop (oper, exp1, exp2) -> 
	    (match oper with
		 Plus -> Binop (Plus, (derivExp exp1 env), (derivExp exp2 env))
	       | Minus -> Binop (Minus,(derivExp exp1 env),(derivExp exp2 env))
	       | Times -> Binop (Plus, Binop(Times, (derivExp exp1 env), exp2),
				 Binop (Times, exp1, (derivExp exp2 env)))
	       | Div -> Binop (Div, (Binop (Minus, Binop (Times, (derivExp exp1 env), exp2), Binop (Times, exp1, (derivExp exp2 env)))), Binop (Power, exp2, Elt (Integer (Ast.M.of_string_integer "2"))))
 	       | Power -> Binop (Times, exp2, Binop (Times, (derivExp exp1 env), Binop (Power, exp1, Binop (Minus, exp2, Elt (Integer (A.M.get_mult_neutral ())))))))
 	| Funcdec (rel, lassign) -> 
	    (match rel with
		 Full (id, set1, exp, set2) -> (derivExp exp env)
	       | Poly (id, exp) -> (derivExp exp env));
	| Min(a) -> Min (derivExp a env)
    in
      match f with
	| Exp(e) -> derivExp e env
	| _ -> raise DerExce
end

