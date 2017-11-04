(*reseau est le resau de neurones de la forme decrite dans network.mli
et entrees une liste de liste de float compris entre -1 et 1
représentant les différents paramètres et leur précédentes valeurs

Cette fonction renvoie un couple de listes de couple de float
Explication: chaque couple de float repésente la valeur avant et apres
application de la sigmoide de la sortie de chaque neurone. Chaque
liste représente donc la sortie de chaque couche
*)

let phi x = 2. /. (1. +. exp(-.x)) -. 1.
let phiprime x= 2. *. (1. /. (1. +. exp(-.x)) -. 1. /. ((1. +. exp(-.x)) *. (1. +. exp(-.x))))


let rec cut_last l=
  match l with
    |[] -> failwith "cut_last : liste vide"
    |[a] -> []
    |a::q -> a::(cut_last q) 

let rec activ (tl, norm) entrees (patl, pann) ntl=
  let rec apply_tlneur entrees (l,b) =
    let rec apply_tloneparam le l=
      
	match (le, l) with
	    ([],[]) -> 0.
	  |(a::q, v::g) -> (a *. v) +. (apply_tloneparam q g)
	  |_ -> failwith "apply_tloneparam"
    in
      begin
	(*Printf.printf "entree:%d l:%d\n" (List.length entrees) (List.length l);*)
	match (entrees,l) with
	  ([],[]) -> b  
	  |(a::q, v::g) -> (apply_tloneparam a v) +. (apply_tlneur q (g,b))
	  |_ -> failwith "applytloneparam"
      end
  in
  let rec apply_tlcouche entrees l patl=
    match (l, patl) with
      |([],[]) -> []
      |(a::q, b::g) -> let act = apply_tlneur entrees a in
	  if ntl > List.length b then
			 ((act, phi act)::b)::(apply_tlcouche entrees q g) 
	  else
	    ((act, phi act)::cut_last b)::(apply_tlcouche entrees q g)
      |(a::q, []) -> let act = apply_tlneur entrees a in
	  [ (act, phi act)]::(apply_tlcouche entrees q [])
      |_ -> failwith "apply_tlcouche"
  in
  let rec apply_nneur lent (l,b) =
    match (lent,l) with
	([],[]) -> b
      |(a::q, v::g) -> (snd (List.hd a)) *. v +. (apply_nneur q (g,b))
      |_ -> failwith "apply_nneur"
  in
  let rec apply_ncouche lent l =
    match l with
	[] -> []
      |a::q -> let act = apply_nneur lent a in
	  (act, phi act)::(apply_ncouche lent q)
  in
  let acttl = apply_tlcouche entrees tl patl in
  let actnorm = apply_ncouche acttl norm in
    (acttl, actnorm)
