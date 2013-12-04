
let joblist = [
  ("N3P2_L2L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=2,L2=11' --prism");
  ("N3P2_L2L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=2,L2=11' -r");
  ("N3P2_L3L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=3,L2=11' --prism");
  ("N3P2_L3L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=3,L2=11' -r");
  ("N3P2_L4L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=4,L2=11' --prism");
  ("N3P2_L4L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=4,L2=11' -r");
  ("N3P2_L5L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=5,L2=11' --prism");
  ("N3P2_L5L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=5,L2=11' -r");
  ("N3P2_L6L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=6,L2=11' --prism");
  ("N3P2_L6L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=6,L2=11' -r");
  ("N3P2_L7L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=7,L2=11' --prism");
  ("N3P2_L7L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=7,L2=11' -r");
  ("N3P2_L8L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=8,L2=11' --prism");
  ("N3P2_L8L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=8,L2=11' -r");
  ("N3P2_L9L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=9,L2=11' --prism");
  ("N3P2_L9L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=9,L2=11' -r");
  ("N3P2_L10L11", "MAPK_P2Reduit.grml" "RareEventUntil.lha" "--const 'L=10,L2=11' --prism");
  ("N3P2_L10L11", "MAPK.grml" "RareEventUntil2.lha" "--const 'L=10,L2=11' -r");
]


let add_option (x,y,z) =
  execSavedCosmos ~prefix:false (x,y,z,"--width 0.01 --njob 16")


let _ =
  List.iter (execSavedCosmos ~prefix:true) 
