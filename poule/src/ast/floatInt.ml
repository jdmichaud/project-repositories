open Typesig;;
open Entiers;;
open Reels;;

module FloatInt : Typesig =
struct
  module Integer = Entiers
  module Real = Reels

  type integer = Integer.t
  type real = Real.t

  let to_string_real = Real.toString 
  let of_string_real = Real.ofString

  let to_string_integer = Integer.toString
  let of_string_integer = Integer.ofString

  let add_real a b = Real.meth#groupe#plus (a, b)
  let mul_real a b = Real.meth#mult (a, b)
  let sous_real a b = Real.meth#groupe#plus (a, (Real.meth#groupe#oppose b))
  let div_real a b = Real.meth#mult (a, (Real.meth#inverse b))
  let equal_real a b = Real.meth#groupe#egal (a, b)
  let opp_real a = Real.meth#groupe#oppose a
  let lt_real a b = Real.meth#inferieur (a, b)
  let gt_real a b = not (Real.meth#inferieur (a, b))

  let add_integer a b = Integer.meth#groupe#plus (a, b)
  let mul_integer a b = Integer.meth#mult (a, b)
  let sous_integer a b = Integer.meth#groupe#plus 
			   (a, (Integer.meth#groupe#oppose b))
  let opp_integer a = Integer.meth#groupe#oppose a
  let div_integer a b = Integer.meth#divEntiere (a, b)
  let mod_integer a b = sous_integer a (mul_integer (div_integer a b) b)
  let equal_integer a b = Integer.meth#groupe#egal (a, b)
  let lt_integer a b = Integer.meth#inferieur (a, b)
  let gt_integer a b = not (Integer.meth#inferieur (a, b))

  let get_add_neutral () = Integer.meth#groupe#getNeutre
  let get_mult_neutral () = Integer.meth#getZero

end
