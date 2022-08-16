// overview of the c++ standard library
#include <cstdio>
using namespace std;

// The C++ standard library is used to support a large number of common system level tasks.
// This set of library functions is mostly inherited from the C standard library
// and is generally compatible with standard C code.
// The standard library includes a great number of functions and macros
// supporting a broad scope of functionalities including:
// 1) File I/O facilities for creating, reading and writing files.
// 2) Strings support for C strings null-terminated arrays of characters.
// 3) Error handling functions for standardized handling of system level errors.
// 3) Date and time functions provide support for time and date structures.
// And other utilies including math, localization, signals, and other system services.
//////////////////////////////////////////////////
// -- File I/O -- //
///// fopen(filename, mode)
///// fread(str, count, stream)
///// fwrite(str, stream)
///// fgets(buffer, size, count, stream)
///// fputs(buffer, size, count, stream)
// -- Strings -- //
///// strncpy(dest, src, count)
///// strncat(dest, src, count)
///// strncmp(lhs, rhs)
///// strnlen(str, count)
///// strchr(str, ch)
///// strstr(dest, src)
// -- Error Handling -- //
///// errno
///// perror(s)
///// strerror(errnum)
// -- Date and Time -- //
///// time(time)
///// gmtime(time)
///// localtime(time)
// -- Other Utilites -- //
///// Math
///// Localization
///// Process control
///// System services
//////////////////////////////////////////////////
// The headers for the C++ standard library
// are the same as those for the C standard library with a simple difference.
// For C++, the headers have no .h at the end of the filename
// and have a lower case c at the beginning.
// This effectively distinguishes the C++ library headers from the C versions
// which are likely also included with our development system.
//////////////////////////////////////////////////
// -- Header Files (C) -- //
///// #include <stdio.h>
///// #include <stdlib.h>
///// #include <string.h>
///// #include <errno.h>
// -- Header files (C++) -- //
///// #include <cstdio>
///// #include <cstdlib>
///// #include <cstring>
///// #include <cerrno>
//////////////////////////////////////////////////
// This C++ library functions are in the standard namespace.
// -- Namespace -- //
// using namespace std;
// std::puts("Hello, World!");
//////////////////////////////////////////////////
// For compatibility with C code, many systems may not enforce this rule
// but we cannot count on that. It's always a good idea to use the standard namespace
// when using this functions in C++. These functions are all very well documented,
// we can find documentation for these functions in the standard main pages
// if we're on a Mac or UNIX system or in the library documentation
// that comes with our developer environment.
// Or by simply typing the name of a function into any major internet search engine.
// It's important to note here that these are standard I/O functions.
// The C++ standard requires that these are supported.
// Some systems including Microsoft Visual Studio
// have their own versions of these functions and in particular
// Microsoft's compiler will even go so far as to throw an error message
// if we use the standard functions instead of their own versions.
// But, anyway, standard C++ is about standard versions of these functions.

// The C++ standard library is very large, much more than can be covered in this course.
// For our purposes, we will cover those functions that are most commonly used for
// general purpose programming. There are many good references available
// that cover most or all of the library. The standard library is inherited from
// the standard library for the C programming language as C++ includes the full
// definition of C, the standard library is also fully included in the C++ standard.
// Even though C++ has additional object-oriented libraries for its own use, they
// do not duplicate the functionality of the standard C library so we will
// need to use these functions in our C++ code for many common purposes.

int main(int argc, char **argv)
{

    puts("C++ Standard Library");

    return 0;
}