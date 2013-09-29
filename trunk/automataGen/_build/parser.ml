type token =
  | INT of (int)
  | FLOAT of (float)
  | NAME of (string)
  | TRUE
  | FALSE
  | LPAR
  | RPAR
  | PLUS
  | MINUS
  | MULT
  | DIV
  | LSQBRAK
  | RSQBRAK
  | EOL
  | SEMICOLON
  | UNTIL
  | EVENTUALLY
  | NEXT
  | AND
  | OR
  | NOT
  | EQ
  | SG
  | SL
  | GE
  | LE

open Parsing;;
let _ = parse_error;;
# 2 "parser.mly"
  open Type

# 35 "parser.ml"
let yytransl_const = [|
  260 (* TRUE *);
  261 (* FALSE *);
  262 (* LPAR *);
  263 (* RPAR *);
  264 (* PLUS *);
  265 (* MINUS *);
  266 (* MULT *);
  267 (* DIV *);
  268 (* LSQBRAK *);
  269 (* RSQBRAK *);
  270 (* EOL *);
  271 (* SEMICOLON *);
  272 (* UNTIL *);
  273 (* EVENTUALLY *);
  274 (* NEXT *);
  275 (* AND *);
  276 (* OR *);
  277 (* NOT *);
  278 (* EQ *);
  279 (* SG *);
  280 (* SL *);
  281 (* GE *);
  282 (* LE *);
    0|]

let yytransl_block = [|
  257 (* INT *);
  258 (* FLOAT *);
  259 (* NAME *);
    0|]

let yylhs = "\255\255\
\001\000\002\000\002\000\002\000\002\000\002\000\002\000\004\000\
\004\000\004\000\004\000\004\000\004\000\003\000\003\000\003\000\
\003\000\003\000\003\000\003\000\007\000\007\000\007\000\007\000\
\007\000\006\000\006\000\006\000\006\000\006\000\006\000\005\000\
\005\000\000\000"

let yylen = "\002\000\
\002\000\003\000\004\000\002\000\003\000\002\000\003\000\002\000\
\002\000\002\000\002\000\002\000\005\000\001\000\001\000\003\000\
\003\000\002\000\003\000\003\000\001\000\001\000\001\000\001\000\
\001\000\001\000\001\000\003\000\003\000\003\000\003\000\001\000\
\001\000\002\000"

let yydefred = "\000\000\
\000\000\000\000\026\000\027\000\014\000\015\000\000\000\000\000\
\000\000\000\000\034\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\018\000\001\000\000\000\000\000\000\000\000\000\
\000\000\000\000\021\000\022\000\023\000\024\000\025\000\000\000\
\019\000\028\000\033\000\032\000\000\000\010\000\011\000\009\000\
\012\000\008\000\000\000\000\000\000\000\000\000\016\000\000\000\
\000\000\000\000\000\000\030\000\000\000\000\000\000\000\000\000\
\000\000\013\000"

let yydgoto = "\002\000\
\011\000\012\000\013\000\024\000\045\000\014\000\040\000"

let yysindex = "\015\000\
\043\255\000\000\000\000\000\000\000\000\000\000\050\255\016\255\
\016\255\050\255\000\000\018\255\099\255\103\255\004\255\098\255\
\056\255\056\255\056\255\056\255\056\255\056\255\076\255\050\255\
\076\255\050\255\000\000\000\000\016\255\050\255\050\255\067\255\
\067\255\067\255\000\000\000\000\000\000\000\000\000\000\067\255\
\000\000\000\000\000\000\000\000\003\255\000\000\000\000\000\000\
\000\000\000\000\076\255\076\255\076\255\050\255\000\000\024\255\
\067\255\042\255\042\255\000\000\080\255\056\255\076\255\255\254\
\049\255\000\000"

let yyrindex = "\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\055\255\000\000\
\061\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
\000\000\000\000\062\255\065\255\077\255\000\000\000\000\124\255\
\000\000\058\255\078\255\000\000\123\255\000\000\079\255\000\000\
\000\000\000\000"

let yygindex = "\000\000\
\000\000\000\000\005\000\001\000\239\255\249\255\000\000"

