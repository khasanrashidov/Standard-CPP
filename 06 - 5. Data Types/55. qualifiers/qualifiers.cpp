// qualifiers
#include <cstdio>
using namespace std;

// Qualifiers are used to adjust qualities of an object or a variable.
// There are two types of qualifiers in C++, CV qualifiers and storage qualifiers.

// This is an example of a variable declaration with qualifiers.
// In this example, the const and static keywords are qualifiers.
// They tell the compiler that this variable will be immutable. That's the const qualifier.
// And that it will have static storage duration.
const static int i = 21;

// There are two types of qualifiers.
//
// CV stands for constant and volatile,
// so const marks the variable as read-only or immutable.
// It's value cannot be changed once it's been defined.
// Volatile marks a variable that may be changed by another process.
// This is generally used for threaded code, or externally linked code.
// Mutable is used on a data member to make it writable from a const qualified member function.
//
// Storage Duration specifiers are used to define the duration, or lifetime, of a variable.
// By default, a variable defined within a block has automatic lifetime.
// Lifetime is the duration of the block. There is no qualifier for this because the default.
// There used to be an auto qualifier, but it was rarely used,
// so the keyword has been re-purposed.
// Variables declared as static have life beyond the execution of a block.
// Static variables live for the duration of the program.
// Static variables are commonly used for keeping state
// between instances of a given function or method.
// Static variables are stored globally, even if they are stored in a class.
// By default, a variable defined outside of any block is static.
// Register variables are stored in processor registers.
// This can make them faster and easier to access and operate on.
// This qualifier is taken as a suggestion by the compiler.
// The compiler may or may not actually store the variable in a register.
// Extern variables are defined in a separate translation unit
// and are linked with our code by the linker step of the compiler.

// ||||||||||||||||||||||||||||||||||||
// | CV Qualifiers | Storage Duration |
// ||||||||||||||||||||||||||||||||||||
// | const         | static           |
// | volatile      | register         |
// | mutable       | extern           |
// ||||||||||||||||||||||||||||||||||||

class S
{
public:
    int static_value()
    {
        static int x = 7;
        return ++x;
    }
};

int func()
{
    static int x = 7;
    return ++x;
}

int main(int argc, char **argv)
{
    int j = 21; // By default, this variable has automatic storage duration.
    // It's not marked as const, so it is volatile.

    const int k = 5; // This is a constant variable.
    // As it is immutable or read-only variable, it is not assignable.

    // static duration keeps state inside a function or a class
    printf("The integer is %d\n", func());
    printf("The integer is %d\n", func());
    printf("The integer is %d\n", func());
    printf("The integer is %d\n", func());
    printf("The integer is %d\n", func());

    puts("");

    // What's interesting is that static variables work exactly the same way inside of a class.
    // We would think that the static variable would be encapsulated in the class
    // like everything else is. But instead, it's actually global.
    S a;
    S b;
    // We will get different values even though we have two instances of this class
    // because the x is declared static, and it's the same instance of the static variable.
    // We need to be aware that there will only be one copy of a static variable globally.
    printf("The integer is %d\n", a.static_value());
    printf("The integer is %d\n", b.static_value());
    printf("The integer is %d\n", a.static_value());
    printf("The integer is %d\n", b.static_value());
    printf("The integer is %d\n", a.static_value());
    printf("The integer is %d\n", b.static_value());
    printf("The integer is %d\n", a.static_value());
    printf("The integer is %d\n", b.static_value());

    // Qualifiers are used to control the quality of variables.
    return 0;
}