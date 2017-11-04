open Astsig;;
open FloatInt;;

module Substitution (A : Astsig)=
struct

  module Printer = Printer.Printer (A)
  module Entity = Entity.Entity (A)
  module Ast = A
  open Ast

  exception Incompatible_type
  exception Var_in_Enum
  exception ArgNbr
  exception FuncArgNbr of string

  let rec isIn lst elt = 
    match lst with
	[] -> false
      | h::q -> if h = elt then true else isIn q elt

  let rec apply f lstInput lstArg = 
    match lstInput with
	[] -> []
      | h::q -> (f h lstArg)::(apply f q lstArg)

  let getEltfromEnv elt env = 
    match elt with
	Id var ->
	  (try
	     (env#getVar(var))#getValue
	   with  
	       Not_found -> 
		 (try 
		    (env#getSet(var))#getValue
		  with  
		      Not_found -> 
			(try 
			   (env#getFun(var))#getValue
			 with  
			     Not_found -> 
			       elt)))
      | _ -> elt

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

  let rec put_in_exp l =
    match l with
	[] -> []
      | s::q -> match s with
	  | Identifier (a) -> (Elt(Id(Identifier(a))))::(put_in_exp q)

  let substitute ast env =
    let rec substituteSet set =
      match set with 
	  Idens (id) -> 
	    (try 
	       let setExp = (env#getSet(id))#getValue in
		 substituteSet setExp
	     with
		 Not_found -> set)
	| TimesCarth (set1, set2) -> TimesCarth (substituteSet set1, 
						 substituteSet set2)
	| Inter (set1, set2) -> Inter (substituteSet set1, substituteSet set2)
	| Union (set1, set2) -> Union (substituteSet set1, substituteSet set2)
	| Without (set1, set2) -> Without (substituteSet set1, 
					   substituteSet set2)
	| Enum (lelt) -> 
	    let substituteElt elt = 
	      match elt with
		  Id var ->
		    (try
		       let expRes = (env#getVar(var))#getValue in
			 match expRes with
			     Elt elt1 -> elt1
			   | _ -> print_string("Error: An enumeration"
					       ^" can only contain a value.");
			       print_newline ();
			       elt
		     with  
			 Not_found ->
			   (try 
			      let error1 = (env#getFun(var)) in
				print_string ("Error: Incompatible type.\n" ^ 
				"An set enumeration cannot contain "^
				"a function declaration.");
				print_newline ();
				raise Incompatible_type
			    with 
				Not_found -> 
				  (try
				     let error2 = (env#getSet(var)) in
				       print_string 
					 ("Error: Incompatible type.\n" ^ 
					  "An set enumeration cannot contain "^
					  "a set.");
				       print_newline ();
				       raise Incompatible_type
				   with 
				       Not_found -> elt)
			   )
		    )
		| _ -> elt
	    in
	      Enum (List.map substituteElt lelt)
		
	| Borned (exp1, bool1, exp2, bool2) -> 
	    Borned (substituteExp exp1, bool1, substituteExp exp2, bool2)
	| IntBorned (exp1, bool1, exp2, bool2) -> 
	    IntBorned (substituteExp exp1, bool1, substituteExp exp2, bool2)
	      
    and substituteAssign assign = 
      match assign with 
	  Assignexp (id, exp) -> Assignexp (id, substituteExp exp)
	| Assignens (id, set) -> Assignens (id, substituteSet set)

    and substituteExpInRel exp lid = 
      match exp with
	  Elt elt -> 
	    (match elt with
		 Id var ->
		   if isIn lid var then
		     exp
		   else
		     (try
			(env#getVar(var))#getValue
		      with  
			  Not_found -> exp)
	       | _ -> exp)
	| Min exp -> Min (substituteExpInRel exp lid)
	| Funccall (id, lexp) -> 
	    let lsubexp = apply substituteExpInRel lexp lid in
	      Funccall (id, lsubexp)
	| Binop (oper, exp1, exp2) -> Binop (oper, 
					     substituteExpInRel exp1 lid,  
					     substituteExpInRel exp2 lid)
	| Funcdec (rel, lassign) -> 
	    let subrel = 
	      match rel with 
		  Full (lid, set1, exp, set2) -> 
		    Full (lid, substituteSet set1, 
			  substituteExpInRel exp lid, substituteSet set2)
		| Poly (lid, exp) -> Poly (lid, substituteExpInRel exp lid)
	    and sublassign = List.map substituteAssign lassign in
	      Funcdec (subrel, sublassign)
		
    and substituteExp exp =
      match exp with
	  Elt elt -> 
	    (match elt with
		 Id var ->
		   (try
		      substituteExp ((env#getVar(var))#getValue)
		    with  
			Not_found -> 
			  (try
			     substituteExpInRel 
			       ((env#getFun(var))#getDef)#getAst 
			       ((env#getFun(var))#getParams)
			   with
			       Not_found -> exp))
	       | _ -> exp)
	| Min exp -> Min (substituteExp exp)
	| Funccall (id, lexp) -> 
	    let lsubexp = List.map substituteExp lexp in
	    let f = Funccall (id, lsubexp) in
	      (try
		 if ((env#getFun id)#getReplacable) then
		   let exp = ((env#getFun id)#getDef)#getAst in
		   let args = ((env#getFun id)#getParams) in
		   let ensdep = substituteSet ((env#getFun (id))#getSetDep) in
		     if (List.length (args) = List.length (lexp)) then
		       substituteExp (replacelist args lsubexp exp)
		     else
		       raise ArgNbr
		 else
		   f
	       with
		   Not_found -> exp)
	| Binop (oper, exp1, exp2) -> Binop (oper, 
					     substituteExp exp1, 
					     substituteExp exp2)
	| Funcdec (rel, lassign) -> 
	    let subrel = 
	      match rel with 
		  Full (lid, set1, exp, set2) -> 
		    Full (lid, substituteSet set1, 
			  substituteExpInRel exp lid, substituteSet set2)
		| Poly (lid, exp) -> Poly (lid, substituteExpInRel exp lid)
	    and sublassign = List.map substituteAssign lassign in
	      Funcdec (subrel, sublassign)
    in
      match ast with
	  Exp exp -> Exp (substituteExp exp)
	| Assign assign -> Assign (substituteAssign assign)

end

