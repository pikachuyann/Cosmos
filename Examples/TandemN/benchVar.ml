#use "tandem.ml";;

for i =0 to 20 do
  let lambda = 0.1 +.  0.02*.(float i) in
  execSavedCosmos ~prefix:false ((Printf.sprintf "Variancevar-%f" lambda),"tandemVar.grml","tandemHisto.lha",Printf.sprintf " --width 0 --output-PDFCDF pdf_%f.dat  --const \"lambda=%f,rho2=%f\" --max-run 1000000000 --njob 12" lambda lambda (0.55-.lambda));
done;;
