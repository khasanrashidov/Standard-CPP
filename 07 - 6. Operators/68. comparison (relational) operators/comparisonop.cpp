// comparison (relational) operators
#include <cstdio>
using namespace std;

// The comparison operators are used
// to compare for equality or for relative value.

int main(int argc, char **argv)
{
    int x = 5;
    int y = 7;

    // Double equals sign (==) is the equality comparison,
    // and so it's testing if these two values are the same.
    if (x == y)
        puts("true");
    else
        puts("false");
    // It says "false" because X and Y are not equal.
    // And if X and Y were equal then we would get "true".

    // We can also test for "not equal" with this comparison,
    // exclamation point, and the equals sign next to each other (!=) means "not equal".
    if (x != y)
        puts("not equal");
    else
        puts("equal");

    // There's also "greater than" and "less than".
    if (x > y)
        printf("%d is greater than %d\n", x, y);
    else
        printf("%d is not greater than %d\n", x, y);

    if (x < y)
        printf("%d is less than %d\n", x, y);
    else
        printf("%d is not less than %d\n", x, y);

    int z = 20;
    int n = 20;

    // greater than or equal to sign
    if (z >= n)
        printf("%d is greater than or equal to %d\n", z, n);
    else
        printf("%d is not greater than or equal to %d\n", z, n);

    if (z <= n)
        printf("%d is less than or equal to %d\n", z, n);
    else
        printf("%d is not less than or equal to %d\n", z, n);

    // So, these comparison operators are used to compare for relative value or for equality.
    // These are simple and effective operators that work on any scale or type.
    // For class types, they may be overloaded.

    return 0;
}