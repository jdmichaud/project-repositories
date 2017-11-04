(* Define some element *)
module type ELEMENT = sig
  type t
  val zero : t
  val one : t
  val add : t -> t -> t
  val sub : t -> t -> t
  val mul : t -> t -> t
  val div : t -> t -> t
  val abs : t -> t
  val print : t -> unit
  val random : t -> t
end

(* Integers *)
module Int = struct
  type t = int
  let zero = 0
  let one = 1
  let add = (+)
  let sub = (-)
  let mul = ( * )
  let div = (/)
  let abs = abs
  let print = print_int
  let random = Random.int
end

(* Floats *)
module Float = struct
  type t = float
  let zero = 0.
  let one = 1.
  let add = (+.)
  let sub = (-.)
  let mul = ( *. )
  let div = (/.)
  let abs = abs_float
  let print = print_float
  let random = Random.float
end

