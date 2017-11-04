open Astsig;;

(* TYPE_ERROR is raised when a type-error occurs *)

open FloatInt;;

module Check (A : Astsig)=
struct
  open A
  module Printer = Printer.Printer (A)
  module Entity = Entity.Entity (A)
  module Ast = A
  module Eval = Eval.Eval (A)
  open Ast

  exception TYPE_ERROR
  exception NOT_ELT
  exception SET_ERROR
  exception VAR_UNDEFINED_IN_SET
  exception BIZAR 
  exception InfAsElt
  exception RCRSV_DEF of string

  let expToElt exp = 
    match exp with
	Elt elt -> elt
      | Min (Elt (Integer (i))) -> Integer (M.opp_integer i)
      | Min (Elt (Float (f))) -> Float (M.opp_real f)
      | _ -> raise NOT_ELT (* Never here *)

  let rec checktype_funccall_arg ensdep lelt env = 
    match ensdep with
	TimesCarth (set1, set2) -> 
	  ((inSet set1 (List.hd lelt) env) & 
	   (checktype_funccall_arg set2 (List.tl lelt) env))
      | Inter (set1, set2) -> 
	  ((checktype_funccall_arg set1 lelt env) & 
	   ((checktype_funccall_arg set2 lelt) env))
      | Union (set1, set2) -> 
	  ((checktype_funccall_arg set1 lelt env) or 
	   ((checktype_funccall_arg set2 lelt) env))
      | Without (set1, set2) -> 
	  ((checktype_funccall_arg set1 lelt env) & not
	     ((checktype_funccall_arg set2 lelt) env))
      | Idens (id) -> 
	  checktype_funccall_arg ((env#getSet id)#getValue) lelt env
      | _ -> 
	  if List.length lelt = 1 then
	    inSet ensdep (List.hd lelt) env
	  else 
	    false
  
  and betweeni elt borneInf borneSup closeInf closeSup inferior superior equal=
    if ((superior elt borneInf) || (equal elt borneInf)) &
      (closeInf || (not closeInf & not (equal elt borneInf))) then 
	if ((inferior elt borneSup) || (equal elt borneSup)) &
	  (closeSup || (not closeSup & not (equal elt borneSup))) then true
	else false
    else false
   
  and betweenf elt borneInf borneSup closeInf closeSup inferior superior equal=
    if ((superior elt borneInf) || (equal elt borneInf)) & 
      (closeInf || (not closeInf & not (equal elt borneInf))) then 
	if ((inferior elt borneSup) || (equal elt borneSup)) & 
	  (closeSup || (not closeSup & not (equal elt borneSup))) then true
	else false
    else false
    

  (* inSet check if an elt is in a set*)
  and inSet set elt env =
    match set with
	Inter (set1, set2) -> ((inSet set1 elt env) & (inSet set2 elt env))
      | Union (set1, set2) -> ((inSet set1 elt env) or (inSet set2 elt env))
      | Without (set1, set2) -> ((inSet set1 elt env) & 
				 not (inSet set1 elt env))
      | Enum lelt -> 
	  let rec isIn elt lid =
	    match lid with
		h::q when h = elt -> true
	      | h::q -> isIn elt q
	      | [] -> false
	  in
	    isIn elt lelt
      | IntBorned (borneInf, closeInf, borneSup, closeSup) -> 
	  (* i1 = borne inf *)
	  (* i2 = elt *)
	  (* i3 = borne sup *)
	  (match elt with
	       Integer i -> 
		 (match (Eval.eval env borneInf, Eval.eval env borneSup) with
		      (Elt Integer bi, Elt Integer bs) ->
			betweeni i bi bs closeInf closeSup 
			M.lt_integer M.gt_integer M.equal_integer
		    | (Min Elt Integer bi, Elt Integer bs) ->
			betweeni i (M.opp_integer bi) bs closeInf closeSup
			M.lt_integer M.gt_integer M.equal_integer
		    | (Elt Integer bi, Min Elt Integer bs) -> 
			betweeni i bi (M.opp_integer bs) closeInf closeSup 
			M.lt_integer M.gt_integer M.equal_integer
		    | (Min Elt Integer bi, Min Elt Integer bs) -> 
			betweeni i (M.opp_integer bi) (M.opp_integer bs) 
			closeInf closeSup M.lt_integer 
			M.gt_integer M.equal_integer
		    | (Min Elt Inf, _) | (_, Elt Inf) -> true
		    | _ -> raise TYPE_ERROR)
	     | Float f -> raise TYPE_ERROR
	     | Inf -> raise InfAsElt
	     | Id id -> true)

      | Borned (borneInf, closeInf, borneSup, closeSup) -> 
	  (* i1 = borne inf *)
	  (* i2 = elt *)
	  (* i3 = borne sup *)
	  (match elt with
	       Float f -> 
		 (match (Eval.eval env borneInf, Eval.eval env borneSup) with
		      (Elt Float bi, Elt Float bs) ->
			betweenf f bi bs closeInf closeSup 
			M.lt_real M.gt_real M.equal_real
		    | (Min Elt Float bi, Elt Float bs) ->
			betweenf f (M.opp_real bi) bs closeInf closeSup
			M.lt_real M.gt_real M.equal_real
		    | (Elt Float bi, Min Elt Float bs) -> 
			betweenf f bi (M.opp_real bs) closeInf closeSup 
			M.lt_real M.gt_real M.equal_real
		    | (Min Elt Float bi, Min Elt Float bs) -> 
			betweenf f (M.opp_real bi) (M.opp_real bs) 
			closeInf closeSup M.lt_real 
			M.gt_real M.equal_real
		    | (Min Elt Inf, _) | (_, Elt Inf) -> true
		    | _ -> raise TYPE_ERROR)
	     | Integer i -> raise TYPE_ERROR
	     | Inf -> raise InfAsElt
	     | Id id -> true)

      | Idens id -> inSet ((env#getSet id)#getValue) elt env
      | TimesCarth (_, _) -> raise TYPE_ERROR
	    
	   
		       
(* false is the main function which checks the ast *)
  let rec check_ast a env =
    match a with
	Exp (e)    -> checktype_exp e env; ()
      | Assign (a) -> checktype_assign a env; ()
	
(* checktype_exp check the type of an exp and raises TYPE_ERROR *)
(* if an error occurs *)	
  and checktype_exp e env =
    match e with
	Elt elt -> 
	  (match elt with
	       Integer (i) -> 1
	     | Float (f) -> 2
	     | Id (id) -> 0
	     | Inf -> 0)
      | Funccall (id, lexp) ->
	  (try
	     let ensdep = (env#getFun (id))#getSetDep in
	       if (checktype_funccall_arg ensdep (List.map expToElt lexp) env)
	       then (checktype_exp_list lexp 0 env)
	       else raise SET_ERROR
	   with 
	       Not_found -> (checktype_exp_list lexp 0 env)
	     | NOT_ELT -> (checktype_exp_list lexp 0 env))
      | Binop (Power, exp1, exp2) -> 
	  let lhs = (checktype_exp exp1 env)
	  and rhs = (checktype_exp exp2 env) in
	    if lhs = 0 then 
	      if (rhs = 0) || (rhs = 1) then 0 else raise TYPE_ERROR
	    else if lhs = 1 && (rhs = 1 || rhs = 0) then 1 
	    else if lhs = 2 && (rhs = 2 || rhs = 1 || rhs = 0) then 2
	    else raise TYPE_ERROR
      | Binop (_, exp1, exp2) -> 
	  let lhs = (checktype_exp exp1 env)
	  and rhs = (checktype_exp exp2 env) in
	    if ((lhs = rhs) || (lhs = 0) || (rhs = 0)) then
	      if lhs = 0 then checktype_exp exp2 env
	      else lhs
	    else raise TYPE_ERROR
      | Funcdec (rel, lassign) -> 
	  (match rel with
	       Full (id, set1, exp, set2) -> (checktype_exp exp env)
	     | Poly (id, exp) -> (checktype_exp exp env))
      | Min a -> checktype_exp a env;
      
  (* checktype_exp_list check the type of an exp list *)
  (* and raises TYPE_ERROR if an error occurs *)
  and checktype_exp_list l t env =
    match l with
	[]    -> 0
      | a::q  -> let tmp = (checktype_exp a env) in
	  if ((tmp = t) || (tmp = 0) || (t = 0)) then
	    checktype_exp_list q tmp env
	  else raise TYPE_ERROR

  (** checktype_assign check the type of an assign
    and raises TYPE_ERROR if an error occurs **)
  and checktype_assign a env =
    match a with
	Assignexp (i, e) -> checktype_exp e env
      | Assignens (i, e) -> checktype_set e env
	  
  (* checktype_set check the type of a set and *)
  (* raises TYPE_ERROR if an error occurs *)
  and checktype_set s env =
    match s with
	TimesCarth (s1, s2) -> 
	  let tmp = (checktype_set s1 env) in
	    if (tmp = checktype_set s2 env) then tmp
	    else raise TYPE_ERROR
      | Idens (id) -> 
	  checktype_set ((env#getSet id)#getValue) env
      | Inter (s1, s2) -> 
	  let tmp = (checktype_set s1 env) in
	    if (tmp = checktype_set s2 env) then tmp
	    else raise TYPE_ERROR
      | Union (s1, s2) -> 
	  let tmp = (checktype_set s1 env) in
	    if (tmp = checktype_set s2 env) then tmp
	    else raise TYPE_ERROR
      | Without (s1, s2) -> 
	  let tmp = (checktype_set s1 env) in
	    if (tmp = checktype_set s2 env) then tmp
	    else raise TYPE_ERROR
      | Enum l -> checktype_elt_list l 0;
      | Borned (e1, _, e2, _) -> 
	  let tmp = (checktype_exp e1 env) in
	  let tmp2 = checktype_exp e2 env in
	    if (((tmp = tmp2)&& (tmp = 2)) || (tmp = 0) || (tmp2 = 0)) then 2
	    else raise TYPE_ERROR
      | IntBorned (e1, _, e2, _) -> 
	  let tmp = (checktype_exp e1 env) in
	  let tmp2 = checktype_exp e2 env in
	    if (((tmp = tmp2)&& (tmp = 1)) || (tmp = 0) || (tmp2 = 0)) then 1
	    else raise TYPE_ERROR


  (** checktype_elt check the type of an elt and **)
  (** raises TYPE_ERROR if an error occurs **)
  and checktype_elt e =
    match e with
	Integer (i) -> 1
      | Float (f) -> 2
      | Id (id) -> 0
      | Inf -> 0

  (* checktype_elt_list check the type of an elt list *)
  (* and raises TYPE_ERROR if an error occurs *)
  and checktype_elt_list l t =
    match l with
	[]    -> 0
      | a::[] ->
	  let tmp = (checktype_elt a) in
	    if ((tmp = t) || (tmp = 0) || (t = 0)) then tmp
	    else raise TYPE_ERROR
      | a::q  -> 
	  let tmp = (checktype_elt a) in
	    if ((tmp = t) || (tmp = 0) || (t = 0)) then
	      checktype_elt_list q tmp
	    else  
	      raise TYPE_ERROR
		
  let checkFunccallOnly ast env =
    let rec checkFunccallOnlyInExp exp =
      match exp with
	  Funccall (id, lexp) ->
	    (try
	       let ensdep = (env#getFun (id))#getSetDep in
		 if (checktype_funccall_arg ensdep 
		       (List.map expToElt lexp) env)
		 then 
		   let lres = (List.map checkFunccallOnlyInExp lexp) in () 
		 else raise SET_ERROR
	     with 
		 Not_found -> 
		   let lres = (List.map checkFunccallOnlyInExp lexp) in ()
	       | NOT_ELT -> 
		   let lres = (List.map checkFunccallOnlyInExp lexp) in ())
	| Binop (_, lhs, rhs) -> checkFunccallOnlyInExp lhs;
	    checkFunccallOnlyInExp rhs; ()
	| Funcdec (rel, lassign) -> 
	    let lres = List.map checkFunccallOnlyInAssign lassign in ()
	| Min exp -> checkFunccallOnlyInExp exp; ()
	| _ -> ()

    and checkFunccallOnlyInAssign ass =
      match ass with
	  Assignexp (id, e) -> checkFunccallOnlyInExp e
	| Assignens (id, s) -> 
	    (match s with
		 Borned (inf, _, sup, _) 
	       | IntBorned (inf, _, sup, _) -> 
		   checkFunccallOnlyInExp inf;
		   checkFunccallOnlyInExp sup; ()
	       | _ -> ())
    in
      match ast with
	  Exp expr -> checkFunccallOnlyInExp expr
	| Assign assign -> checkFunccallOnlyInAssign assign
	
  let rec checkAssign id exp =
    match exp with
	Elt elt -> checkAssignElt id elt 
      | Funccall (d, lexp) -> 
	  (match lexp with
	       h::q -> checkAssign d h 
	     | [] -> ())
      | Funcdec (rel, lassign) -> checkAssignRel id rel; ()
      | Binop (_, lhs, rhs) -> checkAssign id lhs; checkAssign id rhs
      | Min xp -> checkAssign id xp; ()

  and checkAssignElt id elt =
    match elt with
	Id i when id = i -> 
	  (match i with
	       Identifier str -> raise (RCRSV_DEF str))
      | _ -> ()
	  
  and checkAssignSet id set =
    match set with
	Borned (inf, _, sup, _) | IntBorned (inf, _, sup, _) -> 
				    checkAssign id inf; checkAssign id sup
      | Enum lelt ->
	  let rec isIn l =
	    match l with
		h::q -> checkAssignElt id h; isIn q
	      | [] -> ()
	  in
	    isIn lelt
      | _ -> ()

  and checkAssignRel id rel =
    match rel with
	Full (_, dep, exp, arr) ->
	  checkAssignSet id dep;
	  checkAssign id exp;
	  checkAssignSet id arr;
      | Poly (_, exp) -> 
	  checkAssign id exp;


end
  
