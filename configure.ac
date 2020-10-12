AC_PREREQ([2.69])
AC_INIT([jlibc], [1.0], [jflopezfernandez@gmail.com])

# If possible, enable extensions to C or Posix on hosts that
# normally disable the extensions, typically due to
# standards- compliance namespace issues.
#
#AC_USE_SYSTEM_EXTENSIONS

AC_CONFIG_SRCDIR([src/memory.c])
AC_CONFIG_HEADERS([include/config.h])

# Define the header guards for the configuration file for
# Automake to include when it generates the file.
#
AH_TOP([#ifndef PROJECT_INCLUDES_CONFIG_H
#define PROJECT_INCLUDES_CONFIG_H])
AH_BOTTOM([#endif /** PROJECT_INCLUDES_CONFIG_H */
])

# Checks for programs.
AC_PROG_CPP
AC_PROG_CPP_WERROR
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_MKDIR_P
AC_PROG_LN_S

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdint.h stdlib.h string.h])
AC_HEADER_STDBOOL
AC_HEADER_ASSERT


# Checks for typedefs and structures.
AC_TYPE_SIZE_T

# Checks for compiler characteristics.
AC_C_CHAR_UNSIGNED
AC_C_CONST
AC_C_INLINE
AC_C_RESTRICT

# Checks for library functions.
AC_PROG_CC_STDC
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STAT
AC_FUNC_STRERROR_R

AC_CONFIG_FILES([Makefile
                 tests/Makefile])

AC_OUTPUT
