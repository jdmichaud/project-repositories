(* This file describres Poule algebra *)

(* Class magma *)
class virtual magma =
object
  method toString = "magma"
end

(* Class monoide *)
class virtual ['a] monoide (n : 'a) =
object
  inherit magma
  val neutre = n
  method getNeutre = neutre
  method toString = "monoide (neutre : )"
end

(* Class groupe *)
class virtual ['a] groupe (n : 'a) =
object
  inherit ['a] monoide (n)
  method virtual oppose : 'a -> 'a
  method virtual egal : 'a * 'a -> bool
  method virtual plus : 'a * 'a -> 'a
  method toString = "groupe (neutre : , loi : )"
end

(* Class anneau *)
class virtual ['a] anneau (n : 'a) (g : ('a) groupe) =
object
  val grp = g
  val zero = n
  method getZero = zero
  method virtual mult : 'a * 'a -> 'a
  method groupe = grp
  method toString = "anneau ("^(grp#toString)^", loi2 : )"
end

(* Class anneau ordonne *)
class virtual ['a] anneauOrdonne (n : 'a) (g : ('a) #groupe) =
object
  inherit ['a] anneau n g
  method virtual inferieur : 'a * 'a -> bool
end

(* Class anneau euclidien *)
class virtual ['a] anneauEuclidien (n : 'a) (g : ('a) #groupe) =
object
  inherit ['a] anneau n g
  method virtual divEntiere : 'a * 'a -> 'a
end

(* Class anneau ordonne euclidien *)
class virtual ['a] anneauOrdonneEuclidien (n : 'a) (g : ('a) #groupe) =
object
  inherit ['a] anneau n g
  method virtual inferieur : 'a * 'a -> bool
  method virtual divEntiere : 'a * 'a -> 'a
end

(* Class coprs *)
class virtual ['a] corps (n : 'a) (g : ('a) #groupe) =
object
  inherit ['a] anneau n g
  method virtual inverse : 'a -> 'a
  method toString = "groupe ("^(grp#toString)^", loi2 : )"
end

(* Class coprs ordonne *)
class virtual ['a] corpsOrdonne (n : 'a) (g : ('a) #groupe) =
object
  inherit ['a] corps n g
  method virtual inferieur : 'a * 'a -> bool
end

(* Signature of the module anneau *)
module type Anneau =
 sig
  type t
  val meth: t anneau
  val toString : t -> string
  val ofString : string -> t
 end

(* Signature of the module anneau ordonne *)
module type AnneauOrdonne = 
sig
  type t
  val meth: t anneauOrdonne
  val toString : t -> string
  val ofString : string -> t
end

(* Signature of the module anneau euclidien *)
module type AnneauEuclidien =
sig 
  type t
  val meth: t anneauEuclidien
  val toString : t -> string
  val ofString : string -> t
end

(* Signature of the module anneau ordonne euclidien *)
module type AnneauOrdonneEuclidien =
sig
  type t
  val meth: t anneauOrdonneEuclidien
  val toString : t -> string
  val ofString : string -> t
end

(* Signature of the module corps *)
module type Corps =
sig
  type t
  val meth: t corps
  val toString : t -> string
  val ofString : string -> t
end

(* Signature of the module corps ordonne *)
module type CorpsOrdonne =
sig
  type t
  val meth: t corpsOrdonne
  val toString : t -> string
  val ofString : string -> t
end
