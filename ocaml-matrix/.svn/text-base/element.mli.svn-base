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

(* Some Elements *)
module Int : ELEMENT with type t = int
module Float : ELEMENT with type t = float
