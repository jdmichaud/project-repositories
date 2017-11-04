open Astsig;;

module Latex = functor (A : Astsig) ->
struct
  open A;;

  let rec latexPrinter a =
    "\\documentclass{article}"^
    "\n"^
    "\\begin{document}"^
    "\n"^
    "$$"^
    "\n"^
    (match a with
	 Exp e    -> latexPrinterExp e
       | Assign a -> latexPrinterAssign a)^
    "$$"^
    "\n"^
    "\\end{document}"
      
  and latexPrinterExp e = 
    match e with
	Elt (e) -> latexPrinterElt e
      | Funccall (i, l) -> (latexPrinterId i)^"( "^(latexPrinterExpList l)^") "
      | Binop (o, e1, e2) ->  "("^(latexPrinterBinop e)^") "
      | Funcdec(r, [])  -> latexPrinterRel r;    
      | Funcdec(r, l)  -> (latexPrinterRel r)^" with "^
	  (latexPrinterAssignList l)
      | Min a ->  "-"^(latexPrinterExp a)
	  
  and latexPrinterExpList l =
    match l with
	[]    -> ""
      | a::[] -> latexPrinterExp a;
      | a::q  -> (latexPrinterExp a)^", "^(latexPrinterExpList q)

  and latexPrinterEltList l =
    match l with
	[]    -> ""
      | a::[] -> latexPrinterElt a;
      | a::q  -> (latexPrinterElt a)^", "^(latexPrinterEltList q)

  and latexPrinterAssignList l =
    match l with
	[]    -> ""
      | a::[] -> latexPrinterAssign a;
      | a::q  -> (latexPrinterAssign a)^", "^(latexPrinterAssignList q)

  and latexPrinterBinop e =
    match e with
	Binop (o, e1, e2) ->
	  (match o with
	       Div   ->  "\frac{"^(latexPrinterExp e1)^
		 "}{"^(latexPrinterExp e2)^"}"
	     | Plus  -> (latexPrinterExp e1)^" + "^(latexPrinterExp e2)
	     | Minus -> (latexPrinterExp e1)^" - "^(latexPrinterExp e2)
	     | Times -> (latexPrinterExp e1)^" * "^(latexPrinterExp e2)
	     | Power -> (latexPrinterExp e1)^"^"^(latexPrinterExp e2))
      | _ ->  "** error **"

  and latexPrinterId i =
    match i with
	Identifier s ->  s

  and latexPrinterLid l =
    match l with
	[] -> ""
      | [id] -> latexPrinterId id
      | h::q -> (latexPrinterId h)^", "^(latexPrinterLid q)

  and latexPrinterElt e =
    match e with
	Integer s ->  (A.M.to_string_integer s)
      | Float s   ->  (A.M.to_string_real s)
      | Id i      -> latexPrinterId i
      | Inf	->  "\infty"

  and latexPrinterSet s =
    match s with
	Inter (s1, s2) -> (latexPrinterSet s1)^" \bigcap "^(latexPrinterSet s2)
      | Union (s1, s2) -> (latexPrinterSet s1)^" \bigcup "^(latexPrinterSet s2)
      | Without (s1, s2) -> (latexPrinterSet s1)^" - "^(latexPrinterSet s2)
      | Enum l ->  "\{"^(latexPrinterEltList l)^"\} "
      | Borned (e1, true, e2, true) -> "]"^(latexPrinterExp e1)^
	  "; "^(latexPrinterExp e2)^"[ ";  
      | Borned (e1, true, e2, false) ->  "]"^(latexPrinterExp e1)^
	  "; "^(latexPrinterExp e2)^"] "; 
      | Borned (e1, false, e2, true) ->  "["^(latexPrinterExp e1)^
	  "; "^(latexPrinterExp e2)^"[ "; 
      | Borned (e1, false, e2, false) ->  "["^(latexPrinterExp e1)^
	  "; "^(latexPrinterExp e2)^"] " ;
      | _ -> ""

  and latexPrinterRel r =
    match r with
	Full (lid, s1, e, s2) -> (latexPrinterLid lid)^"\in"^
	  (latexPrinterSet s1)^"\mapsto"^(latexPrinterExp e)^
	  "\in"^(latexPrinterSet s2)
      | Poly (lid, e) -> latexPrinterLid lid^("\mapsto")^(latexPrinterExp e)
	    
  and latexPrinterAssign a =
    match a with
	Assignexp (i, e) -> (latexPrinterId i)^" = "^(latexPrinterExp e)
      | Assignens (i, e) -> (latexPrinterId i)^" = "^(latexPrinterSet e)

end


