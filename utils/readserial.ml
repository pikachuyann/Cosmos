
let open_connection s b =
  let serial = Unix.openfile s [Unix.O_RDWR;Unix.O_NOCTTY; Unix.O_NONBLOCK] 0o666 in
  let term = Unix.tcgetattr serial in 
  Unix.tcflush serial Unix.TCIOFLUSH;
  Unix.tcsetattr
    serial
    Unix.TCSANOW
    {term with 
      Unix.c_ibaud = b ;
      Unix.c_obaud = b ;

      Unix.c_icanon = false;
      Unix.c_echo = false;
      Unix.c_echoe = false;
      Unix.c_echok = false;
      Unix.c_echonl = false;
      Unix.c_isig = false;
      
      Unix.c_inlcr = false;
      Unix.c_igncr = false;
      Unix.c_icrnl = false;
      Unix.c_ignbrk = false;
      Unix.c_parmrk = false;

      Unix.c_ixon = false;
      Unix.c_ixoff = false;

      Unix.c_cread =true;
      Unix.c_clocal=true;

      Unix.c_csize = 8;
      Unix.c_parenb = false ;
      Unix.c_parodd = false ;
      Unix.c_inpck = false;
      Unix.c_istrip = false;

      Unix.c_cstopb = 1;
      Unix.c_opost = false ;
      Unix.c_vmin = 1;
      Unix.c_vtime =0;
      
      
    (*  Unix.c_hupcl = false;*)
      
      };
  serial

let mapping_fun = function
|'0' ->  0
|'1' ->  1
|'2' ->  2
|'3' ->  3
|'4' ->  4
|'5' ->  5
|'6' ->  6
|'7' ->  7
|'8' ->  8
|'9' ->  9
|'A' ->  10
|'B' ->  11
|'C' ->  12
|'D' ->  13
|'E' ->  14
|'F' ->  15
|'\n' -> 0
| x -> print_char x; failwith "not hex"

let map_hex s n =
let s2= Bytes.create n in
for i =0 to (n-1)/2 do
s2.[i] <- char_of_int ((mapping_fun s.[2*i])*16 + (mapping_fun s.[2*i+1]))
done;
s2


let _ =
  assert (Array.length Sys.argv > 1);
  let b = (if Array.length Sys.argv>2 then int_of_string Sys.argv.(2) else 115200) in
  print_endline ("Opening:"^Sys.argv.(1)^" at rate:"^(string_of_int b));
  let serial = open_connection Sys.argv.(1) b in
  let closeimm = Array.length Sys.argv <=3 in
  let s = Bytes.create (101) in
  while closeimm do
    let rf,_,_ = (Unix.select [serial;Unix.stdin] [] [] (-1.0)) in
    match rf with
      x::_ when x=serial ->
	let nread =  Unix.read serial s 0 100 in
	if nread = 0 then raise End_of_file;
	print_string (String.sub s 0 nread);
	flush stdout;
    | x::_ when x=Unix.stdin ->
      let nread =  Unix.read Unix.stdin s 0 100 in
      if nread = 0 then raise End_of_file;
      let s2 =  map_hex s nread in
      ignore @@ Unix.write serial  s2 0 (nread/2);
  done
