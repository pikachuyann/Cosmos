#use "tandem.ml";;

level:= 0.99;;

for i = 0 to 10 do
  for j= 0 to 10 do 
    generate (1+i) 13 13 (0.4 -. 0.015*.(float j) -. 0.01*.(float j)) (fun _ -> 0.75); 
      Sys.command "prism tandem.sm prismtandem.csl >> prismout";
  done
done;;
  
