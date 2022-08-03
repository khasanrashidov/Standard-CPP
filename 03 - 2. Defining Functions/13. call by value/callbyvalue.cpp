// call by value
#include <cstdio>
using namespace std;

void f(int a)
{
    ++a;
    printf("a is %d in function f\n", a); // prints 2
}

int main(int argc, char **argv)
{
    int a = 1;
    f(a);
    printf("a is %d in main function\n", a); // prints 1
    return 0;
}