#include <cstdio>
#include "func.h" // in quotes "func.h"
using namespace std;
// in C++ everything must be declared before it's used
// defining a function
// void func(); // declaring the function

int main(int argc, char **argv)
{
    puts("this is main()");
    func();
    return 0;
}

void func() // return type void means that the function does not return a value
{
    puts("this is func()");
}
