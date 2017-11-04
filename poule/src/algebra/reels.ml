(* This file describes the floats in Poule *)

open Algebre;;

class grReels (n : float) =
object
  inherit [float] groupe n
  method egal (x, y) = (x = y) (* Definition of operator egal *)
  method plus (x, y) = x +. y (* Definition of operator plus *)
  method oppose x = -. x (* Definition of oppose *)
end

class reels (n : float) (g : (float) #groupe) =
object
  inherit [float] corpsOrdonne n g
  method mult (x, y) = x *. y (* Definition of operator times *)
  method inverse x = 1. /. x (* Definition of inverse to make divisions *)
  method inferieur (x, y) = x < y (* Definition of operator inf *)
end

module Reels : CorpsOrdonne =
struct
  type t = float
  let meth = (new reels 1. (new grReels 0.))
  let toString = string_of_float
  let ofString = float_of_string
end
