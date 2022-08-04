// conditional compilation
#include <cstdio>
#define FOO // before #include "conditional.h"
#include "conditional.h"

int main(int argc, char **argv)
{
    printf("Number is %d\n", NUMBER);
    return 0;
}