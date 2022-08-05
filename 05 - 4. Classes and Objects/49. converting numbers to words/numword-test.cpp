// converting numbers to words
#include <cstdio>
#include <cstdint>
#include "numword.h"
using namespace std;

int main(int argc, char **argv)
{
    my::numword nw;
    uint64_t n;

    n = 3;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 5;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 20;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 49;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 1492;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 18352;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 100000;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 100000001;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 123000000000;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 123456789012;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 3543523434523;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 999000000000000;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 999999999999999999;
    printf("n is %lld, %s\n", n, nw.words(n));
    n = 1000000000000000000;
    printf("n is %lld, %s\n", n, nw.words(n));

    for (int i = 0; i < 201; ++i)
    {
        printf("%d is %s\n", i, nw.words(i));
    }
    return 0;
}

// Numwords is a class that converts numbers into words.

// The numword.h file has the class definition, which serves as an interface.
// The numword.cpp file has the code that implements that interface.

// We create a object of the numword class.
// We declare an integer value using uint64 type,
// which is contained in the C standard int header file.
// uint64 is a type that is an unsigned integer 64 bits in length, and it is portable.
// When we use this type, we know that it is an unsigned 64-integer on any system
// that supports that type. This is important because if we are dealing with large numbers.

// In practice, it is usually a really good idea to have our class definition in one file,
// typically with a .h extension, and our implementation in a .cpp file with all of the code.
// That is considered best practice. It really has some real advantages.

// So, that is really it.
// That's the code.
// That's the great solution.
// This is actually a useful real-world application.
// A class like this is typically used in banking applications,
// for writing checks and other documents where monetary values are
// typically expressed in words.