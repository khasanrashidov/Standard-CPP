// overloading operators with functions
#include <cstdio>
using namespace std;

class A
{
    int a;

public:
    A(const int &a) : a(a) {}
    const int &value() const { return a; }
};

int operator+(const A &lhs, const A &rhs)
{
    puts("operator + for class A");
    return lhs.value() + rhs.value();
}

int main(int argc, char **argv)
{
    A a(5);
    A b(20);
    printf("add them up! %d\n", a + b);
    return 0;
}