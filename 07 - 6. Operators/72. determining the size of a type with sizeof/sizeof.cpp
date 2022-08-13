// determining the size of a type with sizeof
#include <cstdio>
using namespace std;

// The "sizeof" operator is used to determine the size of an object.
// Sizeof is an operator. Sometimes it doesn't look like an operator
// because it's a word and not a symbol.

int main(int argc, char **argv)
{
    int x = 7;
    // We want to know how much space that "x" takes up in bytes.
    // We use "%ld" to print out because the type that sizeof returns
    // is actually called "size_t". And it's typically defined
    // as a constant unsigned integer, but it can be different platforms.
    // But it's usually an unsigned long integer.
    printf("size is %ld\n", sizeof x);
    // We can write "sizeof x" because this is an operator, it's NOT a function.

    // Sizeof returns a value in bytes
    // and so the size of an integer on this machine
    // is 4 bytes or 32 bits.

    // If we want to take the size of a type or a class instead of a value,
    // we have to put that in parentheses.
    printf("size is %ld\n", sizeof(int));

    // We can define a struct or class like this.
    struct X
    {
        int a;
        int b;
        char c;
        char d;
        long int e;
        long int f;
    };

    printf("size is %ld\n", sizeof(X));
    // So even though the parentheses are optional for variables,
    // it is a good idea/habit to include them anyway
    // because it just makes it clearer.
    // We know that makes it look more like a function than an operator,
    // but that really doesn't have any impact on the readability of the code.
    // So, it's usually good to include the parentheses just on general principle.

    // The "sizeof" operator can be useful when we need to find out
    // how much space is required for an object or a type.

    return 0;
}