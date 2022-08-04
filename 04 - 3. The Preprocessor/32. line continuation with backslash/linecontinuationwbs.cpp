// line continuation with backslash
#include <cstdio>
using namespace std;

// line continuation with backslash makes complex macros more readable
#define SWAP(a, b) \
    do             \
    {              \
        a ^= b;    \
        b ^= a;    \
        a ^= b;    \
    } while (0)

int main(int argc, char **argv)
{
    int x, y;
    x = 20;
    y = 5;

    puts("Hell\
o, World!"); // backslash immediately followed by a newline will not change anything
    printf("x is %d, y is %d\n", x, y);
    SWAP(x, y);
    printf("x is %d, y is %d\n", x, y);
    return 0;
}
