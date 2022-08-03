// using function pointers
#include <cstdio>
using namespace std;

void func()
{
    puts("this is func()");
}

void func2()
{
    puts("this is func2()");
}

int main(int argc, char **argv)
{
    puts("this is main()");
    void (*fp)() = &func; // void (*fp)() = func; works as well
    (*fp)();              // fp(); works as well

    void (*funcp)() = func2; // *funcp is a function pointer and func2 is without ()
    funcp();

    return 0;
}