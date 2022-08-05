// creating and destroying objects with new and delete
#include <cstdio>
#include <new> // for 'nothrow'
using namespace std;

// The 'new' and 'delete' operators are used to allocate memory space for objects in C++.
// Sometimes we need to create an object and use it beyond the lifetime of the function
// or block that it's created in and destroy it later.
// This is what 'new' and 'delete' are for.

class A
{
    int _a = 0;
    int _b = 0;
    int _c = 0;

public:
    A(int i = 0);
    ~A();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
};

A::A(int i) : _a(i), _b(i + 1), _c(i + 2)
{
    puts("A constructor called.");
}

A::~A() { puts("A destructor called."); }

int main(int argc, char **argv)
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    puts("Allocating space for one A object.");
    // So, here we allocate space for the object using the 'new' operator.
    // We declare a pointer of the class that we are creating an object for.
    // We use the 'new' operator and the name of the class, and the new operator
    // returns a pointer to the object.
    // 'new' will allocate space and create the object and call the constructor,
    // and then return a pointer to that new object in the allocated space.
    A *a = new (nothrow) A; // allocating space for default value, which is 0
    // we need to use the 'nothrow' option with new
    // because we are not using exceptions for error reporting
    if (a == nullptr)
    {
        puts("new A failed");
        return 1;
    }
    printf("a: %d, %d, %d\n", a->a(), a->b(), a->c());
    // The 'delete' operator does the opposite. It calls destructor on the object,
    // and then it reclaims the space so that the object can no longer be used.
    // And its space is reclaimed and returned to the pool of space.
    delete a;
    puts("An object has been deleted");

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    puts("Allocating space for one A object.");
    A *b = new (nothrow) A(20); // allocating space for 20
    // we need to use the 'nothrow' option with new
    // because we are not using exceptions for error reporting

    if (b == nullptr)
    {
        puts("new A failed");
        return 1;
    }

    printf("b: %d, %d, %d\n", b->a(), b->b(), b->c());
    delete b;
    puts("An object has been deleted");

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    puts("Allocating space for three A objects.");
    A *c = new (nothrow) A[3]; // allocating space for an array of objects
    // we need to use the 'nothrow' option with new
    // because we are not using exceptions for error reporting

    if (c == nullptr)
    {
        puts("new A failed");
        return 1;
    }

    printf("c: %d, %d, %d\n", c->a(), c->b(), c->c());
    delete[] c;
    puts("An object has been deleted");

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    // So, the 'new' operator used for allocating space for objects in C++.
    // Every object allocated with new must be destroyed with delete.
    // Otherwise our program will leak memory.

    return 0;
}
