// Using macros as constants
#include <cstdio>
using namespace std;
// using macros as constants
// defining preprocessor constants
// preprocessor contants are not actual constants,
// although they're commonly called constants,
// and are used for that purpose, they are macros

// there is non semi-colon at the end of the preprocessor directive
// and we define macros with all capital letters (in order to distinguish from variables or other types)
#define ONE 1 // 'ONE' is the symbol and '1' is what 'ONE' expands to
// so when the preprocessor encounters this ('ONE') symbol,
// it actually replaces it with the literal value before the compiler ever gets to it

#define HELLO_STRING "Hello, World!"

int main(int argc, char **argv)
{
    const int one = 1;
    printf("value is %d\n", one);
    puts("Hello, World!");

    printf("%s\n", HELLO_STRING);
    printf("value is %d\n", ONE);
    // but this ('ONE') over here, this is not a variable
    // we can't get its address, it won't show up in the debugger,
    // and we can't use a pointer with it
    return 0;
}
