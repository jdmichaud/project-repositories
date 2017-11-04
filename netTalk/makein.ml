let make_fen str pos tl=
  begin
  (*  Printf.printf " str:%s|long:%d pos:%d tl:%d\n" str (String.length str) pos tl;*)
    String.sub str (pos-tl+1) tl 
  end 

let permutlist l =
  let rec add_l_to_l l1 l2 =
    match (l1, l2) with
	([],_) -> []
      |(a::q,[]) -> [a]::(add_l_to_l q [])
      |(a::q, b::g) -> (b@[a])::(add_l_to_l q g)
  in
  let rec permutrec l res=
    match l with
      |[] -> res
      |a::q -> permutrec q (add_l_to_l a res)
  in
    permutrec l []

let entries_of_string str pos tl=
(*  Printf.printf "entries: str:%s|long:%d pos:%d tl:%d\n" str (String.length str) pos tl;*)
  let rec entrec str i=
      if i = String.length str then []
      else (Letters.letter_to_list (String.get str i))::(entrec str (i+1))
  in
    if pos >=  tl then
    
      permutlist (entrec (make_fen str pos tl) 0)
    else 
      let adj = String.make (tl) ' ' in
      let nstr = String.concat "" [adj;str] in
	permutlist (entrec (make_fen nstr (pos+tl) tl) 0)



let adjust_string str tl=
  let adj = String.make (tl-1) ' ' in
    String.concat "" [str;adj]

let rec adjust_bd bd tl=
  match bd with
    |[] -> []
    |(e,d)::q -> (adjust_string e tl,d)::(adjust_bd q tl)
