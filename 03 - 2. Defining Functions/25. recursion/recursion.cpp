// using recursion
#include <cstdio>
using namespace std;

unsigned long int factorial(unsigned long int n)
{
    if (n < 2) return 1;
    return factorial(n - 1) * n;
}

int main(int argc, char **argv)
{
    unsigned long int n = 5;
    printf("Factorial of %ld is %ld\n", n, factorial(n));
    printf("Factorial of %ld is %ld\n", 4, factorial(4));
    printf("Factorial of %ld is %ld\n", 10, factorial(10));

    // using factorial (it is effective)
    unsigned long int fact = 1;
    unsigned long int num = n;
    for (int i = 0; i < n; i++)
    {
        fact = fact * num;
        num--;
    }
    printf("Factorial of %ld is %ld\n", n, fact);

    return 0;
}