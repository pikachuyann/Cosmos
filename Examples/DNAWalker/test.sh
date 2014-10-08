Cosmos track18Block1.grml --sampling 5000 10.0 --trace-place "a1,a2,a3,a4,a9,a10,a11,a12,a8" --output-PDFCDF test.dat --njob 8 --max-run 100000

Cosmos track28.grml --formula "(a20=0 & a25=0 & a28=0)  U<12000 a17>0" --njob 8 --level 0.95 --gppcmd clang++ --max-run 100000000
