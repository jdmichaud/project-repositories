open Algebre;;

module type Typesig =
sig
  type real
  type integer
    
  val to_string_real: real -> string
  val of_string_real: string -> real

  val to_string_integer: integer -> string
  val of_string_integer: string -> integer
    
  val add_real: real -> real ->real
  val mul_real: real -> real ->real
  val sous_real: real -> real ->real
  val opp_real : real -> real
  val div_real: real -> real ->real
  val equal_real: real -> real -> bool
  val lt_real: real -> real -> bool
  val gt_real: real -> real -> bool

  val add_integer: integer -> integer -> integer
  val mul_integer: integer -> integer -> integer
  val sous_integer: integer -> integer -> integer
  val opp_integer:integer -> integer
  val div_integer: integer -> integer ->integer
  val mod_integer: integer -> integer -> integer
  val equal_integer: integer -> integer -> bool
  val lt_integer: integer -> integer -> bool
  val gt_integer: integer -> integer -> bool

  val get_add_neutral: unit -> integer
  val get_mult_neutral: unit -> integer

end
