// compound assignment operators
#include <cstdio>
using namespace std;

// C++ supports compound assignment operators
// that allow us to combine an assignment with an arithmetic operation.
// These are both convenient and efficient.

class num
{
private:
    int value;

public:
    num(int x) : value(x) {}
    int getvalue() const { return value; }
    int setvalue(int x) { return value = x; }
    num &operator+=(const num &n);
};

// compound addition operator
num &num::operator+=(const num &n)
{
    value += n.value;
    return *this; // returns a reference to itself
}

int main(int argc, char **argv)
{
    int x = 7;
    int y = 33;

    // When this addition operation happens,
    // x is called with addition operator
    // and the parameter of y.
    // A temporary object is created,
    // and the value of x is copied into that temporary object.
    // Then the value of y is added to the value in that temporary object.
    // Then that temporary object is returned.
    // And then the assignment operator is called on the object x,
    // and that temporary result is then copied into the value of x.
    // So we have two copy operations
    // and we have a temporary object that is created and its constructor is called.
    // Then, after the result is used, that temporary object is destroyed
    // and its destructor is called.
    // So there's a lot of stuff going on, just to do this simple addition and assignment.
    x = x + y;
    printf("value is %d\n", x);

    // Instead of all of that, we can just do this.
    x += y;
    printf("value is %d\n", x);
    // Now what happens is much, much simpler.
    // The compound addition operator is called on the object x.
    // The value of y is added to the value of x and a reference to x is returned.
    // So there's only the one copy operation, and it's really just the addition.
    // It's not even a complete copy operation that happens.
    // And it happens in place, and then a reference is returned from the object x.
    // So when we do this, we see the result is the same, but it's a lot more efficient.
    // There is a lot less going on just to do that simple addition.

    x -= y;
    printf("value is %d\n", x);
    x *= y;
    printf("value is %d\n", x);
    x /= y;
    printf("value is %d\n", x);
    x %= y;
    printf("value is %d\n", x);
    puts("");

    // Then there's bitwise operators for "AND" and "OR", and for left and right shift.
    x &= y;
    printf("value is %d\n", x);
    x |= y;
    printf("value is %d\n", x);
    x <<= y;
    printf("value is %d\n", x);
    x >>= y;
    printf("value is %d\n", x);
    puts("");

    num n(7);
    num n2(33);
    n += n2;
    printf("value is %d\n", n.getvalue());
    puts("");

    // So these compound assignment operators are convenient,
    // they're safe, and they're often -- usually, actually --
    // more efficient than their common equivalents.

    return 0;
}