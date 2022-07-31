// looping with while and do while
#include <cstdio>
using namespace std;

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};
    int i = 0;
    // while loop
    while (i < 5) {
        printf("element %d is %d\n", i, a[i]);
        ++i;
    }

    printf("\n");

    int b[] = {1, 2, 3, 4, 5};
    int j = 0;
    //do while loop
    do {
        printf("element %d is %d\n", j, a[j]);
        ++j;
    } while (j < 5);


    printf("\n");
    return 0;
}