
#OSTYPE = linux
#OSTYPE = cygwin
#OSTYPE = darwin

ifdef OSTYPE
	# Look for common variants, e.g. gnu-linux -> linux
	ifneq (,$(findstring linux, $(OSTYPE)))
	  OSTYPE = linux
	endif
	ifneq (,$(findstring cygwin, $(OSTYPE)))
	  OSTYPE = cygwin
	endif
	# For Cygwin , OSTYPE is sometimes set to "posix"
	ifneq (,$(findstring posix, $(OSTYPE)))
	  OSTYPE = cygwin
	endif
	ifneq (,$(findstring darwin, $(OSTYPE)))
	  OSTYPE = darwin
	endif
else
	# If OSTYPE is not defined/available, try uname
	ifneq (,$(findstring Linux, $(shell uname -s)))
		OSTYPE = linux
	endif
	ifneq (,$(findstring CYGWIN, $(shell uname -s)))
		OSTYPE = cygwin
	endif
	ifneq (,$(findstring Darwin, $(shell uname -s)))
		OSTYPE = darwin
	endif
endif

ifeq ($(OSTYPE),darwin)

export CC=gcc
export CXX=g++
export OPTIONS= -O3 -Wall -arch i386 -arch x86_64
export BOOSTPATH=/data/usr64/include
export BISON=/opt/local/bin/bison
export FLEX=/opt/local/bin/flex

export AR=libtool
export ARFLAGS=-static -o

else
ifeq ($(OSTYPE),linux)

export CC=gcc
export CXX=g++
export OPTIONS= -O3 -Wall -Wextra $(COV)
export BOOSTPATH=/data/usr64/include

export AR=ar
export ARFLAGS=rcs

endif
endif


files=find SOURCES -type f | grep "\(.cpp\|.hpp\|.c\|.h\|Makefile\)$$"


.PHONY: lib generator clean sim dir automataGen doc cov utils

all: dir lib generator automataGen utils

dir:
	mkdir -p bin
	mkdir -p includes
	mkdir -p Obj/Cosmos
	mkdir -p Obj/ModelGenerator/Eval
	mkdir -p Obj/ModelGenerator/GspnParser
	mkdir -p Obj/ModelGenerator/LhaParser

lib: includes/spn.hpp includes/LHA.hpp includes/marking.hpp
	@(cd SOURCES/Cosmos && $(MAKE) ../../bin/libClientSim.a)

includes/%.hpp: SOURCES/Cosmos/%.hpp
	cp SOURCES/Cosmos/$*.hpp $@

generator:
	@(cd SOURCES/ModelGenerator && $(MAKE) ../../bin/Cosmos)

cleanSim:
	@(cd SOURCES/Cosmos && $(MAKE) clean)

cleanGen:
	@(cd SOURCES/ModelGenerator && $(MAKE) clean)

clean:
	@(cd SOURCES/Cosmos && $(MAKE) $@)
	@(cd SOURCES/ModelGenerator && $(MAKE) $@)
	@(cd automataGen && ocamlbuild -clean)
	@(rm -rf package-alligator.zip)

cleansim:
	@(cd SOURCES/Cosmos && $(MAKE) clean)


parser:
	@(cd SOURCES/ModelGenerator && $(MAKE) parser)

cleanparser:
	@(cd SOURCES/ModelGenerator && $(MAKE) cleanparser)

utils:
	@(cd utils && ocamlbuild -lib str linecombinator.native)
	cp utils/linecombinator.native bin/linecombinator

automataGen:
	@(cd automataGen && ocamlbuild generator.native)
	cp automataGen/generator.native bin/automataGen

package: all
	mkdir package
	cp Readme.txt package/
	cp COPYING package/
	cp -r includes package/includes
	cp -r bin package/bin

cov:
	lcov --directory Obj/ -b SOURCES/ --capture --output-file Cosmos.info
	lcov --directory ./ --remove Cosmos.info '/usr/local/include/*' '/usr/include/*' \
	'*modelwriter.*' '*.yy' '*.ll' '*.tab.*' '*lex.*.c' '*stack.hh' \
	'*position.hh' '*location.hh' --output-file Cosmosclean.info
	genhtml Cosmosclean.info --output-directory cov.html --ignore-errors source

doc:
	doxygen Doxyfile

install:
	cp bin/_Cosmos /usr/share/zsh/4.3.11/functions/_Cosmos 
