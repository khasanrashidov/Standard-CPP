// defining types with typedef
#include <cstdio>
#include <cstdint>
using namespace std;

// The typedef keyword may be used to provide and alias for a type name.
// This can be handy in instances where a type declaration becomes cumbersome,
// or it may vary on different target systems.

// Creating an alias for an unsigned character.
// It's traditional to put "_t" infront of a type.
typedef unsigned char points_t;
typedef uint8_t rank_t;

// ************************************************************
// So providing a simple alias like this can be convenient
// in providing architecture-independent types.
// ************************************************************
// In fact, the uint types are actually defined
// in the same way using a typedef
// inside that header file.
// ************************************************************

struct score
{
    points_t p;
    rank_t r;
};

int main(int argc, char **argv)
{
    // We're initializing an object of type score.
    // Which has two members, a points type member and a rank type member,
    // and we're giving them values of five and one.
    score s = {5, 1};

    printf("score s has %d points and rank of %d\n", s.p, s.r);

    // So, the typedef facility can be very convenient
    // for simplifying cumbersome type definitions
    // and for machine-dependent types.
    // This can be handy also when dealing with complex template types.

    return 0;
}