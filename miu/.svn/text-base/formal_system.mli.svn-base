(* formal_system.mli *)

module type FORMAL_SYSTEM =
sig
  type t
    (* Conversions. *)
  val of_string : string -> t
  val to_string : t -> string
  val of_stream : string Stream.t -> t
  val to_stream : t -> string Stream.t
    (* Prove. *)
  val prove : t list -> t -> bool
  val prove_trace : out_channel -> t list -> t -> bool
end
  
module Resolution : FORMAL_SYSTEM


