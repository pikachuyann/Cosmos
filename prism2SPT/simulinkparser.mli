type block = {
  blocktype : string;
  blockid : string;
  name : string;
  values : (string * string) list;
}
type blockDefault = string * (string * string) list
type blockPort = int * int
type simulinkLink = {
  fromblock : int;
  fromport : int;
  toblock : int;
  toport : int;
}
type simulinkModel = block list * blockDefault list * simulinkLink list
type simulinkPModel = block list * simulinkLink list
val printValues : out_channel -> (string * string) list -> unit
val printBlock : out_channel -> block -> unit
val printBlocklist : out_channel -> block list -> unit
val printParDef : out_channel -> string * (string * string) list -> unit
val printBlockParDeflist :
  out_channel -> (string * (string * string) list) list -> unit
val printLink : out_channel -> simulinkLink -> unit
val printLinks : out_channel -> simulinkLink list -> unit
val verbose : int
val printModel : out_channel -> simulinkModel -> unit
val printPModel : out_channel -> simulinkPModel -> unit
val ssid_count : int ref
val getSSID : (string * string) list -> int
val fresh_ssid : unit -> int
val print_position : out_channel -> Lexing.lexbuf -> unit
val blocklist_of_simulink : simulinkModel -> Xml.xml -> simulinkModel
val blocklist_of_tree : simulinkModel -> Xml.xml -> simulinkModel
val pushDefaults : simulinkModel -> block list * simulinkLink list
val printLaTeX : out_channel -> simulinkPModel -> unit
