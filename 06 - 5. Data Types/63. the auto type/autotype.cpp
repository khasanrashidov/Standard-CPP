// the auto type
#include <cstdio>
#include <string>
#include <typeinfo>
#include <vector>
using namespace std;

// The auto type is extremely handy.

string func()
{
    return string("this is  a string");
}

int main(int argc, char **argv)
{
    // We are declaring a variable as "auto", and
    // we are assigning to it the "return" value from "string" function.
    // And what that means is that this variable is actually going to be of type "string",
    // because the compiler knows that this function is a string,
    // returns a "string" type, and so it can automatically fill this in,
    // and that's what that's for.
    auto x = func();

    printf("x is %s\n", x.c_str());
    printf("type of x is %s\n", typeid(x).name());
    puts("");

    // We need to keep in mind that the "auto" type above is still strongly "type".
    // That "x" above is still of the type "string", and everything that that means still applies.
    // The only thing different here is that it's derived automatically by the compliler.
    // All the other rules of usage still apply.

    vector<int> vi = {1, 2, 3, 4, 5}; // vi stands for "vector int"
    // "for" loop to iterate through this vector of "int"
    // declaring an iterator inside "for loop", like this: "vector<type>::iterator varname"
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it)
    {
        printf("int has value %d in the hex address %p or %d in dec address\n", *it, it, it);
    }
    puts("");

    // Now, this "vector<int>::iterator" above is really a little bit cumbersome.
    for (auto iter = vi.begin(); iter != vi.end(); ++iter)
    {
        printf("int is %d\n", *iter);
    }
    puts("");
    // Declared above auto type works because the compiler
    // knows what type "vi.begin" returns, and
    // "vi.begin" returns that iterator type.
    // And this is where "auto" is really, really handy.
    // "Auto" is a whole lot easier to type without error,
    // and easier to remember, than the long and cumbersome
    // "vector" iterator, especially if it's a vector of something
    // more complicated than just an "int".
    // It can be a vector of other vectors, it could be all kinds of stuff.
    // This could be a very, very long thing.
    // Ando so, instead, to be able to just type "auto",
    // is actually pretty awesome.
    // In fact, an even easier way to do this using the new range-based "for loop" in C++,
    // is to simply say "auto i: vi", and print out "i", here and get that same result.
    // Now, that's a whole lot easier than what we were doing before.
    // It's clear, it's readable, and it's much less prone to error both in typing and in reading.
    for (auto i : vi)
    {
        printf("int is %d\n", i);
    }
    // This feature is great and it's not without its dangers.
    // We need to be careful to only use "auto" types where the implications are clear,
    // and the usage is concise. Otherwise, we could potentially sacrifice readability,
    // and even introduce errors that could be hard to find.

    puts("");
    return 0;
}