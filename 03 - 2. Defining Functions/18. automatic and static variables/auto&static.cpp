// using automatic and static variables
#include <cstdio>
using namespace std;

void func1()
{
    static int i = 5;
    printf("i is %d\n", i);
    i = 20;
    printf("i is %d\n", i);

    // first call:
    // prints 5
    // prints 20

    // second call
    // prints 20
    // prints 20
}

void func2()
{
    static int j = 5;
    printf("j is %d\n", ++j);
    j = 20;
    printf("j is %d\n", ++j);

    // first call:
    // prints 6
    // prints 21

    // second call
    // prints 22
    // prints 21
}

int main(int argc, char **argv)
{
    func1(); // first call
    func1(); // second call
    puts("");

    func2(); // first call
    func2(); // second call
    puts("");
    
    // Automatic storage is the default, there's no reason to declare it
    // Automatic storage is stored on the stack,
    // which is created fresh for each invocation of the function.
    // Because automatic storage is stored on the stack,
    // it is not suitable for large objects.
    // It's always good idea to avoid using automatic storage
    // for anything larger than a few scalar variables.

    // Static storage is not on the stack, and
    // so it's persistent for the life of the entire process.
    // So now the value is carried from one invocation to another.
    
    return 0;
}
