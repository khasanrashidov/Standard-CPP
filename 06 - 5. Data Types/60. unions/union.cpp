// unions
#include <cstdio>
#include <cstdint> // standard integer library
using namespace std;

// A union is a data structure that allows us to use
// the same memory space for different data types.

// What this program does is it packs and unpacks an ipv4 IP address.
// So the idea is to be able to put in an IP address
// with the four different numbers and to be able to pack that into a 32-bit integer
// and unpack it into the four different numbers.

union ipv4
{
    // And so this union has two data members.
    // One is the 32-bit unsigned integer,
    // so we're using this uint32 type from the standard integer library.
    uint32_t i32;
    // And the other is a structure with
    // four unsigned 8-bit integers named a, b, c, and d
    // for the different parts of the IP address.
    struct // anonymous struct
    {
        uint8_t a;
        uint8_t b;
        uint8_t c;
        uint8_t d;
    } octets;
};

int main(int argc, char **argv)
{
    union ipv4 addr; // just "ipv4 addr;" itself will work as well
    addr.octets = {192, 163, 73, 42};

    // In %08x
    // 8 says that we want to show 8 digits
    // 0 that we want to prefix with 0's instead of just blank spaces
    // x that we want to print in lower-case hexadecimal.
    printf("addr is %d.%d.%d.%d is %08x\n",
           addr.octets.a, addr.octets.b, addr.octets.c, addr.octets.d, addr.i32);
    // It also prints out a hexadecimal representation of the 32-bit address.

    // So this is a very common use for unions,
    // providing different representations of the same data.
    // Unions may be used to conserve space and data structures,
    // re-using space for various purposes they're not needed in the same record.
    // They're also sometimes used for crude polymorphism

    // A union may be a convenient solution 
    // for some simple cases like this ipv4 address.
    // For more complex uses we may consider using a class.

    return 0;   
}
