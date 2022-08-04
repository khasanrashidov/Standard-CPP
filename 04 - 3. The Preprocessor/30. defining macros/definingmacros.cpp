// defining macros
#include <cstdio>
using namespace std;

// macro expansion happens before the compiler even sees this in the preprocessor
#define MACRO 7
// there should not be space between PRODUCT and (a, b); NOT PRODUCT (a, b), it is PRODUCT(a, b)
#define PRODUCT(a, b) (a * b)
#define MAX(a, b) (a > b ? a : b)

// however templates are recommended over parameterized macros

int main(int argc, char **agrv)
{
    int ia = 20;
    int ib = 5;
    printf("value of MACRO is %d\n", MACRO);
    printf("PRODUCT value is %d\n", PRODUCT(ia, ib));
    printf("MAX value is %d\n", MAX(ia, ib));
    return 0;
}
