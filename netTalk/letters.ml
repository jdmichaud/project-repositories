let letters = [ '\'';'-';'a';'b';'c';'d';'e';'f';'g';'h';'i';'j';'k';'l';'m';'n';'o';'p';'q';'r';'s';'t';'u';'v';'w';'x';'y';'z';'à';'â';'ç';'è';'é';'ê';'ë';'î';'ï';'ô';'ù';'û';' ']

let letter_to_list c =
  let rec lettrec c refl =
    match refl with
      |[] -> []
      |a::q when a = c  -> 1.::(lettrec c q)
      |a::q -> -1.::(lettrec c q)
  in
    lettrec c letters

