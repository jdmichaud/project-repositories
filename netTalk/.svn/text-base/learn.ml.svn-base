

let rec makeact tps rezal strin tl pos act=
  match tps with
      0-> act
    |x -> makeact (tps-1) rezal strin tl  (pos+1) 
       (Activnn.activ rezal (Makein.entries_of_string strin pos tl) act tl) 




let rec nrj_once str pos res rezal tl=
   let inp = Makein.entries_of_string str pos tl in
    let (n,l) = Activnn.activ rezal inp ([],[]) tl in
    let (toto,re) = List.split l in
    let absfloat a = if a > 0. then a else -.a in
    let rec diffall l1 l2 acc=
      match (l1,l2) with
	|([],[]) -> acc
	|(a::q,b::g) -> diffall q g (acc +. (absfloat (a-.b)))
	|_ -> failwith "nrj_once"
    in
      if pos < String.length res then 
	diffall re (Phoneme.getphonememask (String.get res pos)) 0.
      else
	0.

let rec nrj_word str res rezal tl pos nbj=
  if pos = String.length str then
    nbj
  else
    nrj_word str res rezal tl (pos + 1) (nbj +. nrj_once str pos res rezal tl) 

let rec nrj bd rezal tl nbj =
  match bd with
    |[] -> nbj
    |(str,res)::q -> nrj q rezal tl (nbj +. (nrj_word str res rezal tl 0 0.)) 
  

let rec calcerroronce str pos res rezal tl=
  begin
    let inp = Makein.entries_of_string str pos tl in
    let (n,l) = Activnn.activ rezal inp ([],[]) tl in
    let (toto,re) = List.split l in
    let phon = Phoneme.getphoneme re in
    let absfloat a = if a > 0. then a else -.a in
    let rec diffall l1 l2 acc=
      match (l1,l2) with
	|([],[]) -> acc
	|(a::q,b::g) -> diffall q g (acc +. (absfloat (a-.b)))
	|_ -> failwith "diffall"
    in
      if pos < String.length res then 
	begin
	  if phon = String.get res pos then
	    (0,1, diffall re (Phoneme.getphonememask (String.get res pos)) 0.)
	  else 
	    (1,1, diffall re (Phoneme.getphonememask (String.get res pos)) 0.)
	end
      else
	if phon = ' ' then
	  (0,0, diffall re (Phoneme.getphonememask (' ')) 0. )
	else
	  (1,1, diffall re (Phoneme.getphonememask (' ')) 0.)                                          
  end

let rec calcerrorword str res rezal tl (nberr, nbtot,nrtot) pos=
(*  print_string "calcerrorword\n";*)
 if pos = String.length str then
   (nberr, nbtot, nrtot)
 else
   let (nerr, ntot, nrj) = calcerroronce str pos res rezal tl in
     calcerrorword str res rezal tl (nberr + nerr, nbtot + ntot, nrj +. nrtot) (pos + 1)


let rec calcerror bd rezal tl (nberr, nbtot, nrtot)=
  match bd with
    |[] -> ((float_of_int nberr) /. (float_of_int nbtot) *. 100., nrtot)
    |(str, res)::q -> 
       let (err, tot, nrj) = calcerrorword str res rezal tl (0,0, 0.) tl in
	 calcerror q rezal tl (nberr + err, nbtot + tot, nrtot +. nrj)

let rec learn_word strin strout rezal tl eps=
(*  print_string "learn_word\n";*)
  let rec learnrec strin strout rezal tl pos =
(*    print_string "learnrec\n";*)
    if pos = String.length strin then rezal
    else
      if pos-tl < String.length strout then
	begin
(*	  print_string "cas 1\n";*)
	  let inp = Makein.entries_of_string strin pos tl in
	  let outp = Phoneme.getphonememask (String.get strout (pos-tl)) in
	  let act = makeact tl rezal strin tl (pos-tl) ([],[]) in
	  let new_resal = Apprentnn.apprent rezal eps inp outp act in
	    learnrec strin strout new_resal tl (pos+1)
	end
      else
	learnrec strin strout 
	  (Apprentnn.apprent rezal eps (Makein.entries_of_string strin pos tl)
	     (Phoneme.getphonememask ' ')
	     (makeact tl rezal strin tl (pos-tl) ([],[])) ) 
	  tl (pos+1) 
  in
    learnrec strin strout rezal tl tl

let min a b= if a < b then a else b

let rec learn bd test rezal tl eps errmin error nrj2=
  if (errmin < error) then (rezal, errmin, nrj2)
  else
    match bd with
      [] -> (rezal,errmin, nrj2)
    |(input, out)::q ->
       begin
	 let (err, nrj1) = calcerror test rezal tl (0,0, 0.) in
	   (*FIXED*)
	   (*print_float err ;*)
	   Printf.printf "%f" err;
	   print_string "   ";
	   (*print_float errmin;*)
	   Printf.printf "%f" errmin;
	   print_string "   ";
	   (*print_float (nrj test rezal tl 0.);*)
	   Printf.printf "%f" nrj1;
	   (*Printf.printf " %f" (nrj test rezal tl 0.);*)
	     
	   print_newline ();
	   
	   if err < error then
             (rezal, err, nrj1)
           else
	     (learn q test (learn_word input out rezal tl eps) tl eps (min errmin err) error 0.)
       end

let learnall bd test rezal tl eps error =
  let rec lall bd test rezal tl error errmin =
    let (errcour, nrj) = calcerror test rezal tl (0,0,0.) in
    if errcour <= error then
      rezal
    else
      begin
	(*print_string "Appris la base\n";*)
	let (nres, nerr, nrj) = (learn bd test rezal tl eps (min errmin errcour) error nrj) in
	  lall bd test nres tl error (min errcour nerr);
      end
  in
    lall bd test rezal tl error 100.
  
