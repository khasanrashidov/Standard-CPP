// creating function objects
#include <cstdio>
using namespace std;

// By overloading function operator we can create a class
// that operates as if it were a function.
// This pattern is sometimes called a functor.
// This can be a handy technique for circumstances where
// we need to keep state, or other context information
// with our function calls.

// The function-operator is a handy way to create an object that works like a function,
// yet has the ability to keep state and other information between function calls.

class MultBy
{
    int mult = 1;
    // Our class MultBy has the private default constructor,
    // so we cannot construct this object without passing it an integer.
    MultBy();

public:
    MultBy(int n) : mult(n) {}
    // Here we see the function operator overload.
    // The function operator is the parentheses, so it returns an int,
    // and we have the operator keyword, and the operator itself,
    // which is the function operator.
    // It takes one parameter which is a number that would be multiplied by the multiplier.
    int operator()(int n) const { return mult * n; }
};

// Then using the function overload operator

int main(int argc, char **argv)
{
    const MultBy times4(4); // it is like times4 = 4;
    const MultBy times10(10);
    const MultBy times15(15);

    printf("times4(5) is %d\n", times4(5));
    printf("times4(15) is %d\n", times4(15));
    printf("times10(5) is %d\n", times10(5));
    printf("times10(15) is %d\n", times10(15));
    printf("times15(5) is %d\n", times15(5));
    printf("times15(15) is %d\n", times15(15));

    return 0;
}