// functions
#include <cstdio>
using namespace std;

unsigned long factorial(unsigned long n)
{
    if (n < 2) return 1;
    return factorial(n - 1) * n;
}

int main(int argc, char **argv)
{
    printf("%s\n", argv[1]);

    // if no arguments are supplied, argc will be one
    printf("%d\n", argc); // prints 1

    // prints the location path of the functions.cpp
    for (int i = 0; i < argc; ++i)
    {
        puts(argv[i]);
    }

    int j = 0;
    puts(argv[j]); // prints the location path of the functions.cpp too

    printf("%s\n", argv[0]); // prints the location path of the functions.cpp too

    // prints the location path of the functions.cpp too
    while (*argv != NULL)
    {
        printf("%s\n", *argv);
        argv++;
    }

    printf("\n");

    int num = 5;
    printf("factorial of %d is %d\n", num, factorial(num));

    printf("\n");
    return 0;
}