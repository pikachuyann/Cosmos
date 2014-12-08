#mod_use "../../prism2SPT/PetriNet.ml"
#mod_use "../../prism2SPT/Type.ml"
#use "../../prism2SPT/StochasticPetriNet.ml"
#use "../../utils/mlcall.ml"


let dcr n x = let s = string_of_int (1+((x+n-2) mod n)) in
	      s;;


let generate_net n =
  let net = Net.create () in
  Data.add ("Counter", Int 0) net.Net.place;
  for i=1 to n do
    Data.add (("T"^(string_of_int i)), Int 1) net.Net.place;
    Data.add (("W"^(string_of_int i)), Int 0) net.Net.place;
    Data.add (("E"^(string_of_int i)), Int 0) net.Net.place;
    Data.add (("F"^(string_of_int i)), Int 1) net.Net.place;
    Data.add ("TL"^(string_of_int i) ,(Exp (Float 0.34))) net.Net.transition;
    Data.add ("TR"^(string_of_int i) ,(Exp (Float 0.34))) net.Net.transition;
    Data.add ("Eat"^(string_of_int i) ,(Exp (Float 0.33))) net.Net.transition;
  done;
  for i=1 to n do
    Net.add_arc net ("T"^(string_of_int i)) ("TL"^(string_of_int i)) (Int 1);
    Net.add_arc net ("F"^(string_of_int i)) ("TL"^(string_of_int i)) (Int 1);
    Net.add_arc net ("TL"^(string_of_int i)) ("W"^(string_of_int i)) (Int 1);
    Net.add_arc net ("W"^(string_of_int i)) ("TR"^(string_of_int i)) (Int 1);
    Net.add_arc net ("F"^(dcr n i)) ("TR"^(string_of_int i)) (Int 1);
    Net.add_arc net ("TR"^(string_of_int i)) ("E"^(string_of_int i)) (Int 1);
    Net.add_arc net ("E"^(string_of_int i)) ("Eat"^(string_of_int i)) (Int 1);
    Net.add_arc net ("Eat"^(string_of_int i)) ("T"^(string_of_int i)) (Int 1);
    Net.add_arc net ("Eat"^(string_of_int i)) ("F"^(string_of_int i)) (Int 1);
    Net.add_arc net ("Eat"^(string_of_int i)) ("F"^(dcr n i)) (Int 1);
    Net.add_arc net ("Eat"^(string_of_int i)) "Counter" (Int 1);
  done;
  net;;


let generate fpath n =
  let net = generate_net n in
  print_spt (fpath^".grml") net;
  print_spt_marcie (fpath^".andl") net;
  print_spt_dot (fpath^".dot") net [] [];;

generate "philo100" 100;;


let loop x = 1+((x+3) mod 5);;

loop 5;;
