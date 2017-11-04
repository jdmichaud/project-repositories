open Astsig

module Entity (Ast:Astsig)= 
struct
  open Ast

  class entity a =
  object(self)
    val mutable ast = a; (* The ast of the entity *)
    val mutable poly = []; (* The list represents the polynom of the entity *)
    val mutable astuptodate = true;
    val mutable polyuptodate = false;
    
    (* getdeg returns the degree of an entity *)
    method private getdeg a =
      match a with
	  Elt(Id(v))-> (Elt(Id(v)),Elt(Integer(M.of_string_integer "1")),0)
	|Funccall(f,e) -> (Funccall(f,e),
			   Elt(Integer(M.of_string_integer "1")),
			   0)
	|Binop(Power,Elt(Id(v)),a) -> (Elt(Id(v)),a,0)
	|Binop(Power,Funccall(f,e),a) -> (Funccall(f,e),a,0)
	|_ as e -> (e,e,-1)

    (* putmoins insert minus in the poly of an entity *)
    method private putmoins l =
      match l with
	  [] -> [] 
	|(f,v,e)::q -> (Min(f),v,e)::(self#putmoins q)

    (* astotopoly converts an ast to a polynom *)
    method asttopoly a =
      let rec asttopolyrec a =
	match a with
	    Elt(Id(i)) as e-> [(Elt(Integer(M.of_string_integer "1")),
				e,
				Elt(Integer(M.of_string_integer "1")))]
	  | Elt(e)  -> [(Elt(e),Elt(Id(Identifier("x"))),
			 Elt(Integer(M.of_string_integer "0")))]
	  | Funccall(f,e) -> [(Elt(Integer(M.of_string_integer "1")),
			       Funccall(f,e),
			      Elt(Integer(M.of_string_integer "1")))]
	  |Binop(Plus,c,b) -> (asttopolyrec c)@(asttopolyrec b)
	  |Binop(Minus,c,b) -> (asttopolyrec c)@(asttopolyrec (Min(b)))
	  |Binop(Power,c,b) ->[(Elt(Integer(M.of_string_integer "1")),
				c,
				b)]
	  |Min(a) -> self#putmoins (asttopolyrec a)
	  |Binop(Times,c,b) -> 
	     begin
	       let (vara,da,va) = self#getdeg c
	       in let (varb,db,vb) = self#getdeg b in
		 match (va,vb) with
		     (-1,-1) -> [(Binop(Times,c,b),Elt(Id(Identifier("x"))),
				  Elt(Integer(M.of_string_integer  "0")))]
		   |(0,-1) -> [(b,vara,da)]
		   |(-1,0) -> [(c, varb,db)]
		   |_ -> 
		      begin
			
			match (da,db) with
			    (Elt(Integer(x)),Elt(Integer(y))) ->  
			      if vara <> varb then 
				[(Elt(Integer(M.of_string_integer "1"))
				    ,(Binop(Times,c,b)),
				    Elt(Integer(
					  M.of_string_integer "1")))]
			      else
				[(Elt(Integer(M.of_string_integer "1"))
				    ,vara, Elt(Integer(M.add_integer x y)))]
			  | (Elt(Float(x)),Elt(Float(y))) ->
			      if vara<>varb then 
				[(Elt(Integer(M.of_string_integer "1"))
				    ,(Binop(Times,c,b)),
				    Elt(Integer(
					  M.of_string_integer "1")))]
			      else
				[(Elt(Integer(M.of_string_integer "1"))
				    ,vara,Elt(Float(M.add_real x y)))]
			  |_ -> [(Elt(Integer(M.of_string_integer "1"))
				    ,(Binop(Times,c,b)),
				    Elt(Integer(
					  M.of_string_integer "1")))]
		      end
	     end
	  |_ as e -> [(e,Elt(Id(Identifier("x"))),
		       Elt(Integer(M.of_string_integer "0")))]
      in
	asttopolyrec a
	
    (* polytotast converts a polynom to an ast *)
    method polytoast a = 
      let rec polytoastrec a acu=
	match a with 
	    []  -> acu
	  |(b,v,c)::t -> polytoastrec t (Binop(Plus,
					       Binop(Times,b,
						     Binop(Power,v,c)),
					       acu)) 
      in
      if a = [] then Elt(Integer(M.of_string_integer  "0"))
      else
	let (b,v,c) = List.hd a in
	  polytoastrec (List.tl a) (Binop(Times,b,
					  Binop(Power,v,c)))

    (* returns the ast of an entity *)
    method getAst = if astuptodate then ast
    else
      begin
	ast <- self#polytoast poly;
	astuptodate <- true;
	ast;
      end;
      
    (* returns the polynom of an entity *)
    method getPoly = if polyuptodate then poly
    else
      begin
	poly <- self#asttopoly ast;
	polyuptodate <- true;
	poly;
      end;    

    (* set the ast of an entity with the value a*)
    method setAst a = 
      begin
	ast <- a;
	polyuptodate <- false;
      end
      
    (* set the poly of an entity with the value a*)
    method setPoly a = 
      begin
	poly <- a;
	astuptodate <- false;
      end  
  end 
end
