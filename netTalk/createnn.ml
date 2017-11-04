let create nbentree tl nbtl nbsorties=
  let rec create_floatlist n=
    match n with
	0 -> []
      |x -> (Random.float 1. -. 0.5)::(create_floatlist (x-1))
  in
  let rec create_floatlistlist nbentree tl=
    match nbentree with
	0 -> []
      |x -> (create_floatlist tl)::(create_floatlistlist (x-1) tl)
  in
  let rec create_tlneuronlist nbentree tl nbtl =
    match nbtl with
	0 -> []
      |x -> (create_floatlistlist nbentree tl, Random.float 10. -. 5.)
	 ::(create_tlneuronlist nbentree tl (nbtl - 1))
  in
  let rec create_nneuronlist nbtl nbsorties =
    match nbsorties with
	0 -> []
      |x -> (create_floatlist nbtl, Random.float 10. -. 5.)
	 ::(create_nneuronlist nbtl (x - 1))
  in
  (create_tlneuronlist nbentree tl nbtl, create_nneuronlist nbtl nbsorties)
