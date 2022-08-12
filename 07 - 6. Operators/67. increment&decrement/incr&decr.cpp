// increment and decrement operators
#include <cstdio>
using namespace std;

class num
{
private:
    int value = 0;

public:
    num() {}
    num(int x) : value(x) {}
    int getvalue() const { return value; }
    int setvalue(int x) { return value = x; }
    num &operator++();
    num operator++(int);
    num &operator--();
    num operator--(int);
};

// Here below we have incremented increment and increment operators.
// pre-increment
num &num::operator++()
{
    puts("pre-increment");
    value += 1;
    return *this;
}

// post-increment
// Now, we can notice that the only difference here is that word "int" is
// inside of the post-increment operator. That's just to distinguish it
// from the pre-increment operator because otherwise,
// we'd just have two pluses here and we need a way to distinguish them.
num num::operator++(int)
{
    puts("post-increment");
    num temp = *this;
    ++(*this);
    return temp;
}

// pre-decrement
num &num::operator--()
{
    puts("pre-decrement");
    value -= 1;
    return *this;
}

num num::operator--(int)
{
    puts("post-increment");
    num temp = *this;
    --(*this);
    return temp;
}

// We can notice the difference in how they are implemented.
// The pre-increment simply takes the value, adds one to it, and returns a reference to itself.
// The post-increment can't work that way because it actually needs to return the value
// before the increment. So it needs to create a temporary object.
// And it uses an assignment operator to copy the object over. And it increments itself.
// And then it returns the temporary object. Because it's a temporary object,
// it cannot return a reference. So it needs to, again, copy that object
// when it's assigned to something else. So we have two copy operations
// and a constructor and a destructor, all added to this, which don't exist in the pre-increment.
// Clearly, the pre-increment is far more efficient.

int main(int argc, char **argv)
{
    num n(5);
    num m(20);

    printf("value is %d\n", (++n).getvalue());
    printf("value is %d\n", n.getvalue());

    puts("");

    printf("value is %d\n", (m++).getvalue());
    printf("value is %d\n", m.getvalue());

    // The unary increment and decrement operators are very useful and very commonly used.
    // We need to keep in mind that the prefix version increments before returning the value,
    // and the postfix version increments after returning the value,
    // and that the prefix version is far more efficient.

    return 0;
}