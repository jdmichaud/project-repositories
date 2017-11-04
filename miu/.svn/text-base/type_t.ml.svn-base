type t = Empty
	 | True
	 | False
	 | Cst of string * t
	 | SCst of string
	 | Var of string
	 | Not of t
	 | And of t * t
	 | Or of t * t
	 | Arg of t * t
	 | Clause of (t list * t list)
	 | Theory of t * t
	 | Imp of t * t
	 | Notcutted
