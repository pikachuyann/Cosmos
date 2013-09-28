
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

include Makefile_common

.PHONY: doc cov

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
