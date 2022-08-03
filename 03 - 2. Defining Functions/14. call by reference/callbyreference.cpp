// call by reference
#include <cstdio>
using namespace std;

// explicit call by reference
void function1(int *point)
{
    ++(*point);
    *point = *point * 5;
    printf("a is %d in function1\n", *point); // prints 10
}

// implicit call by reference
void function2(int &ref)
{
    ++ref;
    printf("b is %d in function2\n", ref); // prints 3
}

int main(int argc, char **argv)
{
    // for explicit call by reference
    int a = 1;
    function1(&a);
    printf("a is %d in main function\n", a); // prints 10

    // for implicit call by reference
    int b = 2;
    function2(b);
    printf("b is %d in main function\n", b); // prints 3

    return 0;
}