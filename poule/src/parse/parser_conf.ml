type token =
    EXP of (string)
  | EOL
  | EOF

open Parsing
let yytransl_const = [|
  258 (* EOL *);
    0 (* EOF *);
    0|]

let yytransl_block = [|
  257 (* EXP *);
    0|]

let yylhs = "\255\255\
\001\000\002\000\002\000\002\000\002\000\000\000"

let yylen = "\002\000\
\002\000\001\000\002\000\002\000\003\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\000\000\000\000\006\000\000\000\000\000\003\000\
\001\000\005\000"

let yydgoto = "\002\000\
\005\000\006\000"

let yysindex = "\003\000\
\000\255\000\000\003\255\000\255\000\000\006\000\000\255\000\000\
\000\000\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\007\000\000\000\000\000\008\000\000\000\
\000\000\000\000"

let yygindex = "\000\000\
\000\000\252\255"

let yytablesize = 8
let yytable = "\008\000\
\003\000\004\000\010\000\001\000\007\000\009\000\002\000\004\000"

let yycheck = "\004\000\
\001\001\002\001\007\000\001\000\002\001\000\000\000\000\000\000"

let yynames_const = "\
  EOL\000\
  EOF\000\
  "

let yynames_block = "\
  EXP\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun parser_env ->
    let _1 = (peek_val parser_env 1 : string list) in
    Obj.repr((
# 14 "parser_conf.mly"
         _1) : string list))
; (fun parser_env ->
    Obj.repr((
# 18 "parser_conf.mly"
       []) : string list))
; (fun parser_env ->
    let _2 = (peek_val parser_env 0 : string list) in
    Obj.repr((
# 19 "parser_conf.mly"
             _2) : string list))
; (fun parser_env ->
    let _1 = (peek_val parser_env 1 : string) in
    Obj.repr((
# 20 "parser_conf.mly"
             [_1^"\n"]) : string list))
; (fun parser_env ->
    let _1 = (peek_val parser_env 2 : string) in
    let _3 = (peek_val parser_env 0 : string list) in
    Obj.repr((
# 21 "parser_conf.mly"
                 (_1^"\n")::_3) : string list))
(* Entry conf *)
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
let conf (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (yyparse yytables 1 lexfun lexbuf : string list)
