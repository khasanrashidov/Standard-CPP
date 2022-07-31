// switch, the branching conditional
#include<cstdio>
using namespace std;

int main(int argc, char ** argv)
{
    const int iONE = 1;
    const int iTWO = 2;
    const int iTHREE = 3;
    const int iFOUR = 4;
    const int iFIVE = 5;
    const int iTWENTY = 20;

    int x = 2;

    switch (x)
    {
    case iONE: /* constant-expression */
        /* code */
        puts("one");
        break; // break for not jumping to other cases
    case iTWO:
    case iTWENTY:
        puts("two or twenty");
        break;
    case iTHREE:
        puts("three");
        break;
    case iFOUR:
        puts("four");
        break;
    case iFIVE:
        puts("five");
        break;

    default:
        puts("default");
        break;
    }

    return 0;
}