let yytablesize = 144
let yytable = "\016\000\
\046\000\047\000\048\000\049\000\050\000\042\000\032\000\033\000\
\034\000\026\000\041\000\015\000\023\000\025\000\027\000\001\000\
\003\000\062\000\004\000\005\000\006\000\007\000\030\000\031\000\
\058\000\059\000\060\000\017\000\051\000\054\000\052\000\028\000\
\061\000\053\000\055\000\056\000\010\000\018\000\019\000\020\000\
\021\000\022\000\030\000\003\000\065\000\004\000\005\000\006\000\
\007\000\064\000\003\000\034\000\004\000\005\000\006\000\007\000\
\043\000\044\000\063\000\008\000\009\000\066\000\000\000\010\000\
\029\000\029\000\029\000\003\000\004\000\004\000\010\000\029\000\
\057\000\029\000\006\000\005\000\029\000\029\000\007\000\029\000\
\029\000\029\000\029\000\029\000\031\000\031\000\031\000\032\000\
\033\000\034\000\002\000\031\000\003\000\031\000\030\000\031\000\
\031\000\031\000\000\000\031\000\031\000\031\000\031\000\031\000\
\042\000\032\000\033\000\034\000\000\000\000\000\032\000\033\000\
\034\000\000\000\029\000\000\000\000\000\030\000\031\000\035\000\
\036\000\037\000\038\000\039\000\035\000\036\000\037\000\038\000\
\039\000\020\000\017\000\000\000\000\000\000\000\000\000\000\000\
\020\000\017\000\020\000\017\000\000\000\020\000\020\000\017\000"

let yycheck = "\007\000\
\018\000\019\000\020\000\021\000\022\000\007\001\008\001\009\001\
\010\001\009\000\007\001\007\000\008\000\009\000\010\000\001\000\
\001\001\015\001\003\001\004\001\005\001\006\001\019\001\020\001\
\032\000\033\000\034\000\012\001\024\000\029\000\026\000\014\001\
\040\000\029\000\030\000\031\000\021\001\022\001\023\001\024\001\
\025\001\026\001\019\001\001\001\062\000\003\001\004\001\005\001\
\006\001\057\000\001\001\010\001\003\001\004\001\005\001\006\001\
\001\001\002\001\054\000\017\001\018\001\013\001\255\255\021\001\
\007\001\008\001\009\001\001\001\014\001\003\001\021\001\014\001\
\006\001\016\001\014\001\014\001\019\001\020\001\014\001\022\001\
\023\001\024\001\025\001\026\001\007\001\008\001\009\001\008\001\
\009\001\010\001\014\001\014\001\014\001\016\001\019\001\020\001\
\019\001\020\001\255\255\022\001\023\001\024\001\025\001\026\001\
\007\001\008\001\009\001\010\001\255\255\255\255\008\001\009\001\
\010\001\255\255\016\001\255\255\255\255\019\001\020\001\022\001\
\023\001\024\001\025\001\026\001\022\001\023\001\024\001\025\001\
\026\001\007\001\007\001\255\255\255\255\255\255\255\255\255\255\
\014\001\014\001\016\001\016\001\255\255\019\001\020\001\020\001"

let yynames_const = "\
  TRUE\000\
  FALSE\000\
  LPAR\000\
  RPAR\000\
  PLUS\000\
  MINUS\000\
  MULT\000\
  DIV\000\
  LSQBRAK\000\
  RSQBRAK\000\
  EOL\000\
  SEMICOLON\000\
  UNTIL\000\
  EVENTUALLY\000\
  NEXT\000\
  AND\000\
  OR\000\
  NOT\000\
  EQ\000\
  SG\000\
  SL\000\
  GE\000\
  LE\000\
  "

let yynames_block = "\
  INT\000\
  FLOAT\000\
  NAME\000\
  "

let yyact = [|
  (fun _ -> failwith "parser")
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 1 : 'expr) in
    Obj.repr(
# 36 "parser.mly"
           (_1)
# 201 "parser.ml"
               : Type.formula))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'stateCondition) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 40 "parser.mly"
                                      (Until(_1,_3) )
