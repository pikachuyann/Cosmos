#use "tandem.ml";;

for i =1 to 70 do
  let lambda =  0.01*.(float i) in
  execSavedCosmos ~prefix:false ((Printf.sprintf "Variancevar-%f" lambda),"tandemVar.grml","tandemVar.lha",Printf.sprintf " --width 0 --const \"lambda=%f,rho2=%f\" --max-run 10000000" lambda (0.55-.lambda));
done;;
