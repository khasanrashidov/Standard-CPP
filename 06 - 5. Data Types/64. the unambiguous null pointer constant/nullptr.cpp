// the unambiguous null pointer constant
#include <cstdio>
using namespace std;

// In C++ the NULL constant has always been too ambiguous.

#ifndef NULL
#define NULL (0LL) /* common C++ definition */
#endif

void f(int i) // takes integer
{
    printf("the int is %d\n", i);
}

void f(const char *s) // takes constant character pointer
{
    printf("the pointer is %p\n", s);
}

int main(int argc, char **argv)
{
    // If we call this with NULL, then it prints out "the int is 0".
    f(NULL); // This NULL is defined differently on PCs with Windows OS. (On Mac OS (xcode) it may not work.)

    // Since the very beginning of the C language,
    // the constant value 0 has served double duty as a null pointer constant.
    // Ambiguity was dealt with by defining a pre-processor macro called NULL,
    // which was typically defined as a zero value pointer to void,
    // and that would look something like this,  "(void*)0".
    // C++ did not adopt this behavior, and it doesn't support the loose typecasting
    // of the void pointer like C does.
    // This would be too ambiguous in C++ with its extensible type system.
    // So the C++ standard does not specify the exact value of the NULL macro.
    // It's different on different systems.
    // On Mac OS, "0LL" that's actually how it's defined in the headers Mac OS,
    // so it's a long long zero value.
    // On some systems it's just a 0, and like we said, on some systems
    // if it's just a "0", this wouldn't even create an error.
    // So this leaves C++ without a generic NULL pointer and
    // beginning with C++11 there is now a keyword for this.
    // So "(void*)0" doesn't work like that, "0" does.
    // On the other hand if we just say "nullptr" now that's treated as any kind of a pointer,
    // and so it'll actually call the version here that says, "the pointer is",
    // we'll see it says, "the pointer is 00000000".
    f(nullptr);

    // And if we call this with a number zero, then it'll come back and say,
    // "the int is 0".
    f(0);

    // If we call with "0LL", it will not work at all because the call
    // is now ambiguous because there's no long long version of it.
    // So C++ defines this keyword, "nullptr",
    // and we'll no longer use the NULL constant, the NULL pre-processor macro
    // as we used to do in C, and even in early versions of C++.

    // The nullptr constant provides a much needed value to be used
    // where the traditional NULL void pointer value has been used in C++ but doesn't work in C++.
    // It resolves the ambiguity problem, and it can be used in any context of any pointer type.

    return 0;
}
