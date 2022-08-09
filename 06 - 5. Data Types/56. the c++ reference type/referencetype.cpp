// the c++ reference type
#include <cstdio>
using namespace std;

// We are going to have this function return a reference to an int.
// And we're going to have it take a reference to an int as its argument.
// So, when the function is called, it's called with a reference.
int &f(int &j)
{
    ++j; // this j now refers to i
    return j;
}

const int &h(const int &k) // And we no longer have our side effect.
{
    static int s = k;
    ++s;
    return s;
}

int main(int argc, char **argv)
{
    int i = 5;
    int &ir = i; // This makes this reference bound to that object.
    // Then we can use either the reference or the object in exactly the same way.
    printf("the value of i is %d\n", i);
    printf("the value of ir is %d\n", ir);
    puts("");

    ir = 21;
    printf("the value of i is %d\n", i);
    printf("the value of ir is %d\n", ir);
    puts("");

    i = 30;
    printf("the value of i is %d\n", i);
    printf("the value of ir is %d\n", ir);
    puts("");

    // And so, we can use ir just as if it were i.
    // We can give it values.
    // We can assign it to other things.
    // We can increment it and pass it to variables.
    // We can do whatever we want with it and it will act just as if it were i.

    // So, a reference works very much like a pointer,
    // but with obviously with some significant differences.
    // The syntax of setting a reference is different and
    // does not involve using the address of operator.
    // The syntax of getting the value referred to by a reference
    // also does not involve using the value of dereference operator (no need of asterisk *).

    // We cannot refer to the reference itself.
    // That is, we cannot take a reference of the reference.
    // We cannot have a pointer to a reference.
    // We cannot have an array of references.
    // And the reference cannot be null.
    // It cannot be unitialized.
    // And it cannot be changed to refer to another variable.
    // The reference, in essence, doesn't exist anymore syntactically.
    // It just becomes exactly the same as using the variable itself.
    // So, obviously this isn't a very effective use of a reference.

    // Most often, references are used with functions and object methods.

    // This is what's called and unintended side effect.
    printf("the value is %d\n", i);
    printf("the value is %d\n", f(i));
    printf("the value is %d\n", i);
    printf("the value is %d\n", f(i));
    printf("the value is %d\n", i);
    printf("the value is %d\n", f(i));
    printf("the value is %d\n", i);
    puts("");

    int n = 7;
    printf("the value is %d\n", n);
    printf("the value is %d\n", h(n));
    printf("the value is %d\n", n);
    printf("the value is %d\n", h(n));
    printf("the value is %d\n", n);
    printf("the value is %d\n", h(n));
    printf("the value is %d\n", n);
    puts("");

    // So, whenever we're using references,
    // especially in function calls and class method calls,
    // we always want to make them const.
    // Unless, we really want side effects.
    // And if we really want side effects,
    // then it is always better to use pointers instead of references
    // because then it's more obvious. (IMO)

    // References are very powerful and very common in C++.

    puts("The C++ reference type");
    return 0;
}