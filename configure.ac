#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# $Id$
# $URL $

AC_PREREQ(2.61)
AC_INIT([ticcutils],[0.7],[timbl@uvt.nl])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([.])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

if test x"${CXXFLAGS+set}" = xset; then
  # the user set CXXFLAGS; don't override it.
  cxx_flags_were_set=true
else
  cxx_flags_were_set=false
fi
if $cxx_flags_were_set; then
  CXXFLAGS=$CXXFLAGS
fi

# Checks for programs.
AC_PROG_CXX([g++ c++] )
AC_PROG_LIBTOOL
LT_INIT


# when running tests, use CXX
AC_LANG([C++])

#checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([sys/time.h])

AC_CHECK_HEADERS([bzlib.h],
		[LIBS="$LIBS -lbz2"],
		[AC_MSG_NOTICE([libbz2-dev not found. bz2 support disabled])] )

AC_CHECK_HEADERS([libtar.h],
		[LIBS="$LIBS -ltar"],
		[AC_MSG_NOTICE([libtar-dev not found. tar support disabled.])] )

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T
AC_TYPE_PID_T

# Checks for library functions.
AC_CHECK_FUNCS([localtime_r, gettimeofday,memset,strerror])
AC_FUNC_MALLOC

ACX_PTHREAD([],[AC_MSG_ERROR([We need pthread support!])])

if test x"$acx_pthread_ok" = xyes; then
   LIBS="$PTHREAD_LIBS $LIBS" \
   CXXFLAGS="$CXXFLAGS $PTHREAD_CFLAGS"
fi

AX_BOOST_BASE([1.40])
AX_BOOST_REGEX
LIBS="$LIBS $BOOST_REGEX_LIB"

# ugly hack when PKG_CONFIG_PATH isn't defined.
# couldn't get it to work otherwise
if test "x$PKG_CONFIG_PATH" = x; then
    export PKG_CONFIG_PATH=""
fi

PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([XML2], [libxml-2.0 >= 2.6.16] )
CXXFLAGS="$CXXFLAGS $XML2_CFLAGS"
LIBS="$LIBS $XML2_LIBS"

OPENMP_CHECK( [CXXFLAGS="$CXXFLAGS $OPENMP_CXXFLAGS"
	       AC_DEFINE(HAVE_OPENMP, 1 , Define to 1 if you have OpenMP )],
	      [AC_MSG_NOTICE(We don't have OpenMP. Multithreaded testing is disabled)] )

AC_SUBST([OPENMPFLAGS],[$OPENMP_CXXFLAGS])

AC_CONFIG_FILES([
  Makefile
  ticcutils.pc
  m4/Makefile
  src/Makefile
  docs/Makefile
  include/Makefile
  include/ticcutils/Makefile
  tests/Makefile
  tests/sub1/Makefile
])
AC_OUTPUT
