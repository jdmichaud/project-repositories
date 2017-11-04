(* This file describes the integers in Poule *)

open Algebre;;

class grEntiers (n : int) =
object
  inherit [int] groupe n
  method egal (x, y) = (x = y) (* Definition of operator egal *)
  method plus (x, y) = x + y (* Definition of operator plus *)
  method oppose x = -x (* Definition of oppose *)
end

class entiers (n : int) (g : (int) #groupe) =
object (this)
  inherit [int] anneauOrdonneEuclidien n g
  method mult (x, y) = x * y (* Definition of operator times *)
  method inferieur (x, y) = x < y (* Definition of operator inf *)
  method divEntiere (x, y) = x / y (* Definition of operator divide *)
end

module Entiers : AnneauOrdonneEuclidien =
struct
  type t = int
  let meth = (new entiers 1 (new grEntiers 0))
  let toString = string_of_int
  let ofString = int_of_string
end
