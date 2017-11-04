(* tlneuron = time lagged neuron = liste de (liste de poids ) * biais *)
type tlneuron = float list list * float

(*nneuron = "neuron normal" = liste de poids * biais*)
type nneuron = float list * float

type network = tlneuron list * nneuron list

