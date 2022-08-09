// integer types
#include <cstdio>
#include <cstdint> // for Specific Width Integer Types
using namespace std;

// The integer types are simple, fundamental data types for representing Integer values,
// that is whole numbers with no fractual part.
// The Integer types include "char", "int", "short int", "long int", and "long long int".
// These are all available in both signed and unsigned versions.
// The size of each type vary depending on both the architecture and the compiler.

// -- "char" --
// The "char" type is defined as the minimum size necessary to contain a character.
// On most modern systems that's eight bits. The "char" type may be signed or unsigned by default,
// that is on some systems it may be signed and on other systems it may be unsigned,
// we cannot count on a "char" being one or the other, the only thing we can count on is that
// it will hold a character.

// All the other Integer types are signed unless modified with the "unsigned" keyword.

// -- "short int" --
// The "short int" is the smallest natural size of an Integer for the target processor.
// It may be the same as "int", on most modern desktop systems it is 16 bits.

// -- "int" --
// The "int" type is the natural size of an Integer for the target processor.
// On most modern systems it's 32 bits.

// -- "long int" --
// The "long int" type is at least the size of an "int", and it's often double the size of an "int".
// On most modern systems it's either 32 or 64 bits.

// -- "long long int" --
// The "long long int" is at least the size of a "long int", it may be double size of a "long int".
// On most modern systems it's 64 bits.

// Unsigned Integer Types
// For the signed types, the most significant bit is a sign bit.
// Unsigned types ar available with the "unsigned" modifier:
// unsigned char
// unsigned short int
// unsigned int
// unsigned long int
// unsigned long long int

// Specific Width Integer Types
// If our usage requires an Integer of a specific type, the "cstdint" header provides types
// in these specific widths, eight bits, 16 bits, 32 bits and 64 bits.
// And these are available both in signed and unsigned varieties.
// #include <cstdint>
// |||||||||||||||||||||||||||||
// | Size | Signed  | Unsigned |
// | 8    | int8_t  | uint8_t  |
// | 16   | int16_t | uint16_t |
// | 32   | int32_t | uint32_t |
// | 64   | int64_t | uint64_t |
// |||||||||||||||||||||||||||||

int main(int argc, char **argv)
{
    puts("");
    puts("Integer Types");

    // The "sizeof" operator returns the number of bytes for a given type,
    // we multiply the result by eight to get the result in bits.
    printf("sizeof char is %ld bits\n", sizeof(char) * 8); // %ld is for "long int"
    printf("sizeof short int is %ld bits\n", sizeof(short int) * 8);
    printf("sizeof int is %ld bits\n", sizeof(int) * 8);
    printf("sizeof long int is %ld bits\n", sizeof(long int) * 8);
    printf("sizeof long long int is %ld bits\n", sizeof(long long int) * 8);

    puts("");

    // It's worth mentioning that due to a legacy feature from C.
    // "int" is a sort of a default type, and what that means is if we take out the word "int"
    // and just leave the keywords "short", "long", "long long" that'll actually give us
    // exactly the same result as above.
    // So, "short" is just a shorthand for "short int".
    // And it's also true of "long" and of "long long".
    printf("sizeof short is %ld bits\n", sizeof(short) * 8);
    printf("sizeof long is %ld bits\n", sizeof(long) * 8);
    printf("sizeof long long is %ld bits\n", sizeof(long long) * 8);

    puts("");

    // Specific Width Integer Types
    // So, if we really are concerned with the size of our Integers, and
    // specifically if we are going to be concerned with it cross-platforms,
    // then we are gonna wanna use the "cstdint" versions rather than the
    // "char", "int", "short int", "long int".
    printf("sizeof int8_t is %ld bits\n", sizeof(int8_t) * 8);
    printf("sizeof int16_t is %ld bits\n", sizeof(int16_t) * 8);
    printf("sizeof int32_t is %ld bits\n", sizeof(int32_t) * 8);
    printf("sizeof int64_t is %ld bits\n", sizeof(int64_t) * 8);

    puts("");

    // Literal values
    // So, this 21 is actually a "decimal" Integer.
    // If we want to specify that it's a "long" Integer
    // we can put an "L" after, like that. And we can put "U" for "unsigned".
    long int x = 21UL; // 21UL is (unsigned long)21UL
    printf("x is %ld\n", x);

    // When we use a leading zero on a number then C will interpret that as octal, base-8.
    // octal is from zero to seven (0~7), only numbers 0, 1, 2, 3, 4, 5, 6, 7 are allowed,
    // otherwise it will give an error
    long int y = 030;        // 030 is octal number and it is 24 in decimal, base-10
    printf("y is %ld\n", y); // prints octal in decimal

    // 0x is for hexadecimal values
    long int z = 0x55FF;     // 0x55FF is hexadecimal number and it is 22015 in decimal, base-10
    printf("z is %ld\n", z); // prints hexadecimal in decimal

    // 0b is for binary values
    long int b = 0b11001111; // 0b11001111 is binary number and it is 207 in decimal, base-10
    printf("b is %ld\n", b); // prints binary in decimal

    // So, C++ provides a full selection of Integral types, in many sizes, both signed and unsigned.

    puts("");
    puts("Integer Types");
    return 0;
}
