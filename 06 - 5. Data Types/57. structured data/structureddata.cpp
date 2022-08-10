// structured data
#include <cstdio>
using namespace std;

// The struct type provides a way to aggregate
// a fixed set of data members into a single object.
// In C++ the struct type is expanded to include function members.

// Here we are dealing with the struct type as an aggregate data type.
struct Employee // struct definition: struct name_of_the_structure
{
    // data members
    // order matters here
    int id;
    const char *name;
    const char *role;

    // This is really very similar to defining a class.
    // The difference is that the data members default to public rather than private.
};

int main(int argc, char **argv)
{
    // Here we declare the type, employee, and the name,
    // and we assign it values in an initializer list
    // in curly braces separated with commas.
    // The data member are initialized in the order that they're defined in the struct
    // and they're accessed using the access operator the dot,
    // just as with a class.
    Employee khasan = {2010223, "Khasan", "Student"}; // order matters here
    printf("%s is the %s and has ID U%d.\n", khasan.name, khasan.role, khasan.id);

    Employee *khasanptr = &khasan;
    // now we can access with the pointer access operator (->) as we would use with a class object
    printf("%s is the %s and has ID U%d.\n", khasanptr->name, khasanptr->role, khasanptr->id);

    // The ability to create data structures using struct is a fundamental tool in C++.
    // And it is also the basis of classes and objects.
    
    return 0;
}