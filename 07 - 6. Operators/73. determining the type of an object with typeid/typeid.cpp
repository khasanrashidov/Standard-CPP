// determining the type of an object with typeid
#include <cstdio>
#include <typeinfo> // This defines the typeinfo object that is returned by the typeid operator.
using namespace std;

// The "typeid" operator is used to determine the type of an object.
// It returns a typeinfo object, which is defined in the typeinfo header.

// structures
struct A
{
    int x;
};
struct B
{
    int x;
};

// objects from structures above
struct A a1;
struct A a2;
struct B b1;
struct B b2;

int main(int argc, char **argv)
{
    // We are comparing the typeid of a structure with the typeid of an object.
    // And it's either the same or it's different using this == comparison operator.
    if (typeid(a1) == typeid(A))
        puts("same");
    else
        puts("different");
    // The code above will print out "same" because "a1" is of type "A".

    if (typeid(b1) == typeid(A))
        puts("same");
    else
        puts("different");
    // The code above will print out "different" because "b1" is NOT of type "A".

    // So, how does this work?
    // There's a main method in the typeinfo object,
    // so we can print the name of the type that's returned by that.
    printf("type is %s\n", typeid(A).name());
    printf("type is %s\n", typeid(B).name());
    printf("type is %s\n", typeid(a1).name());
    printf("type is %s\n", typeid(b1).name());

    // This name is not actually literal and it's not by itself, terribly useful.
    // There are circumstances where it can be very long and obscure
    // and it's dependent on the environment.
    // That string above may be different on Windows, Mac OS, UNIX.
    // It may be different with different compilers and different class libraries.
    // So, by itself that string is not terribly useful,
    // but most of the time we just want to know if it's the same as something else,
    // and so we will be using a comparison operator like the == to check it against a class
    // or a type that we know in our code.

    // So, most of the time we just want to know if it's the same as given type
    // and we'll just use the comparison operator.
    // That's how typeid works.

    return 0;
}