// floating-point types
#include <cstdio>
using namespace std;

// C++ provides the common basic point types.
// C++ provides these floating point types: "float", "double", and "long double".
// "float" is 4 bytes
// "double" is 8 bytes
// "long double" is 16 bytes (or 8 bytes depending on the architecture and the compiler)

int main(int argc, char **argv)
{
    // Literal floating point numbers are indicated by having a decimal point,
    // so if we say "500.0", that's a literal floating point number.
    // We can do the same thing with scientific notation and
    // we can say "5e2" and we get exactly the same value.
    float f = 500.0;
    double df = 5e2; // here we've indicated 500 with scientific notation
    long double ldf;

    printf("float f is %f\n", f); // %f is for floating-point numbers
    printf("float df is %f\n", df);

    puts("");

    printf("size of float f is %ld bytes\n", sizeof(f));
    printf("size of double df is %ld bytes\n", sizeof(df));
    printf("size of long double ldf is %ld bytes\n", sizeof(ldf));

    puts("");

    // It's important to understand the distinction between scale and precision when we're working
    // with floating point numbers. Scale is how large or how small a number maybe represented.
    // Precision is the accuracy of the representation to a number of significant digits.
    // What this means, is that when we use floating point numbers, we may get rounding errors.

    float num;
    num = 0.1 + 0.1 + 0.1;
    // we would expect the result of that to be 0.3
    printf("float num is %1.10f\n", num);
    // %1.10f is for printing out the number to 10 significant digits (0.3000000119)
    // and then we can see that there is a little bit of a rounding error

    if (num == 0.3)
    {
        puts("true");
    }
    else
    {
        puts("false"); // the value is not actually equal to 0.3.
    }

    puts("");

    // So while it may be possible to represent very large or very small values
    // using floating point types, the precision of these types is always limited.
    // Now we get more precision with the larger types, so if we make this a double float,
    // it's represented by a large space, and so it can represent more precision.
    double num2;
    num2 = 0.1 + 0.1 + 0.1;
    printf("float num is %1.10f\n", num2);
    printf("float num is %1.20f\n", num2); // %1.20f means 20 digits after floating point

    // So, on most modern systems float is 32 bits, which is a precision to about seven digits.
    // Double is 64 bits, which is a precision to about 16 digits.
    // And long double is either a synonym for double, or it may be an 80 bit IEEE floating point format.
    // The precision is going to vary.

    // What's important to understand is that while it's possible to represent
    // very large or very small numbers with these types, it is always at the expense of accuracy,
    // and if precision is important as in the case of accounting
    // where we're going to want no rounding errors whatsoever, then we'll want to use integer type instead.

    puts("");

    return 0;
}
