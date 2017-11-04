open Element
open Matrix

module ArrayMatrix (Elt : ELEMENT) = struct

  type elt = Elt.t

  type 'a matrix =
    {
      mat : 'a array array; (* Hold values within arrays *)
      row : int;            (* row size *)
      col : int;            (* column size *)
    }

  let apply mat f =
    for i = 0 to mat.row - 1 do
      for j = 0 to mat.col - 1 do
        mat.mat.(i).(j) <- f mat.mat.(i).(j)
      done
    done

  (* Create the matrix *)
  let create row col def =
    {
      mat = Array.make_matrix row col def;
      row = row;
      col = col;
    }

  (* Create the matrix from [l] *)
  let of_list l =
    let len = List.length (List.hd l) in
    List.iter (fun x -> assert (List.length x = len)) l;
    let tmp_mat = List.map Array.of_list l in
    {
      mat = Array.of_list tmp_mat;
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

  (* Set a value, modify the current matrix *)
  let set mat row col v =
    assert (row < mat.row && col < mat.col && row >= 0 && col >= 0);
    mat.mat.(row).(col) <- v;
    mat

  (* Iter on matrix elements with [f] *)
  let iter f mat = Array.iter (fun x -> Array.iter f x) mat.mat

  (* Map matrix [mat] with [f] *)
  let map f mat =
    {
      mat = Array.map (fun x -> Array.map f x) mat.mat;
      row = mat.row;
      col = mat.col;
    }

  (* Apply f on mat1 and mat2 *)
  let rec map2 f mat1 mat2 =
    assert (mat1.row = mat2.row && mat1.col = mat2.col);
    let tmp_mat =
      Array.make_matrix mat1.row mat1.col (f mat1.mat.(0).(0) mat2.mat.(0).(0))
    in
    for i = 0 to mat1.row - 1 do
      for j = 0 to mat1.col - 1 do
        tmp_mat.(i).(j) <- (f mat1.mat.(i).(j) mat2.mat.(i).(j))
      done
    done;
    {
      mat = tmp_mat;
      row = mat1.row;
      col = mat1.col;
    }

  (* Create an identity matrix *)
  let identity size =
    let tmp_mat = Array.make_matrix size size Elt.zero in
    for i = 0 to size - 1 do
      tmp_mat.(i).(i) <- Elt.one
    done;
    {
      mat = tmp_mat;
      row = size;
      col = size;
    }

  (* Create a random matrix *)
  let random row col lim =
    Random.self_init ();
    {
      mat = 
        Array.init row (fun _ -> Array.init col (fun _ -> Elt.random lim));
      row = row;
      col = col;
    }

  (* Transpose the matrix *)
  let transpose mat =
    {
      mat = (
        Array.init mat.col (fun i ->
          Array.init mat.row (fun j -> mat.mat.(j).(i)))
      );
      row = mat.col;
      col = mat.row;
    }

  (* Print the matrix *)
  let print mat =
    Array.iter (fun x ->
      Array.iter (fun y ->
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
    let elem i j =
      let res = ref Elt.zero in
      for k = 0 to mat1.col - 1 do
        res := Elt.add !res (Elt.mul mat1.mat.(i).(k) mat2.mat.(k).(i))
      done;
      !res
    in
    {
      mat = (
        Array.init mat1.row (fun i ->
          Array.init mat2.col (fun j -> elem i j))
      );
      row = mat1.row;
      col = mat2.col;
    }

end

(******************************)
(* Define some useful modules *)
(******************************)

module IntArrayMatrix = ArrayMatrix (Int)
module FloatArrayMatrix = ArrayMatrix (Float)
