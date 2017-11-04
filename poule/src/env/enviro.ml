module type Entsig = 
sig
  type entity
end

open Astsig;;
module Enviro (Ast:Astsig)=
struct
  open Ast;;
  module Printer = Printer.Printer(Ast)
  module Entity = Entity.Entity(Ast)
  
  (* Remove a funObj from the function list _funlist *)
  let rec removeFun e l =
    match l with
      | [] -> []
      | h::t when h#getName = e -> removeFun e t
      | h::t -> h::(removeFun e t);;
  
  (* Remove a setObj from the set list _setlist *)
  let rec removeSet e l =
    match l with
      | [] -> []
      | h::t when h#getName = e -> removeSet e t
      | h::t -> h::(removeSet e t);;
  
  (* Remove a varObj from the var list _varlist *)
  let rec removeVar e l =
    match l with
      | [] -> []
      | h::t when h#getName = e -> removeVar e t
      | h::t -> h::(removeVar e t);;
  
  (* Search a varObj from the var list _varlist *)
  (* findVar returns the varObj *)
  let rec findVar e l =
    match l with
      | [] -> raise Not_found
      | h::t when h#getName = e -> h
      | h::t -> findVar e t;;
  
  (* Search a setObj from the set list _setlist *)
  (* findSet returns the setObj *)
  let rec findSet e l =
    match l with
      | [] -> raise Not_found
      | h::t when h#getName = e -> h
      | h::t -> findSet e t;;
  
  (* Search a funObj from the function list _funlist *)
  (* findFun returns the funObj *)
  let rec findFun e l =
    match l with
      | [] -> raise Not_found
      | h::t when h#getName = e-> h
      | h::t -> findFun e t;;

  type opt =
    | Ent of Entity.entity
    | Null;;
  

  (* Defintion of funObj *)
  class funObj n r = 
  object(self)
    
    (* Attributes *)
    val mutable name : id = n
    val mutable replacable = true
    val mutable def = 
      match r with
 	| Full(id, set1, exp, set2) -> new Entity.entity exp
 	| Poly(id, exp) -> new Entity.entity exp
    val mutable deriv = Null
    val mutable params =
      match r with
	| Full(id, set1, exp, set2) -> id
 	| Poly(id, exp) -> id
    val mutable prim = Null
    val mutable setDep =
      match r with
 	| Full(id, set1, exp, set2) -> set1
 	| Poly(id, exp) -> Borned(Binop(Minus, 
					Elt(Integer(M.of_string_integer "0")) ,
 					Elt(Inf)), false, Elt(Inf), false)
    val mutable setArr =
      match r with
	| Full(id, set1, exp, set2) -> set2
 	| Poly(id, exp) -> Borned(Binop(Minus, 
					Elt(Integer(M.of_string_integer "0")) ,
					Elt(Inf)), false, Elt(Inf), false)

    (* Setters *)
    method setDeriv e = deriv <- e
    method setPrim p = prim <- p
    method setReplacable r = replacable <- r
	       
    (* Accessors *)
    method getName = name
    method getDef = def
    method getDeriv = deriv
    method getPrim = prim
    method getReplacable = replacable
    method getParams = params
    method getSetDep = setDep
    method getSetArr = setArr
    method show = 
      match name with
	  Identifier str -> str^" = "^(Printer.printer_exp (def#getAst))
  end;;
  

  (* Defintion of varObj *)
  class varObj n v = 
  object(self)
    
    (* Attributes *)
    val mutable name : id = n
    val mutable value : Ast.exp = v

    (* Accessors *)
    method getName = name
    method getValue = value
    method show =       
      match name with
	  Identifier str -> str^" = "^(Printer.printer_exp value)
  end;;
  
  (* Defintion of setObj *)
  class setObj n v = 
  object(self)
    
    (* Attributes *)
    val mutable name : id = n
    val mutable value : Ast.set = v
				    
    (* Accessors *)
    method getName = name
    method getValue = value
    method show =       
      match name with
	  Identifier str -> str^" = "^(Printer.printer_set value)
  end;;
  
  
  (* Defintion of the environment object *)
  class enviro =
  object(self)
    
    (* Attributes *)
    val mutable _prec = 5
    val mutable _funlist : funObj list = []
    val mutable _setlist : setObj list = []
    val mutable _varlist : varObj list = []

    (* Methods *)
    method rein () = 
      _funlist <- [];
      _setlist <- [];
      _varlist <- [];
      

    method showEnv =
      let rec showList list =
	match list with
	    h::q -> 
	      print_string (h#show);
	      print_newline ();
	      showList q;
	  | [] -> ()
      in
	showList _setlist;
	showList _varlist;
	showList _funlist

    method getPrec = _prec
		       
    method setPrec p = 
      begin
 	_prec = p;
      end
      
    method addFun i a =
      begin
	let newFunc = new funObj i a in 
 	let tmp = removeFun newFunc#getName _funlist in _funlist <- 
							newFunc::tmp;
      end
      
    method addSet i a = 
      begin
 	let newSet = new setObj i a in 
	let tmp = removeSet newSet#getName _setlist in _setlist <- newSet::tmp;
      end
      
    method addVar i a =
      begin
	let newVar = new varObj i a in
	let tmp = removeVar newVar#getName _varlist in _varlist <- newVar::tmp;
      end
      
    method remFun f = 
      begin
	removeFun f _funlist
      end
      
    method remSet s = 
      begin
	removeSet s _setlist
      end
      
    method remVar e =
      begin
	removeVar e _varlist
      end
      
    method getVar e =
      begin
	findVar e _varlist
      end
      
    method getSet s =
      begin
	findSet s _setlist
      end
      
    method getFun f =
      begin
	findFun f _funlist
      end
  end
end
