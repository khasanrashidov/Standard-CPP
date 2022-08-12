// increment and decrement operators
#include <cstdio>
using namespace std;

// C++ provides unary operators for incrementing and decrementing values.

int main(int argc, char **argv)
{
    int x = 30;
    // Prefix increment - increments the value and then returns the value: ++x
    // Postfix increment - the value is returned first and the value is incremented: x++

    printf("prefix increment: value is %d\n", ++x); // prefix increment

    printf("postfix increment: value is %d\n", x++);     // postfix increment
    printf("after postfix increment: value is %d\n", x); // after postfix increment

    puts("");

    int ia[5] = {1, 2, 3, 4, 5}; // an array of integers
    int *ip = ia;                // a pointer to the array, which points to the first element of the array

    printf("value is %p\n", ip);
    printf("value is %d\n", *ip++); // post-increment
    printf("value is %p\n", ip);
    printf("value is %d\n", *ip);

    printf("value is %d\n", *(++ip)); // pre-increment
    printf("value is %d\n", *ip);
    printf("value is %p\n", ip);
    // It's worth noting that we need the parentheses with the pre-increment
    // and we don't with the post-increment, because of operator precedence.
    // But it's always a good idea to just use the parentheses.

    // Now, what's interesting about this, if we print the value of the pointer itself,
    // we'll notice that the pointer increases by the size of an integer, which is four bytes,
    // because it's a strongly-typed pointer.
    // And it knows the size of what it needs to increment by, so it's doing that.

    puts("");

    // If, instead, this was a character array, and a character pointer,
    // it would increment by just one byte.
    char ib[5] = {1, 2, 3, 4, 5}; // an array of characters
    char *iptr = ib;              // a pointer to the array, which points to the first element of the array

    printf("value is %p\n", iptr);
    printf("value is %d\n", *iptr++); // post-increment
    printf("value is %p\n", iptr);
    printf("value is %d\n", *iptr);

    printf("value is %d\n", *(++iptr)); // pre-increment
    printf("value is %d\n", *iptr);
    printf("value is %p\n", iptr);

    puts("");

    return 0;
}