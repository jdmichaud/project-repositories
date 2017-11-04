open Element

(* Define the matrix signature *)
module type MATRIX = sig

  (* The element *)
  type elt
  (* The matrix *)
  type 'a matrix

  (* Create a simple matrix *)
  val create : int -> int -> elt -> elt matrix

  (* Create the matrix from [l] *)
  val of_list : elt list list -> elt matrix

  (* Matrix size : row * col *)
  val size : elt matrix -> (int * int)

  (* Get value : row * col *)
  val get : elt matrix -> int -> int -> elt

  (* Set a value *)
  val set : elt matrix -> int -> int -> elt -> elt matrix

  (* Iter on matrix elements with [f] *)
  val iter : (elt -> unit) -> elt matrix -> unit

  (* Map matrix [mat] with [f] *)
  val map : (elt -> 'a) -> elt matrix -> 'a matrix

  (* Apply [f] on 2 matrix *)
  val map2 : (elt -> 'a -> 'b) -> elt matrix -> 'a matrix -> 'b matrix

  (* Create an identity matrix *)
  val identity : int -> elt matrix

  (* Create a random matrix *)
  val random : int -> int -> elt -> elt matrix

  (* Transpose the matrix *)
  val transpose : elt matrix -> elt matrix

  (* Print the matrix *)
  val print : elt matrix -> unit

  (* Basic operations on a matrix and an element *)
  val add_elem : elt matrix -> elt -> elt matrix
  val sub_elem : elt matrix -> elt -> elt matrix
  val mul_elem : elt matrix -> elt -> elt matrix
  val div_elem : elt matrix -> elt -> elt matrix

  (* Basic operations on 2 matrix *)
  val add : elt matrix -> elt matrix -> elt matrix
  val sub : elt matrix -> elt matrix -> elt matrix
  val mul : elt matrix -> elt matrix -> elt matrix

end


(* Keep the old array *)
module Std_array = Array

module Array = struct
  include List

  let get = nth

end

module GenMatrix (Elt : ELEMENT) = struct

  type elt = Elt.t

  type 'a matrix =
    {
      mat : 'a list list; (* Hold values within lists *)
      row : int;          (* row size *)
      col : int;          (* column size *)
    }


  (***********************************************)
  (*                  Create                     *)
  (***********************************************)

  (* Create a list of length [n] with value [def] *)
  let make_list def n =
    let rec make_list_ acc = function
      | 0 -> acc
      | n -> make_list_ (def :: acc) (n - 1)
    in
    make_list_ [] n

  (* Create a 'a list list of size row * col *)
  let make_matrix row col def =
    let line = make_list def col in
    make_list line row

  (* Replace a value with [v] within a list at pos [i] *)
  let list_replace v i l =
    let rec insert_ acc pos = function
      | [] -> []
      | h :: t when pos = i -> (List.rev (v :: acc)) @ t
      | h :: t -> insert_ (h :: acc) (pos + 1) t
    in
    insert_ [] 0 l

  (* Create the matrix *)
  let create rows cols def =
    assert (rows > 0 && cols > 0);
    {
      mat = make_matrix rows cols def;
      row = rows;
      col = cols;
    }

  (* Create the matrix from [l] *)
  let of_list l =
    let len = List.length (List.hd l) in
    List.iter (fun x -> assert (List.length x = len)) l;
    {
      mat = l;
      row = List.length l;
      col = len;
    }


  (***********************************************)
  (*              Generic Operations             *)
  (***********************************************)

  (* Matrix size *)
  let size mat = (mat.row, mat.col)

  (* Get value : row * col *)
  let get mat row col =
    assert (row < mat.row && col < mat.col && row >= 0 && col >= 0);
    mat.mat.(row).(col)

  (* Set a value *)
  let set mat row col v =
    assert (row < mat.row && col < mat.col && row >= 0 && col >= 0);
    let res = list_replace v col mat.mat.(row) in
    {
      mat = list_replace res row mat.mat;
      row = mat.row;
      col = mat.col;
    }

  (* Iter on matrix elements with [f] *)
  let iter f mat = List.iter (fun x -> List.iter f x) mat.mat

  (* Map matrix [mat] with [f] *)
  let map f mat =
    {
      mat = List.map (fun x -> List.map f x) mat.mat;
      row = mat.row;
      col = mat.col;
    }

  (* Apply f on mat1 and mat2 *)
  let rec map2 f mat1 mat2 =
    assert (mat1.row = mat2.row && mat1.col = mat2.col);
    {
      mat = List.map2 (fun x y -> List.map2 f x y) mat1.mat mat2.mat;
      row = mat1.row;
      col = mat1.col;
    }

  (* Create an identity matrix *)
  let identity size =
    let make_id_list i n =
      let rec make_id_list_ acc = function
        | 0 -> acc
        | n when n = i -> make_id_list_ (Elt.one :: acc) (n - 1)
        | n -> make_id_list_ (Elt.zero :: acc) (n - 1)
      in
      make_id_list_ [] n
    in
    {
      mat = (
        let rec make_id acc = function
          | 0 -> acc
          | n -> make_id (make_id_list n size :: acc) (n - 1)
        in
        make_id [] size);
      row = size;
      col = size;
    }

  (* Create a random matrix *)
  let random row col lim =
    let mat = create row col lim in
    Random.self_init ();
    map Elt.random mat

  (* Transpose the matrix *)
  let transpose mat =
    let rec get_line acc acc2 = function
      | []  -> (List.rev acc, List.rev acc2)
      | [] :: t -> get_line acc acc2 t
      | (h1 :: []) :: t -> get_line (h1 :: acc) acc2 t
      | (h1 :: t1) :: t -> get_line (h1 :: acc) (t1 :: acc2) t
    in
    let rec app acc = function
      | [] -> List.rev acc
      | m ->
          let (l, tmpmat) = get_line [] [] m in
          app (l :: acc) tmpmat
    in
    {
      mat = app [] mat.mat;
      row = mat.col;
      col = mat.row;
    }

  (* Print the matrix *)
  let print mat =
    List.iter (fun x ->
      List.iter (fun y ->
        Elt.print y; print_string "\t")
      x; print_newline ())
    mat.mat


  (***********************************************)
  (*            Op on Elements                   *)
  (***********************************************)

  (* Basic operations on a matrix and an element *)
  let apply_elem f mat elem = map (fun x -> f x elem) mat

  let add_elem = apply_elem Elt.add
  let sub_elem = apply_elem Elt.sub
  let mul_elem = apply_elem Elt.mul
  let div_elem = apply_elem Elt.div

  (* Basic operations on 2 matrix *)
  let add = map2 Elt.add

  let sub = map2 Elt.sub

  let mul mat1 mat2 =
    assert (mat1.col = mat2.row);
    let compute_elem l1 l2 =
      let l = List.map2 (fun x y -> Elt.mul x y) l1 l2 in
      List.fold_left Elt.add Elt.zero l
    in
    let compute_line l1 l2 = List.map (compute_elem l1) l2 in
    let res =
      let trans = transpose mat2 in
      List.map (fun x -> compute_line x trans.mat) mat1.mat
    in
    {
      mat = res;
      row = mat1.row;
      col = mat2.col;
    }


  (* Do not forget the determinant *)

end


(******************************)
(* Define some useful modules *)
(******************************)

module IntMatrix = GenMatrix (Int)
module FloatMatrix = GenMatrix (Float)
