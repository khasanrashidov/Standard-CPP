// pointers
#include<cstdio>
using namespace std;

int main(int argc, char** argv)
{
    int x = 5;
    int y = 21;
    int *ip = &x;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("\n");

    x = 48;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("\n");

    ip = &y;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("\n");

    return 0;
}