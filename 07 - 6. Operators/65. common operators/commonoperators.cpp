// common operators
#include <cstdio>
using namespace std;

// There are a few common operators that we are probably already familiar with.
// Fo completeness sake, let's go over them quickly.

int main(int argc, char **agrv)
{
    int x = 5;
    // The assignment operator is used to copy a value from one object to another.
    // Assingment operator assigns a value.
    x = 21;
    int y = 30;

    // It's worth noting that the addition, subtraction, multiplication and division operator,
    // in fact, most opertors return a temporary object, which can then be
    // copied with the assignment operator or used in an expression.
    // So, in this case, "x + y" returns a new temporary object without actually overriding
    // either of these existing objects. And then, that temporary object is then copied to x
    // and then the temporary object is discarded.
    x = x + y;
    printf("value is %d\n", x);
    // And if it is an object in the class sense of an object,
    // before it's discarded, its destructor is called.

    x = y - x;
    printf("value is %d\n", x);
    x = -(x * y);
    printf("value is %d\n", x);
    x = y / x; // integer division, if x > y then it is 0
    printf("value is %d\n", x);

    x = 21 / 5; // It's a value without the remainder part
    printf("value is %d\n", x);

    // If we want the remainder part, then we use the modulo operator,
    // which is indicated with the % and that gives us actually the remainder
    // and not the mantissa of the result of the division.
    x = 21 % 5;
    printf("value is %d\n", x);

    // There is also a unary minus and plus.
    x = -y;
    printf("value is %d\n", x);
    // It returns, again, a new temporary object with
    // the value of y in the minus domain instead of the plus domain.

    int z = -33;
    x = -z;
    printf("value is %d\n", x);
    

    return 0;
}