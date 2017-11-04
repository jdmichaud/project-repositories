(* interpreter.mli *)

module type S =
sig
  val eval : string -> bool -> out_channel -> int
  val toplevel : unit -> unit
end

module Make (Fs : Formal_system.FORMAL_SYSTEM) : S
  
