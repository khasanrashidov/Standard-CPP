// pointing to the current object with _this
#include <cstdio>
using namespace std;

// Object member functions in C++ make use of a keyword "this"
// to provide a pointer to the current object.

// a very simple class
class Class1
{
    int i = 0;

public:
    void setvalue(const int value) { i = value; }
    int getvalue() const;
};

int Class1::getvalue() const
{
    // The "this" pointer is giving us inside of a function member.
    // It is giving the address of the current object.
    printf("getvalue(): this is %p\n", this); // %p for addresses
    return i;
}

int main(int argc, char **argv)
{
    int i = 5;
    Class1 object1;
    Class1 object2;

    object1.setvalue(i);
    object2.setvalue(i);

    printf("value is %d\n", object1.getvalue());
    printf("address of object1 is %p\n", &object1); // %p for addresses
    // We use ampersand (&) to get the address of the object.
    printf("value is %d\n", object2.getvalue());
    printf("address of object2 is %p\n", &object2); // %p for addresses

    return 0;
}