# 209 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 3 : 'stateCondition) in
    let _3 = (Parsing.peek_val __caml_parser_env 1 : 'timeinterval) in
    let _4 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 41 "parser.mly"
                                                    (BoundedUntil(_1,_3,_4))
# 218 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 42 "parser.mly"
                             (Until(True,_2) )
# 225 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'timeinterval) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 43 "parser.mly"
                                          (BoundedUntil(True,_2,_3) )
# 233 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 44 "parser.mly"
                       (Next(_2))
# 240 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'timeinterval) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 45 "parser.mly"
                                    (BoundedNext(_2,_3))
# 248 "parser.ml"
               : 'expr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'floatexpr) in
    Obj.repr(
# 50 "parser.mly"
                ((Float(0.0),_2))
# 255 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'floatexpr) in
    Obj.repr(
# 51 "parser.mly"
                ((Float(0.0),_2))
# 262 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'floatexpr) in
    Obj.repr(
# 52 "parser.mly"
                ((_2,_2))
# 269 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'floatexpr) in
    Obj.repr(
# 53 "parser.mly"
                ((_2,Infty))
# 276 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'floatexpr) in
    Obj.repr(
# 54 "parser.mly"
                ((_2,Infty))
# 283 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 3 : 'floatexpr) in
    let _4 = (Parsing.peek_val __caml_parser_env 1 : 'floatexpr) in
    Obj.repr(
# 55 "parser.mly"
                                                 ((_2,_4))
# 291 "parser.ml"
               : 'timeinterval))
; (fun __caml_parser_env ->
    Obj.repr(
# 58 "parser.mly"
          (True)
# 297 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    Obj.repr(
# 59 "parser.mly"
           (False)
# 303 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'stateCondition) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 60 "parser.mly"
                                     (And(_1,_3))
# 311 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'stateCondition) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 61 "parser.mly"
                                    (Or(_1,_3))
# 319 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 0 : 'stateCondition) in
    Obj.repr(
# 62 "parser.mly"
                      (Not(_2))
# 326 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'stateCondition) in
    Obj.repr(
# 63 "parser.mly"
                            (_2)
# 333 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'intexpr) in
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'cmp) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'intexpr) in
    Obj.repr(
# 64 "parser.mly"
                        ( IntAtom(_1,_2,_3) )
# 342 "parser.ml"
               : 'stateCondition))
; (fun __caml_parser_env ->
    Obj.repr(
# 68 "parser.mly"
     (EQ)
# 348 "parser.ml"
               : 'cmp))
; (fun __caml_parser_env ->
    Obj.repr(
# 69 "parser.mly"
      (SG)
# 354 "parser.ml"
               : 'cmp))
; (fun __caml_parser_env ->
    Obj.repr(
# 70 "parser.mly"
      (SL)
# 360 "parser.ml"
               : 'cmp))
; (fun __caml_parser_env ->
    Obj.repr(
# 71 "parser.mly"
      (GE)
# 366 "parser.ml"
               : 'cmp))
; (fun __caml_parser_env ->
    Obj.repr(
# 72 "parser.mly"
      (LE)
# 372 "parser.ml"
               : 'cmp))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : int) in
    Obj.repr(
# 76 "parser.mly"
      (Int(_1))
# 379 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : string) in
    Obj.repr(
# 77 "parser.mly"
        (IntName(_1))
# 386 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _2 = (Parsing.peek_val __caml_parser_env 1 : 'intexpr) in
    Obj.repr(
# 78 "parser.mly"
                     (_2)
# 393 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'intexpr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'intexpr) in
    Obj.repr(
# 79 "parser.mly"
                        (Plus(_1,_3))
# 401 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'intexpr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'intexpr) in
    Obj.repr(
# 80 "parser.mly"
                        (Mult(_1,_3))
# 409 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 2 : 'intexpr) in
    let _3 = (Parsing.peek_val __caml_parser_env 0 : 'intexpr) in
    Obj.repr(
# 81 "parser.mly"
                         (Minus(_1,_3))
# 417 "parser.ml"
               : 'intexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : float) in
    Obj.repr(
# 85 "parser.mly"
         (Float(_1))
# 424 "parser.ml"
               : 'floatexpr))
; (fun __caml_parser_env ->
    let _1 = (Parsing.peek_val __caml_parser_env 0 : int) in
    Obj.repr(
# 86 "parser.mly"
       (Float(float_of_int _1))
# 431 "parser.ml"
               : 'floatexpr))
(* Entry main *)
; (fun __caml_parser_env -> raise (Parsing.YYexit (Parsing.peek_val __caml_parser_env 0)))
|]
let yytables =
  { Parsing.actions=yyact;
    Parsing.transl_const=yytransl_const;
    Parsing.transl_block=yytransl_block;
    Parsing.lhs=yylhs;
    Parsing.len=yylen;
    Parsing.defred=yydefred;
    Parsing.dgoto=yydgoto;
    Parsing.sindex=yysindex;
    Parsing.rindex=yyrindex;
    Parsing.gindex=yygindex;
    Parsing.tablesize=yytablesize;
    Parsing.table=yytable;
    Parsing.check=yycheck;
    Parsing.error_function=parse_error;
    Parsing.names_const=yynames_const;
    Parsing.names_block=yynames_block }
let main (lexfun : Lexing.lexbuf -> token) (lexbuf : Lexing.lexbuf) =
   (Parsing.yyparse yytables 1 lexfun lexbuf : Type.formula)
