// using the range-based for loop
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};

    for (int i : a) // int variable 'i' contains the element of the container 'a'
    {
        printf("element is %d\n", i);
    }

    printf("\n");

    // string is an array of characters with a terminating 0
    char s[] = "string";
    for (char c : s)
    {
        // as string is an array of characters with a terminating 0,
        // without STL string it prints blank
        // with STL string there is no blank in the end of printing
        if (c == 0) break; // to remove the blank
        printf("element is %c\n", c);
    }
    printf("\n");
    
    return 0;
}