open Astsig;;

module Printer = functor (A : Astsig) ->
struct
  open A;;

  let rec printer_ast a =
    match a with
	Exp (e)    -> printer_exp e
      | Assign (a) -> printer_assign a
	  
  and printer_exp e = 
    let rec printer_exp_rec e =
      match e with
	  Elt (e) -> printer_elt e
	| Funccall (i, l) -> (printer_id i)^"("^(print_exp_list l)^")"
	| Binop(o, e1, e2) -> "("^(printer_exp e1)^(printer_op o)^
	    (printer_exp e2)^")"
	| Funcdec(r, [])  -> printer_rel r;
	| Funcdec(r, l)  -> (printer_rel r)^" WITH "^(print_assign_list l)
	| Min e -> "-"^(printer_exp e)
    in 
      printer_exp_rec e
	
  and print_exp_list l =
    match l with
	[]    -> ""
      | a::[] -> printer_exp a;
      | a::q  -> (printer_exp a)^", "^(print_exp_list q)

  and print_elt_list l =
    match l with
	[]    -> ""
      | a::[] -> printer_elt a;
      | a::q  -> (printer_elt a)^"; "^(print_elt_list q)

  and print_assign_list l =
    match l with
	[]    -> ""
      | a::[] -> printer_assign a;
      | a::q  -> (printer_assign a)^", "^(print_assign_list q)

  and printer_op o =
    match o with
	Plus  -> " + " 
      | Minus -> " - " 
      | Times -> " * "
      | Div   -> " / "
      | Power -> "^"

  and printer_id i =
    match i with
	Identifier s -> s

 and printer_lid l =
    match l with
	[] -> ""
      | [id] -> printer_id id  
      | h::q -> (printer_id h)^", "^(printer_lid q)

  and printer_elt e =
    match e with
	Integer s -> A.M.to_string_integer s
      | Inf	  -> "INF"
      | Float s   -> A.M.to_string_real s
      | Id i      -> printer_id i
	  

  and printer_set s =
    match s with
	TimesCarth (s1, s2) -> "("^(printer_set s1)^" ** "^(printer_set s2)^")"
      | Idens(Identifier(i)) -> i
      | Inter (s1, s2) -> "("^(printer_set s1)^" Inter "^(printer_set s2)^")";
      | Union (s1, s2) -> "("^(printer_set s1)^" Union "^(printer_set s2)^")"
      | Without (s1, s2) -> "("^(printer_set s1)^" \ "^(printer_set s2)^")";
      | Enum l -> "{"^(print_elt_list l)^"}"
      | Borned (e1, true, e2, true) -> 
	  "["^(printer_exp e1)^"; "^(printer_exp e2)^"]"
      | Borned (e1, true, e2, false) -> 
	  "["^(printer_exp e1)^"; "^(printer_exp e2)^"["
      | Borned (e1, false, e2, true) -> 
	  "]"^(printer_exp e1)^"; "^(printer_exp e2)^"]"
      | Borned (e1, false, e2, false) -> 
	  "]"^(printer_exp e1)^"; "^(printer_exp e2)^"["
      | IntBorned (e1, true, e2, true) -> 
	  "[|"^(printer_exp e1)^"; "^(printer_exp e2)^"|]"
      | IntBorned (e1, true, e2, false) -> 
	  "[|"^(printer_exp e1)^"; "^(printer_exp e2)^"[|"
      | IntBorned (e1, false, e2, true) -> 
	  "|]"^(printer_exp e1)^"; "^(printer_exp e2)^"|]"
      | IntBorned (e1, false, e2, false) -> 
	  "|]"^(printer_exp e1)^"; "^(printer_exp e2)^"[|"; 

  and printer_rel r =
    match r with
	Full (lid, s1, e, s2) -> 
	  (printer_lid lid)^": "^(printer_set s1)^
	  " |-> "^(printer_exp e)^": "^(printer_set s2)
      | Poly (lid, e) -> (printer_lid lid)^" |-> "^(printer_exp e)
	    
  and printer_assign a =
    match a with
	Assignexp (i, e) -> (printer_id i)^" = "^(printer_exp e)
      | Assignens (i, e) -> (printer_id i)^" = "^(printer_set e)

end
