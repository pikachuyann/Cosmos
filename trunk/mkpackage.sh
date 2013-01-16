#!/bin/sh
mkdir package
cp Makefile package/
cp cosmosTool package/
cp Readme.txt package/
cp COPYING package/
cp -r SOURCES package/SOURCES
cp -r prism package/prism
find package/SOURCES -name "*.yy" -delete
find package/SOURCES -name "*.ll" -delete
mkdir -p package/Obj/ModelGenerator/Eval
mkdir -p package/Obj/ModelGenerator/GspnParser
mkdir -p package/Obj/ModelGenerator/LhaParser
mkdir package/bin
cp bin/gnuplotScript.gnu package/bin
cd package
cd prism; make
rm -rf classes
rm -rf cudd
rm -rf doc
rm -rf dtds
rm -rf etc
rm -rf examples
rm -rf images
rm -rf include
rm -rf obj
rm -rf src
cd ..
make