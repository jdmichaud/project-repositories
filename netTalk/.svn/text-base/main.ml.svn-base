let rec printallbd bd rezal tl=
match bd with
  [] -> ()
  |(a,b)::q ->
     begin
       print_string a;
       print_string " -> ";
       print_string b;
       print_string " -> ";
       for i = tl to String.length a - 1 do
         let inp = Makein.entries_of_string a i tl in
	 let (n,l) = Activnn.activ rezal inp ([],[]) tl in
	 let (toto,re) = List.split l in
	 let phon = Phoneme.getphoneme re in
	   print_char phon
       done; 
       print_newline ();
	 printallbd q rezal tl
     end


let transform str rezal tl=
  for i = tl to String.length str - 1 do
    let inp = Makein.entries_of_string str i tl in
    let (n,l) = Activnn.activ rezal inp ([],[]) tl in
    let (toto,re) = List.split l in
    let phon = Phoneme.getphoneme re in
      print_char phon
  done


let _ = 
  begin
    Random.self_init (); 
      match Sys.argv.(1) with
	  "t" ->
	    let (eps,rezal) =Nnconf.main Nnconfscan.lexer (Lexing.from_channel (open_in Sys.argv.(2))) 
	    in 
	      (*Printnn.print rezal;*)
	      let bd = Csv.get_bd Sys.argv.(3) 
	      in let nbent = (List.length (fst (List.hd (fst rezal)))) in
	      let tl = (List.length (List.hd(fst (List.hd (fst rezal)))))
	      in
	      let nbd = (Makein.adjust_bd bd tl) in
	      let (test, apprbd) = Csv.random_db nbd (List.length bd / 100) in
	      let nres = Learn.learnall nbd nbd rezal tl eps
			   (float_of_string Sys.argv.(4)) in
		begin
		  printallbd bd rezal tl;
		  Save.save_rezal rezal (Sys.argv.(5))
		end
		    
	| "a" ->
	    let rezal =Nndesc.main Nndescscan.lexer (Lexing.from_channel(open_in Sys.argv.(2)) ) 
	    in 
	    let tl = (List.length (List.hd(fst (List.hd (fst rezal)))))
            in
	      begin
                transform (Sys.argv.(3)) rezal tl;
                print_newline ()
              end

	| _ -> print_string "Bad argument\n\tsyntaxe : ./bobTalk t file bd error\n ./bobtalk a file\n"
  end
 
