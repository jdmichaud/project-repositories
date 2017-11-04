let reseau_to_string (timel, norml)=

 let rec print_floatlist l c=
    match l with
	[] -> ""
      |[a] -> Printf.sprintf "%g" a
      |a::q -> (Printf.sprintf "%g" a)^c^(print_floatlist q c)
  in
    
  let rec print_floatlistlist l=
    match l with
	[] -> ""
      |a::q -> (print_floatlist a ",")^"\n"^(print_floatlistlist q)
  in
  let print_tl (l,b) =
    "\n"^(print_floatlistlist l)^"B:"^(string_of_float b)^"\n"
  in 
  let rec print_tllist l=
    match l with
	[] -> "\n"
      |a::q -> (print_tl a)^(print_tllist q)
  in
  let print_n (l,b) =
    "\n"^(print_floatlist l "\n")^"\nB:"^(string_of_float b)^"\n"
  in
  let rec print_nlist l =
    match l with
	[] -> "\n"
      |a::q -> (print_n a)^(print_nlist q)
  in
    (print_tllist timel)^"\n#\n"^(print_nlist norml)


let save_rezal rezal filename=
  let f = Unix.openfile filename [Unix.O_WRONLY;Unix.O_CREAT] 0o644 in
  let rezstr = reseau_to_string rezal in
    begin
      if (Unix.write f rezstr 0 (String.length rezstr)) = 
	(String.length rezstr) then
	  Unix.close f
      else
	print_string "Erreur d'ecriture dans le fichier\n"
    end
