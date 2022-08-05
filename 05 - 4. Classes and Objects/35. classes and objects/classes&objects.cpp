// overview of classes and objects
#include <cstdio>
using namespace std;

// In C++, classes are like custom data types.
// The definition of a class, using the 'class' keyword, is the class itself.
// We can then use the class to create an 'object'.
// The object is also called an 'instance' of a 'class'.
// 'Instantiating' - to describe the process of creating an object.
// 'Members' are the contents of an object.
// There are two types of members: 'Data members' and 'Function members'.
// 'Data members' are the members that represent encapsulated data.
// Data members are sometimes called 'properties'.
// 'Function members' are members that represent functions associated with class.
// Function members are sometimes called 'methods'.
// 'Constructors' and 'destuctors' are 'special function members'
// that are called when an object is 'created' or 'destroyed' respectively.
// A constructor is called when the object is created.
// There may be several constructors defined,
// but only one is called depending on how the object is created.
// The destructor is called when the object is destroyed.
// There may be one destructor to find.

class Class1
{
private: // access modifier
    // data members:
    int i;

public: // access modifier
    // function members:
    Class1();                 // constructor
    Class1(int value);        // constructor
    ~Class1();                // destructor
    void setValue(int value); // method
    int getValue();           // method
};

// Using C++ classes we may
// 1) "create constructors" for a variety of different types and numbers of parameters.
// 2) "allocate and deallocate memory" appropriately, so that our objects run smoothly.
// 3) "overload operators" so that our objects can use those operators intelligently.
// overload the function call operators, so that our objects can operate like a function.
// 4) "create conversion operators", so that our objects behave as we expect them to in different contexts.

int main(int argc, char **argv)
{
    Class1 object1;
    int i = 47;
    object1.setValue(i);
    printf("value: %d\n", object1.getValue());
    puts("Hello, World!");
    return 0;
}
