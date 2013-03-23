export CC=gcc
export CXX=g++
export OPTIONS= -O3 -Wall -arch i386 -arch x86_64
export BOOSTPATH=/data/usr64/include
export BISON=/opt/local/bin/bison
export FLEX=/opt/local/bin/flex

export AR=libtool
export ARFLAGS=-static -o

files=find SOURCES -type f | grep "\(.cpp\|.hpp\|.c\|.h\|Makefile\)$$"

include Makefile_common

.PHONY: doc

doc:
	doxygen Doxyfile

install:
	cp bin/_Cosmos /usr/share/zsh/4.3.11/functions/_Cosmos 
