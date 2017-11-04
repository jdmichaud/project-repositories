let print (timel, norml)=
  let rec print_floatlist l c=
    match l with
	[] -> ()
      |[a] -> print_float a
      |a::q -> print_float a;print_string c ;print_floatlist q c
  in
    
  let rec print_floatlistlist l=
    match l with
	[] -> ()
      |a::q -> print_floatlist a "," ;print_newline ();print_floatlistlist q
  in
  let print_tl (l,b) =
    print_string "\n";
    print_floatlistlist l;
    print_string "B:";
    print_float b;
    print_newline ()
  in 
  let rec print_tllist l=
    match l with
	[] -> print_newline ()
      |a::q -> print_tl a; print_tllist q
  in
  let print_n (l,b) =
    print_string "\n";
    print_floatlist l "\n";
    print_newline ();
    print_string "B:";
    print_float b;
    print_newline ()
  in
  let rec print_nlist l =
    match l with
	[] -> print_newline ()
      |a::q -> print_n a; print_nlist q
  in
    print_tllist timel;
    print_string "\n#\n";
    print_nlist norml
    
