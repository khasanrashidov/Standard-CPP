// function members
#include <cstdio>
using namespace std;

class A
{
private:
    int ia;

public:
    void setvalue(const int a);
    int getvalue() const;
    int getvalue();
};

// It is considered best practice to separate the interface from the implementation.

// The setter is not const safe and it can't be because it actually changes a value.
void A::setvalue(const int a)
{
    // Read-only memory is not assignable.
    ia = a;
}

// Any method that's called on a const object must be const safe.
// A const safe method cannot modify any of its data members.
int A::getvalue() const // Getter should be const safe if declared object is const.
{
    puts("immutable const getter");
    return ia;
}

// On the other hand, the getter can be used
// either with the const or the non const version of get value.
// The really interesting thing, we can have two versions of getvalue.
// One of them const safe and one of them not const safe.

int A::getvalue()
{
    puts("mutable getter");
    return ia;
}

int main(int argc, char **argv)
{
    A a;
    const A b = a;
    a.setvalue(20);
    printf("value is %d\n", a.getvalue());
    printf("value is %d\n", b.getvalue());
    return 0;
}