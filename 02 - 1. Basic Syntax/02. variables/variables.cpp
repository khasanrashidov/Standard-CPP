// defining variables
#include<cstdio>
using namespace std;

int main(int argc, char** argv)
{
    int x;
    x = 7;
    printf("x is %d\n", x);
    printf("now the value of x is %d\n", x * 5 - 30);

    const int y = 20;
    // now the y is a constant value, we cannot modify its value or reassign it to the new value
    printf("the value of constant integer y is %d\n", y);

    int z = y;
    printf("z is equal to y and its value is %d as well\n", z);

    printf("\n");
    return 0;
}