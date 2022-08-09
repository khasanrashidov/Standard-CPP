// characters and strings
#include <cstdio>
using namespace std;

// In C++, the fundamental string type is an array of characters terminated with a null value.
// This is sometimes referred to as a "C string", or a "null-terminated string", to distinguish it
// from object-oriented string types.

int main(int argc, char **argv)
{
    // The character type is technically an integer type
    // of a size suitable for holding a character,
    // which is 8 bits on most common systems.
    // A string is an array of these characters terminated with a zero value.

    // So, this six-character string here that says "String", is a string that
    // actually takes up seven values in the array, inlcuding the null terminator.
    char cstring[] = "String";

    puts(cstring);

    for (unsigned int i = 0; cstring[i]; i++)
    {
        printf("%02d: %c\n", i, cstring[i]); // %02d
    }

    // The size of cstring above is 7 because it also includes the null terminator.
    printf("size of array is %ld\n", sizeof(cstring));

    puts("");

    char cstring1[] = "String"; // Here within the quotes is a literal string,
    // and what that returns is constant, an array of constant characters terminated by a zero.
    // If we want to concatenate multiple literal strings, we can do so like this.
    char cstring2[] = "String"
                      "String"
                      "String";

    // So these literal strings are concatenated into one literal string,
    // and that one literal string is terminated with one null.
    puts(cstring2);

    for (unsigned int i = 0; cstring2[i]; i++)
    {
        printf("%02d: %c\n", i, cstring2[i]); // %02d
    }

    // The size of cstring above is 19 because it also includes the null terminator.
    printf("size of array is %ld\n", sizeof(cstring2));
    // And so, 18 characters makes an array of size 19 with the null terminator.

    // So, C strings are very simple form of strings,
    // much simpler than the string class
    // provided by the C++ STL.

    // For circumstances where we don't need the power of object-oriented strings,
    // C strings are small, simple and fast, and they're very commonly used in C++.

    puts("");

    return 0;
}