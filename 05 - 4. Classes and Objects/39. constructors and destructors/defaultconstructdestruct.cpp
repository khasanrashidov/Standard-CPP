// constructors and destructors
#include <cstdio>
using namespace std;

// There are default implicit constructors and destructors
// that are included in the class by default.

// A constructor doesn't have a name of its own.
// It simply takes on the name of the class.

// a very simple class
class Class1
{
    int i = 0;

public:
    void setvalue(const int value) { i = value; }
    int getvalue() const { return i; }
};

// initializer

// assignment operator
// There is something called the rule of threes,
// it says that if we are overloading any of the implicit copy constructor,
// destructor or copy operator, that it is a good idea to overload all three of them,
// because we might run into problems if we do not.

int main(int argc, char **argv)
{
    int i = 5;
    Class1 object1;

    object1.setvalue(i);
    printf("value is %d\n", object1.getvalue());
    return 0;
}