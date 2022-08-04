// about the preprocessor
#include <cstdio> // include directive
using namespace std;

#define ONE 1
#define MAX(a, b) (a > b ? a : b)


int main(int argc, char **argv)
{
    puts("Hello, World!");
    printf("The largest among 20 and 5 is %d\n", MAX(20, 5));
    printf("ONE: %d\n", ONE);
    return 0;
}
