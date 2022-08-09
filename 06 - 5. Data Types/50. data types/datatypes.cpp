// overview of data types
#include <cstdio>
using namespace std;

// -- Data Types --
// C++ is strongly typed language. This means that every value has a specific type.
// The meaning of a value is determined by its type.
// A data type determines both the size and the interpretation of a value.

// For example, the int type means a natural machine size signed integer value.
// -- int --
// 32 bits
// Signed integer value
// Range: -2,147,483,648 to 2,147,483,647

// And unsigned int means the same size integer with no bit reserved for sign.
// -- unsigned int --
// 32 bits
// Unsigned integer value
// Range: 0 to 4,294,967,295

// -- Fundamental Types --
// Fundamental types for C++ include
// -- Integer types -- for representing integer numerical values,
// -- Floating point types -- for representing real numerical values,
// and a
// -- Boolean type -- for representing true false values.
// C++ also provides literal values for true and false.

// -- Array --
int x[5] = {1, 2, 3, 4, 5};
// An array is a contiguous sequential set of objects of the same type.
// Arrays are very powerful, flexible, and have very low overhead.
// They're also the basis of C strings and the C++ SDL container classes.
// Although C++ has no fundamental string type, a null terminated array of characters
// is a special case called a C string, and it is treated as a string in many contexts.

// -- Structure --
struct s
{
public: // struct is public by default
    int a;
    float b;
    char c[25];
};
// A structure is a sequential set of objects of various types.
// A structure may contain scalers, arrays, and even other structures and classes.

// -- Class --
class c
{
private: // class is private by default
    int a;
    float b;
    char c[25];

public:
    int getvalue() const;
    void setvalue(int v);
};
// C++ classes are based on structures.
// Technically, a class is a structure that defaults to private membership.
// In practice, a class is a structure that contains function members as well as data members.

// -- Union types --
union u
{
    int a;
    float b;
    char c[25];
};
// A union is a set of overlapping object types.
// This allows a single compound object to hold objects of different types,
// at different times, overlapping the same space.

int main(int argc, char *argv)
{
    // -- Pointer types --
    int x = 5;
    int *px = &x;
    printf("x is %d\n", *px);
    // A pointer is a reference to an object of a given type.
    // A pointer itself typically holds the address of the object it points to.
    // Pointers are strongly typed in C++.
    // The type of a pointer is used as the type when it's de-referenced,
    // and is also used to determine the size of increments, decrements,
    // and arithmetic operations on the pointer.

    // -- Reference types --
    int y = 21;
    int &ry = y;
    printf("y is %d\n", ry);
    // A reference is like a pointer, but with different semantics.
    // The major distinctions between pointers and references are
    // that references are immutable, and once defined they cannot be changed to refer to a different object.
    // References are accessed as aliases without any syntactic indication that it's a reference,
    // and not directly a variable. This allows for silent side effects.

    // C++ provides a number of fundamental data types that may be used or extended for many purposes.
    puts("Data Types");
    return 0;
}