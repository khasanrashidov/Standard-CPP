// returning values from a function
#include <cstdio>
#include <string>
using namespace std;

const int func(int, int);

// If we want to return something larger,
// we better use static storage space and a reference
const string &fs() // fs - function string
{
    static string s = "This is a static string.";
    return s;
}

int main(int argc, char **argv)
{
    puts("this is main()");
    printf("returned value is %d\n", func(5, 7));

    // c_str() - because <string> is a C++ string class and not a C string,
    // we are just de-referencing it and using the C string method,
    // so that we get a C string so that we can display it.
    printf("returned value: %s\n", fs().c_str());

    puts("");
    return 0;
}

const int func(int i, int j)
{
    puts("this is func()");
    return i * j;
}
