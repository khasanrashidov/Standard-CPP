// iterating with for loop
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
    {
        printf("element %d is %d\n", i, a[i]);
    }
    
    printf("\n");

    char s[] = "string";
    // array name s is a pointer by default
    // here condition is *cp and it has true (non zero or not null) value
    // if there is zero or null value in the condition then it is false
    // and we are just incrementing the pointer
    for (char *cp = s; *cp; ++cp)
    {
        printf("element %c\n", *cp);
    }

    printf("\n");
    return 0;
}