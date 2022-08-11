// the void type
#include <cstdio>
using namespace std;

// The void type has special meaning in C++.
// It's used to specify lack of value for function parameters
// and function returns.

// This function has a return type of void.
// This means that the function cannot return a value,
// and in fact, no return statement is required.
// The void type as the parameter type,
// that's this one here, means that
// the function does not take any arguments.
// Now this is one of the few significant differences from C.
// This actually means something slightly different than it does in C.
// In C, the single void type in the argument list
// means the function takes no arguments,
// but for a different reason, in C, a function with no arguments at all,
// does not mean that the function takes no arguments, and so the void type in C
// is actually required here in order to say this function actually
// doesn't take any arguments.
// In C++, a function declaration with no arguments does actually mean that the
// function takes no arguments, and we'll more often see it done without arguments (in C++),
// whereas the void here, is allowed just for compatibility with C.

void func(void)
{
    puts("this is void func(void)");

    // If we did have a return statement, it would simply be
    // return, like this, without a value.
    return;
    // If we try return a value, that would be an error
    // because void function does not return a value.
    // Void function should not return a value.

    // On the other hand, if this were declared as something other than void,
    // then that would represent an error because control reaches end of non-void function.
    // There needs to be a return statement that returns a value.
}

int main(int argc, char **argv)
{
    puts("calling func()");
    func();

    return 0;
}