// the ternary conditional operator
#include <cstdio>
using namespace std;

// The ternary conditional operator is a simple shortcut
// for choosing a value based on a condition.

int main(int argc, char **argv)
{
    int x = 21;
    int y = 33;

    // If the condition evaluates to true,
    // the expression will return the first argument before the colon,
    // and if not, it will return the second argument after the colon.
    printf("is the condition true? %s\n", x > y ? "yes" : "no");
    printf("is the condition true? %s\n", x < y ? "yes" : "no");

    // The ternary conditional operator takes three operands.
    // The one to the left of the question mark is a Boolean expression
    // that returns true or false, non-zero or zero.
    // The next expression is returned if the condition is evaluated to true
    // and the next expression is returned if the condition is evaluated to false.
    // This operator can not be overloaded, but we can generally achieve
    // whatever desired affect we desire by overloading the conditional operators.
    // This can be very handy in cases where we just need to select the scale or value
    // and we don't need the complexity of a block-oriented if/else construct.
    // So, the ternary conditional operator is a common shortcut
    // for testing a simple condition with a simple scale of result.

    return 0;
}