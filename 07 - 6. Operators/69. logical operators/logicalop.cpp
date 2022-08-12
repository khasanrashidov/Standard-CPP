// logical operators
#include <cstdio>
using namespace std;

// The logical operators are used for combining logical conditions.

int main(int argc, char **argv)
{
    bool a = true;
    bool b = false;

    if (a && b)
        puts("true");
    else
        puts("false");
    // It prints false because the AND operator is a Boolean operator,
    // a logical operator, which returns a true result only if both its operands are true.

    // Logical OR operator returns true if either of conditions are true.
    if (a || b)
        puts("true");
    else
        puts("false");

    // And there's also not, which will negate an entire logical expression.
    if (!(a && b)) // This used to be false, now it's true.
        puts("true");
    else
        puts("false");

    // So these logical Boolean operators operate on any expression
    // that returns a Boolean true or false.
    // Boolean true is any value that is not zero.
    // Boolean false is always zero, or rather,
    // any value that is equal to zero is Boolean false.
    if (0 || 1)
        puts("true");
    else
        puts("false");

    int x = 1;
    int y = 0;

    if (x && y)
        puts("true");
    else
        puts("false");

    // We can also use the logical operators to combine relational expressions.
    int z = 21;
    int n = 33;

    if (z > n || z < n)
        puts("true");
    else
        puts("false");

    // These logical operators are simple, they're straightforward,
    // they operate on logical conditions, and they may be used for logically
    // combining conditions or logical values.

    return 0;
}
