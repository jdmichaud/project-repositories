let phonemelist =['\'';'/';'A';'E';'N';'O';'R';'^';'a';'b';'c';'d';'e';'f';'g';'i';'j';'k';'l';'m';'n';'o';'p';'r';'s';'t';'u';'v';'y';'z';'£';'â';'è';'é';'ê';'ï';'ô';'û';'ü';'ÿ';' ']



let getphonememask c =
  let rec getphon li =
    match li with 
	h :: t when c = h -> 1.::getphon t
      | h :: t -> -1.::getphon t
      | [] -> []
  in
    getphon phonemelist

let  getphoneme li=
  let rec myargmax l arg max phon=
    match (l, phon) with
	([],[]) -> arg
      |(a::q, b::g) when a > max -> myargmax q b a g
      |(a::q, b::g) -> myargmax q arg max g
      | _ -> failwith "getphoneme"
  in
    myargmax li '@' (-2.) phonemelist
