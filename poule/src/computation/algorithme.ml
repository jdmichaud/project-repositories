open Astsig;;
open FloatInt;;

(* Div_zero is raised in case of "divide by zero" *)
exception Div_zero

(* This module contents differents algorithms... *)
module Algorithme (A : Astsig) =
struct
  open A

  (* ei is the algorithm of indian exponentiation *)
  let ei a b =
    let res = ref (M.of_string_integer "1") in
      if b = (M.of_string_integer "0") then 
	Elt (Integer (M.of_string_integer "1"))
      else
	begin
	  let x = ref a
	  and y = ref b in
	    while not (!y = (M.of_string_integer "0")) do
	      if (M.mod_integer !y (M.of_string_integer "2")) = 
		(M.of_string_integer "0") then
		  begin
		    x := M.mul_integer !x !x;
		    y := M.div_integer !y (M.of_string_integer "2");
		  end 
	      else begin
		res := M.mul_integer !res !x;
		y := M.sous_integer !y (M.of_string_integer "1");
	      end
	    done;
	    Elt (Integer !res)
	end

  let eiReal a b =
    let res = ref (M.of_string_real "1.0") in
      if b = (M.of_string_integer "0") then 
	Elt (Integer (M.of_string_integer "1"))
      else
	begin
	  let x = ref a
	  and y = ref b in
	    while not (!y = (M.of_string_integer "0")) do
	      if (M.mod_integer !y (M.of_string_integer "2")) = 
		(M.of_string_integer "0") then
		  begin
		    x := M.mul_real !x !x;
		    y := M.div_integer !y (M.of_string_integer "2");
		  end 
	      else begin
		res := M.mul_real !res !x;
		y := M.sous_integer !y (M.of_string_integer "1");
	      end
	    done;
	    Elt (Float !res)
	end
	  
end
