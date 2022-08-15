// template functions
#include <cstdio>
#include <string>
using namespace std;

// C++ supports both template functions and template classes.

// This is a template function.
// It has the "template" keyword at the beginning,
// and then in angle brackets it has the word "typename"
// and the capital "T".
// This is called the template argument list,
// and in this case it has just one item.
// The "T" is a placeholder for the type.
// Then we have the standard function signature,
// and it returns whatever this type is from the template.
// It takes two parameters, also of that type.

template <typename T>
T maxof(T a, T b)
{
    return (a > b ? a : b);
}

int main(int argc, char **argv)
{
    // When we call the function we specify
    // the template argument list in angel brackets,
    // and this time it has an actual type.
    // So this type is passed to the template.
    // It is replaced in all the places where we have a capital "T".
    // What happens is the compiler generates a specialization
    // of the function for the type int.
    // A few details here.
    // First of all we notice the keyword "typename"
    // in the template argument list in the template definition.
    // Sometimes we'll see the word "class" there, especially in legacy code,
    // but "typename" is less ambiguous,
    // and I strongly recommend using "typename" instead of "class".
    printf("max is %d\n", maxof<int>(5, 21));

    // We can also notice that when we use the template,
    // if we omit the template argument list it'll go ahead and still work,
    // in this case, because it's able to infer that integer is what's meant,
    // because we're passing it a couple of integer literals.
    // In some circumstances this does not work,
    // and I strongly recommend always using
    // the template argument list there, and I'm gonna show why it is so.
    printf("max is %d\n", maxof(30, 7));

    // Let's change this to a character string, a c string.
    // We are using "const" here because these are literal strings,
    // and under some circumstances some compilers will complain
    // if we don't put const there.
    printf("max is %s\n", maxof<const char *>("this", "that"));
    // What's being passed here is pointers.
    // These are c strings, which are just arrays of characters
    // and what's being passed is the address.
    // so this function here is actually comparing the addresses (pointer values),
    // not the collated order of the characters within the strings.

    // Let's say that we want to do this with a cstring.
    // We'll include the C++ string class. (#include <string>)
    // We need to take the c string from that to make it work with printf.
    printf("max is %s\n", maxof<string>("this", "that").c_str());
    // Output is the collated result, which is "this".
    // That's because the string class implements the greater than operator,
    // and it does a collated compare.
    // This is all fine and dandy,
    // but what happens when we now eliminate the template argument list,
    // and we build and run?
    // printf("max is %s\n", maxof("this", "that").c_str()); // it gives an error
    // What happens is it's trying to infer what type of string is meant here,
    // or rather what type of argument is meant here,
    // and it guesses that it's a constant character pointer.
    // It passes that to the template. It builds a specialization for that,
    // and of course that doesn't have a .c_str() member,
    // so that's what this error is for here.
    // If we take out that .c_str() it will work again,
    // but it's assuming that what's meant here is, well, what we passed it,
    // which is these c strings.
    printf("max is %s\n", maxof("this", "that"));
    // In order to even make it work with C++ string class
    // we actually need to use the template argument list.
    // I just recommend doing that all the time.
    // We always use the template argument list.
    // It'll make our code more clear and obvious,
    // and ultimately it'll reduce errors and make debugging a lot easier.

    // There is no format specifier for bool types.
    // However, since any integral type shorter than int is promoted to int
    // when passed down to printf()'s variadic arguments, we can use %d.
    printf("max is %d\n", maxof<bool>(true, false));

    printf("max is %1.2f\n", maxof<float>(33.33, 5.5));

    return 0;
}

// Legacy code is source code inherited from someone else
// or inherited from an older version of the software.
// It can also be any code that we don't understand
// and that's difficult to change.