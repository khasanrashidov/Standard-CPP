// passing values to a function
#include <cstdio>
#include <string>
using namespace std;

void func1(const string &fs) // fs - function string
{
    printf("string in func1(): %s\n", fs.c_str());
}

void func2(const string *fs) // fs - function string
{
    printf("string in func2(): %s\n", fs->c_str()); // -> is a pointer dereference
}

int main(int argc, char **argv)
{
    // readonly string i.e. immutable string
    string s = "Hello, this is a string";
    func1(s);
    func2(&s);
    printf("string in main(): %s\n", s.c_str());

    return 0;
}