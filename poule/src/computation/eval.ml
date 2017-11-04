open Astsig;;
open FloatInt;;

module Eval (A : Astsig) =
struct
  open A
  module Printer = Printer.Printer (A)
  module Entity = Entity.Entity (A)
  module Algo = Algorithme.Algorithme (A)
  module Deriv = Derivate.Derivate (A)
  module Sub = Substitution.Substitution (A)
  module Ast = A
  open Ast

  exception Div_zero
  exception Late_type_error		 
  exception Internal_error

  (*let rec getOrder params elt i =
    match params with
	h::q when h = elt -> i
      | h::q -> getOrder q elt (i + 1)
      | [] -> 0

  let rec substituteArg exp params args =
    match exp with
	Elt elt -> 
	  (match elt with
	       Id id -> let order = getOrder params id 1 in
		 if order = 0 then Elt (Id id)
		 else (List.nth args (order - 1))
	     | _ -> Elt elt)
      | _ -> exp*)
    (*eval env (substituteArg ((env#getFun(id))#getDef)#getAst 
      ((env#getFun(id))#getParams) args)*)

  let eltKind exp =
    match exp with
	Elt elt ->
	  (match elt with
	       Integer i -> 0
	     | Float r -> 1
	     | Id id -> 2
	     | Inf -> 3)
      | _ -> 4

  let rec doBinop oper lhs rhs env =
    if (((eltKind lhs) = 0) & ((eltKind rhs) = 0)) then
      (match oper with
	   Plus -> (match (lhs, rhs) with (Elt Integer i1, Elt Integer i2) -> 
		      Elt (Integer (M.add_integer i1 i2))
		      | _ -> raise Late_type_error)
	 | Minus -> (match (lhs, rhs) with (Elt Integer i1, Elt Integer i2) -> 
		       Elt (Integer (M.sous_integer i1 i2))
		       | _ -> raise Late_type_error)
	 | Times -> (match (lhs, rhs) with (Elt Integer i1, Elt Integer i2) -> 
		       Elt (Integer (M.mul_integer i1 i2))
		       | _ -> raise Late_type_error)
	 | Div -> (match (lhs, rhs) with (Elt Integer i1, Elt Integer i2) -> 
		     if not (i2 = (M.of_string_integer "0")) then
		       Elt (Integer (M.div_integer i1 i2))
		     else raise Div_zero
		     | _ -> raise Late_type_error)
	 | Power -> (match (lhs, rhs) with (Elt Integer i1, Elt Integer i2) -> 
		       Algo.ei i1 i2
		       | _ -> raise Late_type_error))
			 
    else if (((eltKind lhs) = 1) & ((eltKind rhs) = 1)) then
      (match oper with
	   Plus -> (match (lhs, rhs) with (Elt Float i1, Elt Float i2) -> 
		      Elt (Float (M.add_real i1 i2))
		      | _ -> raise Late_type_error)
	 | Minus -> (match (lhs, rhs) with (Elt Float i1, Elt Float i2) -> 
		       Elt (Float (M.sous_real i1 i2))
		      | _ -> raise Late_type_error)
	 | Times -> (match (lhs, rhs) with (Elt Float i1, Elt Float i2) -> 
		       Elt (Float (M.mul_real i1 i2))
		      | _ -> raise Late_type_error)
	 | Div -> (match (lhs, rhs) with (Elt Float i1, Elt Float i2) -> 
		     if not (i2 = (M.of_string_real "0")) then
		       Elt (Float (M.div_real i1 i2))
		     else raise Div_zero
		     | _ -> raise Late_type_error)
	 | Power -> (match (lhs, rhs) with (Elt Float i1, Elt Float i2) -> 
		       eval env (Funccall (Identifier "exp", 
					   (Binop (Times, rhs, 
						   Funccall (Identifier "ln", 
							     lhs::[])))::[]))
		       | (_, _) -> raise Late_type_error))
    else if (((eltKind lhs) = 1) & ((eltKind rhs) = 0)) then
      (match oper with
	   Power -> (match (lhs, rhs) with 
			 (Elt Float i1, Elt Integer i2) -> 
			   Algo.eiReal i1 i2
		       | _ -> raise Late_type_error)
	 | _ -> raise Late_type_error)
    else
      Binop (oper, lhs, rhs)

  and eval env exp =
    match exp with
	Elt elt -> Elt elt
      | Funccall (id, lexp) -> 
	  let args = List.map (eval env) lexp in
	  let ast = (Sub.substitute (Exp ((Deriv.replacelist ((env#getFun(id))#getParams) args ((env#getFun(id))#getDef)#getAst))) env) in
	    (match ast with
		 Exp e -> 
		   let tmp = eval env e in
		     eval env tmp
	       | _ -> raise Internal_error)
      
       | Binop (oper, exp1, exp2) -> 
	  let lhs = (eval env exp1)
	  and rhs = (eval env exp2) in
	    doBinop oper lhs rhs env
      | Funcdec (rel, lassign) ->
	  Funcdec ((evalRelation env rel), (List.map (evalAssign env) lassign))
      | Min exp -> (match (eval env exp) with
			Elt (Integer(e)) -> Elt(Integer(M.opp_integer e))
		      | Elt (Float(e)) -> Elt(Float(M.opp_real e))
		      | _ as e -> Min (e))
	  
  and evalRelation env rel =
    match rel with
	Full (lid, set1, exp, set2) -> Full (lid, (evalSet env set1), 
					     (eval env exp), evalSet env set2)
      | Poly (lid, exp) -> Poly (lid, (eval env exp))
	  
  and evalSet env set =
    match set with
	Borned (borneInf, openInf, borneSup, openSup) -> 
	  Borned ((eval env borneInf), openInf, 
		  (eval env borneInf), openSup)
      | IntBorned (borneInf, openInf, borneSup, openSup) ->
	  Borned ((eval env borneInf), openInf, 
		  (eval env borneInf), openSup)
      | _ -> set
	  
  and evalAssign env assign =
    match assign with
	Assignexp (id, exp) -> Assignexp (id, (eval env exp))
      | Assignens (id, set) -> Assignens (id, evalSet env set)

  and evalAst env ast =
    match ast with
	Exp exp -> Exp (eval env exp)
      | Assign assign -> Assign (evalAssign env assign)
	  
end
