export CC=gcc
export CXX=clang++
export OPTIONS= -O3 -Wall -arch i386 -arch x86_64
export BOOSTPATH=/data/usr64/include
export BISON=/opt/local/bin/bison
export FLEX=/opt/local/bin/flex

export AR=libtool
export ARFLAGS=-static -o

files=find SOURCES -type f | grep "\(.cpp\|.hpp\|.c\|.h\|Makefile\)$$"

include Makefile_common

.PHONY: doc cov

cov:
	lcov --directory Obj/ -b SOURCES/ --capture --output-file Cosmos.info
	lcov --directory ./ --remove Cosmos.info '/usr/local/include/*' '/usr/include/*' \
	--output-file Cosmosclean.info
	genhtml Cosmosclean.info --output-directory cov.html --ignore-errors source

doc:
	doxygen Doxyfile

install:
	cp bin/_Cosmos /usr/share/zsh/4.3.11/functions/_Cosmos 
