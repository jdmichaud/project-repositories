
let get_bd name =

  (*We cut file in a string list*) 
  let file_to_list =
    let ic = open_in name in
    let rec file_to_list_ l =
      try
	let line = input_line ic in
	  file_to_list_ (line :: l)
      with
	| End_of_file -> close_in ic; List.rev l
    in
      file_to_list_ []
  in 

  (*We cut a list in word list*)
  let cut s =
    let delims = Str.regexp ("[\t\r\n" ^ ";" ^"]+") 
    in Str.split delims s

  in

  (*We take only the interresting field *)
  let rec get_values l =
    match l with
	h :: t -> (List.nth (cut h) 1 , List.nth (cut h) 4) :: (get_values t)
      | [] -> []
  in
    get_values (List.tl file_to_list)

;;


(*test pretty printer*)
let rec pretty l =
  match l with
      (x , y) :: t -> print_string (x ^ "->" ^ y ^ "\n") ; pretty t 
    | [] -> print_string " "
;;

(*sortir la liste des lettres*)
let str_to_lst str=
  let rec str_rec str i=
    if i = String.length str then []
    else (String.get str i)::(str_rec str (i+1))
  in
    str_rec str 0
;;

let rec get_phon_list l =
  match l with 
      (s, d) :: t -> (str_to_lst d)@(get_phon_list t)
    | [] -> []
;;



let random_db l nbr =
  (*let rec erase_nth la nb =
    match la with
	[] ->[]
      | h :: t when nb = 0-> erase_nth t (-1)
      | h :: t -> h :: erase_nth t (nb - 1)
  in
  let rec random_list li =
    match li with
	[] -> []
      | _ -> let i = Random.int (List.length li) in List.nth li i :: random_list (erase_nth li i)
  in*)
  let separe_bd le =
    let rec separe lw a b nbre =
      match lw with
	  prem :: fin when nbre > 0 -> separe fin (prem :: a) (b) (nbre - 1)
	| prem :: fin -> separe fin a (prem :: b) (nbre - 1)
	| [] -> (a,b)
    in
      separe le [] [] nbr
  in
  let myrand a b= Random.int 7 - 3 in
    separe_bd (List.sort myrand l)
;;
