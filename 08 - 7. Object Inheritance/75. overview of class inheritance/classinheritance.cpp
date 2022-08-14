// overview of class inheritance
#include <cstdio>
using namespace std;

// Class inheritance represents the ability to reuse code
// by deriving a class from a base class.
// The derived class will typically inherit and build upon
// some or all of the data and function members of the base class.
// This is a fundamental and vital part of object-oriented programming (OOP).
// Some terminology:
// The base class is a class that has members
// that are to be used in one or more derived classes.
// Sometimes the base class is called the superclass or the parent class.
// A derived class is a class that's being created and is based upon a base class.
// Sometimes it's called a subclass or a child class.

// There are three different levels of member access.
// The access levels determine what other objects
// will be able to access class members.
// They are specified by the member access specifiers.
// Members given public access are available to all objects,
// those of the base class, derived classes, and other unrelated objects.
// Protected access members are available to members of the base class
// and any derived classes,
// while private access members are only available to the base class.

// Member Access Specifiers
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ||||||||||||| BASE CLASS | DERIVED CLASS | OTHER OBJECTS |||
// | PUBLIC    |++++++++++++|+++++++++++++++|+++++++++++++++|||
// | PROTECTED |++++++++++++|+++++++++++++++|---------------|||
// | PRIVATE   |++++++++++++|---------------|---------------|||
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// In addition to adding members to a class, a derived class
// may also overload members of its base class.
// Overloaded members are used for changing or customizining
// certain behaviors of the derived class.

// Class inheritance is an effective technique for reusing code
// by basing one class on another class and customizing
// behaviors to match usage.

// C++ provides complete support for class inheritance,
// including overloading methods, polymorphism,
// and multiple inheritance.

int main(int argc, char **argv)
{
    puts("Class Inheritance");
    return 0;
}