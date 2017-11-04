type token =
    EXP of (string)
  | EOL

open Parsing
let yytransl_const = [|
  258 (* EOL *);
    0|]

let yytransl_block = [|
  257 (* EXP *);
    0|]

let yylhs = "\255\255\
\001\000\000\000"

let yylen = "\002\000\
\002\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\000\000\002\000\001\000"

let yydgoto = "\002\000\
\004\000"

let yysindex = "\255\255\
\000\255\000\000\001\255\000\000\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000"

let yygindex = "\000\000\
\000\000"

let yytablesize = 3
let yytable = "\001\000\
\003\000\000\000\005\000"

let yycheck = "\001\000\
\001\001\255\255\002\001"

let yynames_const = "\
  EOL\000\
  "

let yynames_block = "\
  EXP\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun parser_env ->
    let _1 = (peek_val parser_env 1 : string) in
    Obj.repr((
# 10 "parser_toplevel.mly"
                      _1 ^ "\n") : string))
(* Entry line *)
; (fun parser_env -> raise (YYexit (peek_val parser_env 0)))
|]
let yytables =
  { actions=yyact;
    transl_const=yytransl_const;
    transl_block=yytransl_block;
    lhs=yylhs;
    len=yylen;
    defred=yydefred;
    dgoto=yydgoto;
    sindex=yysindex;
    rindex=yyrindex;
    gindex=yygindex;
    tablesize=yytablesize;
    table=yytable;
    check=yycheck;
    error_function=parse_error;
    names_const=yynames_const;
    names_block=yynames_block }
let line (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (yyparse yytables 1 lexfun lexbuf : string)
