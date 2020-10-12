AC_PREREQ([2.69])
AC_INIT([jlibc], [1.0], [jflopezfernandez@gmail.com])
AC_CONFIG_SRCDIR([src/memory.c])
AC_CONFIG_HEADERS([include/config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX            Probably not needed

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 tests/Makefile])

AC_OUTPUT
