// string functions
#include <cstdio>
using namespace std;

// The standard C++ library provides
// a number of functions for working with C strings.
// These are different and distinct from the C++ STL string class.
// C strings are simple, efficient, and flexible
// and are often used where the complexity and power
// of an object-oriented string class is not necessary.
// A C string is simply an array of characters terminated with a null value.

int main(int argc, char **argv)
{
    // declaring an array of characters which is terminated with a zero value
    const char s[] = {'S', 't', 'r', 'i', 'n', 'g', 0}; // array of characters
    // And now we can use puts(), and can simply print that value.
    puts(s);
    // And so, this array of characters, it has six character values,
    // followed by a null value, or a zero, and that is exactly the same as
    // if we were to do the following.
    const char s2[] = "String"; // This, within the quotes, is a C string
    puts(s2);                   // We get exactly the same result.
    // And this string is exactly the same as if we were to list out
    // the separate characters, S-T-R-I-N-G and a zero value.
    // C string is an array of characters terminated with a null value.
    // And in the initialization of C string, the equals sign,
    // is actually a copy constructor, and so it's copying
    // the literal array of characters into the array of characters variable.

    // Now, if instead we do this, we have something subtly different.
    const char *s3 = "String";
    // What we have here is a character string pointer,
    // which is being assigned to the address
    // of the literal array of characters.
    // And so, when we build and run this program,
    // we get the same result, but we're not actually copying
    // an entire array in this case.
    puts(s3); // We get exactly the same result.
    // We're simply creating a pointer.
    // Now, it's important to note in this case
    // if we take out the "const" here,
    // so we're going to build and run here,
    // and we can see that we get a warning.
    char *s4 = "String";
    puts(s4);
    // Many compilers will warn us or
    // even refuse to convert from the string literal
    // to a character pointer without the "const".

    // So, now that it's a const character pointer,
    // because in this context it means that what's
    // being pointed at is a constant.

    // Okay, so this is how C strings work.

    return 0;
}