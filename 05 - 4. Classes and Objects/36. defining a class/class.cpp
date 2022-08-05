// defining a class
#include <cstdio>
using namespace std;

// a very simple class
class Class1
{
private:
    int i;
    int foo() { return i = 2; }

public:
    // declaration
    void setvalue(const int value);
    int getvalue() const;

    int callfoo() { return foo(); }
};

// Normally, it is the best practice to separate interface and implementation;
// declaration is inside the class and the implementation is outside of the class.

// implementation
void Class1::setvalue(const int value) { i = value; }
int Class1::getvalue() const { return i; }

int main(int argc, char **argv)
{
    int i = 5;
    Class1 object1;

    object1.setvalue(i);
    printf("value is %d\n", object1.getvalue());
    printf("value is %d\n", object1.callfoo());
    return 0;
}
