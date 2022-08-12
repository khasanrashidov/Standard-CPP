// bitwise operators
#include <cstdio>
using namespace std;

// The bitwise Boolean operators allow us to perform
// Boolean binary operations on integer values.

// The purpose of this file is simply to provide
// a quick and portable way to display binary values.
// The standard printf doesn't provide one,
// so we wrote this simple u8_to_bin function
// to convert an eight bit byte to a binary string.

const char *u8_to_bin(unsigned char x);

int main(int argc, char **argv)
{
    unsigned char x = 5;
    unsigned char y = 10;
    printf("x is %s\n", u8_to_bin(x));
    printf("y is %s\n", u8_to_bin(y));
    printf("result (OR) is %s\n", u8_to_bin(x | y));
    printf("result (AND) is %s\n", u8_to_bin(x & y));
    printf("~x is %s\n", u8_to_bin(~x));
    printf("x & 0xff is %s\n", u8_to_bin(x & 0xff));
    printf("x << 1 is %s\n", u8_to_bin(x << 1));
    printf("y >> 1 is %s\n", u8_to_bin(y >> 1));

    return 0;
}

// So the whole purpose of this u8_to_bin function
// is to be able to display these binary values
// in a binary representation that makes it clear
// what's going on on a bitwise level.
const char *u8_to_bin(unsigned char x)
{
    static char s[sizeof(char) + 1];
    for (char &c : s)
        c = 0; // zero out string
    char *sp = s;
    for (unsigned char z = 128; z > 0; z >>= 1)
    {
        *(sp++) = ((x & z) == z) ? '1' : '0';
        // printf("value of x & z is %d\n", x & z); // to know what's going on here
    }
    return s;
}

// So these are the bitwise Boolean arithmetic operators.
// They allow us to perform the standard Boolean arithmetic
// and bitwise operations for integer values.