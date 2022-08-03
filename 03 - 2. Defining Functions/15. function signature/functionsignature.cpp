// function signature
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

// function signature
/* 
    Even though the two functions have the same name,
    1) the return type, 
    2) the name of the function, and
    3) the types of the function arguments are all combined to form a function signature.

    The function signature is used to identify the function.
    Understaning functions is fundemenatal to C++.
    Even in C++'s OOP model, functions are the basis of class methods.
    All code in a C++ program happends in functions.
*/

long volume(long a, long b, long c)
{
    return a * b * c; // returns the volume of a cuboid
}

double volume(double r, int h)
{
    return M_PI * r * r * h; // returns the volume of a sphere
}

int main(int argc, char **argv)
{   
    printf("%d\n", volume(5, 5, 5));
    printf("%f\n", volume(3, 5));
    
    printf("\n");
    printf("location of functionsignature.exe file:\n%s\n", argv[0]);
    printf("\n");
    return 0;
}