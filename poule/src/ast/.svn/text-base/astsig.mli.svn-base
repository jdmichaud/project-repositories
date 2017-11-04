open Typesig;;

module type Astsig =
sig
  module M : Typesig

  type oper = Plus
	      | Minus
	      | Times
	      | Div
	      | Power
		  
  type id = Identifier of string
    
  type elt = Integer of M.integer
	     | Float of M.real
	     | Id of id
	     | Inf
		 
  type set = TimesCarth of set * set
	     |Idens of id
             | Inter of set * set
	     | Union of set * set
	     | Without of set * set
	     | Enum of elt list
	     | Borned of exp * bool * exp * bool
	     | IntBorned of exp * bool * exp * bool
		 
  and
    relation = Full of id list * set * exp * set
	       | Poly of id list * exp
  and
    exp = Elt of elt
	  | Funccall of id * exp list 
	  | Binop of oper * exp * exp
	  | Funcdec of relation * assign list
	  | Min of exp
  and
    assign = Assignexp of id * exp
	     | Assignens of id * set
		 
  type ast = Exp of exp
	     | Assign of assign

end
