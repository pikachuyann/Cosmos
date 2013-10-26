#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([Cosmos], [1.3] , [barbot@lsv.ens-cachan.fr], [Cosmos], [http://www.lsv.ens-cachan.fr/Software/cosmos/])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_SRCDIR([src/Simulator/BatchR.cpp])
AC_CONFIG_HEADER([config.h])
AC_CONFIG_MACRO_DIR([m4])

# CXXFLAGS=-Wall -Wextra -O3
: ${CXXFLAGS=-O3}

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_YACC
AC_PROG_LEX
AM_PROG_AR
AC_PROG_LIBTOOL


AX_CXX_COMPILE_STDCXX_11


# Checks for libraries.
AC_CHECK_LIB([expat], [ XML_ParseBuffer])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([float.h inttypes.h libintl.h limits.h stdlib.h string.h sys/ioctl.h sys/time.h unistd.h])

BOOST_REQUIRE([1.48.1])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_CHECK_FUNCS([dup2 floor gettimeofday memset mkdir pow select sqrt])

AC_CONFIG_FILES([Makefile src/libgrml/Makefile src/ModelGenerator/Makefile src/Simulator/Makefile test/Makefile])
AC_OUTPUT
