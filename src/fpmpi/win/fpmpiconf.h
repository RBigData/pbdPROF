/* fpmpiconf.h.  Generated from fpmpiconf.h.in by configure.  */
/* fpmpiconf.h.in.  Generated from configure.in by autoheader.  */

/* Define as the value of false in Fortran */
/* #undef F77_FALSE_VALUE */

/* Fortran names are lowercase with no trailing underscore */
/* #undef F77_NAME_LOWER */

/* Fortran names are lowercase with two trailing underscores */
/* #undef F77_NAME_LOWER_2USCORE */

/* Fortran names are lowercase with two trailing underscores in stdcall */
/* #undef F77_NAME_LOWER_2USCORE_STDCALL */

/* Fortran names are lowercase with no trailing underscore in stdcall */
/* #undef F77_NAME_LOWER_STDCALL */

/* Fortran names are lowercase with one trailing underscore */
/* #undef F77_NAME_LOWER_USCORE */

/* Fortran names are lowercase with one trailing underscore in stdcall */
/* #undef F77_NAME_LOWER_USCORE_STDCALL */

/* Fortran names preserve the original case */
/* #undef F77_NAME_MIXED */

/* Fortran names preserve the original case in stdcall */
/* #undef F77_NAME_MIXED_STDCALL */

/* Fortran names preserve the original case with one trailing underscore */
/* #undef F77_NAME_MIXED_USCORE */

/* Fortran names preserve the original case with one trailing underscore in
   stdcall */
/* #undef F77_NAME_MIXED_USCORE_STDCALL */

/* Fortran names are uppercase */
/* #undef F77_NAME_UPPER */

/* Fortran names are uppercase in stdcall */
/* #undef F77_NAME_UPPER_STDCALL */

/* Define as the value of true in Fortran */
/* #undef F77_TRUE_VALUE */

/* Define if we know the value of true in Fortran */
/* #undef F77_TRUE_VALUE_SET */

/* Provide the version for FPMPI2 */
#define FPMPI2_VERSION "2.4"

/* Define for full tracing of communication */
/* #undef FULL_OUTPUT */

/* Define if getrusage has useful maxrss */
#define GETRUSAGE_HAS_MAXRSS 1

/* Define if minflt field for getrusage is available */
/* #undef GETRUSAGE_HAS_MINFLT */

/* Define for getrusage() availability */
#define HAVE_GETRUSAGE 1

/* Define if int32_t is available */
#define HAVE_INT32_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `mpi' library (-lmpi). */
/* #undef HAVE_LIBMPI */

/* Define to 1 if you have the `papi' library (-lpapi). */
/* #undef HAVE_LIBPAPI */

/* Define to 1 if you have the `papi.rts' library (-lpapi.rts). */
/* #undef HAVE_LIBPAPI_RTS */

/* Define to 1 if you have the `pcl' library (-lpcl). */
/* #undef HAVE_LIBPCL */

/* Define to 1 if you have the `perfex' library (-lperfex). */
/* #undef HAVE_LIBPERFEX */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if MPI has F2C */
#define HAVE_MPI_F2C 1

/* Define if MPI defines MPI_Fint */
#define HAVE_MPI_FINT 1

/* Define if MPI_F_STATUS_IGNORE is defined */
#define HAVE_MPI_F_STATUS_IGNORE 1

/* Define if MPI_ROOT is defined */
#define HAVE_MPI_ROOT 1

/* Define to 1 if you have the <papi.h> header file. */
/* #undef HAVE_PAPI_H */

/* Process information stored in /proc/%d/stat\n */
/* #undef HAVE_PROCSTAT */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/resource.h> header file. */
#define HAVE_SYS_RESOURCE_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `usleep' function. */
/* #undef HAVE_USLEEP */

/* maximum number of processes, divided by 32 (for use with int32 bit vectors)
   */
#define MAX_PROCBY32 16

/* maximum number of processes */
#define MAX_PROCS 512

/* Define if a Fortran version of MPI_Init is required */
/* #undef NEEDS_FORTRAN_MPI_INIT */

/* Define if we need to declare strdup */
#define NEEDS_STRDUP_DEF 1

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "fpmpi@mcs.anl.gov"

/* Define to the full name of this package. */
#define PACKAGE_NAME "fpmpi2"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "fpmpi2 2.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "fpmpi2"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "2.4"

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* Define the size of MPI_Status */
#define SIZEOF_MPI_STATUS 24

/* Define the size of MPI_Status in ints */
#define SIZEOF_MPI_STATUS_IN_INTS 6

/* The size of `unsigned int', as computed by sizeof. */
/* #undef SIZEOF_UNSIGNED_INT */

/* Define calling convention */
/* #undef STDCALL */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define if performing coverage tests */
/* #undef USE_COVERAGE */

/* Define if PAPI should be used in the resource code */
/* #undef USE_PAPI */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
