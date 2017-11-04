(* apprentisseur prend: un reseau du type decrit dans nework.ml, une
liste d'entrees et une liste des sorties renvoie: un reseau tout
neuf*)


let phi x = 2. /. (1. +. exp(-.x)) -. 1.
let phiprime x= 2. *. (1. /. (1. +. exp(-.x)) -. 1. /. ((1. +. exp(-.x)) *. (1. +. exp(-.x))))


let apprent reseau eps entrees sorties act=  
  let rec de_nneur sorties act =
    match (sorties, act) with
	([],[]) -> []
      |(a::q, (ac, s)::g) -> ((phiprime ac) *. ((s -. a) -. 2. *. s))::(de_nneur q g)
      |_ -> failwith "de_nneur"
  in
  let rec detlone nde nneur nb=
    match (nneur, nde) with
	([], []) -> 0. 
      |(a::q, b::g) -> List.nth (fst a) nb *. b +. (detlone g q nb)
      |_ -> failwith "detlone"
  in
  let rec detlc tlneur nde nneur nb=
    match tlneur with
      |[] -> []
      |a::q -> (detlone nde nneur nb)::(detlc q nde nneur (nb+1))
  in
  let rec mul_list_float l fl=
    match l with
	[] -> []
      |a::q -> (phiprime (fst a) *. fl)::(mul_list_float q fl)
  in
  let de_tlcouche act tlneur nn nde=
    let tmp = detlc tlneur nde nn 0 in
    let rec fct tmp act= 
      match (tmp, act) with
	  ([],[]) ->[]
	|(a::q, b::g) -> (mul_list_float b a)::(fct q g)
	|_ -> failwith "de_tlcouche"
    in fct tmp act
  in

  let denn = de_nneur sorties (snd act) in
  let detl = de_tlcouche (fst act) (fst reseau) (snd reseau) denn
  in 
  let rec build_np tlact l  de=
    match (tlact, l) with
	([],[]) -> []
      |((s,a)::q, b::g) -> (b -. eps *. a *. de)::(build_np q g de)
      |_ -> failwith "build_np"
  in
  let rec build_nneur tlact lneur lde=
    match (lneur,lde) with
	([],[]) -> []
      |((l, b)::q,de::g) -> (build_np tlact l de, b -. eps *. de)
	 ::(build_nneur tlact q g)
      | _ -> failwith "build_nneur"
  in 
  let rec sum_de lde =
    match  lde with
	[] -> 0.
      |a::q -> a +. (sum_de q)
  in
  let rec build_tlparam  de ent l=
    match (ent,l) with
	([],[]) -> []
      |(a::q, b::g) -> (b -. eps *. de *. a)::(build_tlparam de q g)
      |_ -> failwith "build_tlparam"
  in
  let rec build_tlneur de entrees p=
    match (entrees, p) with
	([],[]) -> []
      |(a::q, b::g)-> (build_tlparam de a b)::(build_tlneur de q g)
      |_ -> failwith "build_tlneur"
  in
  let rec build_tlcouche lde entrees ln=
    begin
    match (ln, lde) with
	([], []) -> []
      |((lp, biais)::q, b::g) -> let de = sum_de b in
	  (build_tlneur de entrees lp, biais -. eps *. de)
	  ::(build_tlcouche g entrees q)
      |_ -> failwith "build_tlcouche"
    end
  in
    (build_tlcouche detl entrees (fst reseau), build_nneur (fst reseau) (snd reseau) denn)
    
    
