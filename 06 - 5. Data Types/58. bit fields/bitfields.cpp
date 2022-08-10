// bit fields
#include <cstdio>
using namespace std;

// Bitfields provide the ability
// to pack multiple values into less space
// than they would normally take.

struct preferences
{
    // Each of these items in the structure they have a colon and a number,
    // and that number is the number of bits that that value will take up in the structure,
    // and so these are ordered and packed in a certain way, actually, depending on the architecture.

    // So we have structure members that are boolean and are taking up one bit,
    // and an unsigned integer that is taking up just four bits,
    // and so obviously, the range of that unsigned integer,
    // will be what can be described in four bits.

    bool likesMusic : 1;
    bool playsBadminton : 1;
    bool hasInternet : 1;
    bool hasCar : 1;
    unsigned int numberOfChildren : 4U;
};

int main(int argc, char **argv)
{
    // Here in main, we are able to use these bitfields just as we would any other structure member.
    struct preferences john;
    john.likesMusic = true;
    john.playsBadminton = true;
    john.hasInternet = true;
    john.hasCar = false;
    john.numberOfChildren = 2;

    printf("sizeof int: %ld bits\n", sizeof(int) * 8);
    printf("sizeof john: %ld bits\n", sizeof(john) * 8);
    // So, we need to be aware that the language does not guarantee
    // any particular bit ordering or any particular byte packing,
    // or any particular data alignment.
    // And so all of that is actually determined by
    // the architecture of the target machine,
    // and by the architecture of the compiler.
    // So, how our data is actually stored in memory
    // is highly dependent upon these other factors
    // and will not be consistent across systems.
    // So this becomes an issue if we store packed data in a file
    // and then expect to read it on a different machine,
    // so it's also worth noting that bitfields
    // can be a source of trouble in concurrent or threaded programming
    // because all of the bits in a unit must be read and written at the same time.
    // So, this is how bitfields work, this is some of their limitations.

    if (john.likesMusic)
        printf("john likes music\n");
    if (john.playsBadminton)
        printf("john plays badminton\n");
    if (john.hasInternet)
        printf("john has net\n");
    if (john.hasCar)
        printf("john has a car\n");
    printf("john has %d children \n", john.numberOfChildren);

    return 0;
}