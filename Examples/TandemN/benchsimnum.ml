#use "tandem.ml";;

level:= 0.99;;

for i = 0 to 10 do
  for j= 0 to 10 do 
    generate (1+i) 5 5 (0.9 -. 0.05*.(float j)) (fun _ -> 0.35); 
      Sys.command "/usr/bin/time /Applications/prism-4.0.2-osx64/bin/prism -v tandem.sm prismtandem.csl > prismout";
  done
done;;
  
(*grep -o "States:[ ]*[0-9]*\|Result:[ ]*[0-9.E-]*\|Time for model checking:[ ]*[0-9.]*" prismout*)

(*grep -o "States:[ ]*[0-9]*\|Result:[ ]*[0-9.E-]*\|Time for model checking:[ ]*[0-9.]*" prismout  |  tr '\n' ' ' | sed -e 's/States//g' -e 's/Time for model checking://g' -e 's/Result://g' | tr ':' '\n'*)

