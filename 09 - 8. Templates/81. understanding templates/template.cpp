// understanding templates
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

// -- Templates --
// C++ templates are marvelously simple and powerful.
// This is the feature that supports generic programming.
// Generic programming refers to code that works independent of type.
// While C++ is a strongly typed language,
// there is still great benefit in being able
// to write functions and classes that are "type-agnostic".
// That is, they operate on object without concern for the type of those objects.
// Because C++ supports defining own types through classes and operator overloading,
// it's possible to do a great deal of generic programming in templates while leaving
// implementation details to the classes and operators.
template <typename T>
T maxof(T a, T b)
{
    puts("went through template"); // just to check the difference vs function
    return (a > b ? a : b);
}

// -- Templates --
// Template declarations look just like normal function or class declarations with one
// distinction, they're preceded by the template keyword and a set of type identifiers.
// These type identifiers are used as placeholders by template code to be replaced during
// compilation with actual types.
template <typename T>
class A
{
    T a;

public:
    T getA() const { return a; }
    void setA(T &x) { a = x; }
};

// // // // // // // // // // // // // // // // // // // //
// -- Specialization --
// When a function or class is used from a template,
// the compiler generates a specialization of that function or class specifically suited to
// the types specified in the instantiation.
// // // // // // // // // // // // // // // // // // // //
// template <typename T>
// T maxof(T a, T b)
// {
//     return (a > b ? a : b);
// }
// // // // // // // // // // // // // // // // // // // //
// above template generates the following specialization:
// // // // // // // // // // // // // // // // // // // //
// int maxof(int a, int b)
// {
//     puts("used the function"); // just to check the difference between template and function
//     return (a > b ? a : b);
// }
// // // // // // // // // // // // // // // // // // // //

// -- Standard Template Library --
// Templates are widely used in the C++ Standard Library,
// which is why parts of the library are commonly called,
// the "Standard Template Library".
// The generic nature of template classes makes
// them a perfect fit for use with container classes.
// // // // // // // // // // // // // // // // // // // //
// vector<string> nums = {"one", "two", "three"};
// for (string s : nums)
// {
//     puts(s.c_str());
// }
// // // // // // // // // // // // // // // // // // // //

// -- Use Caution --
// Template programming is not entirely without its downsides.
// There are some issues we'll need to be aware of.
// 1) -- Larger executables --
// Because the compiler must generate specializations
// for every instantiation of a template,
// the amount of code to support that template can grow rapidly with use.
// 2) -- Confusing error messages --
// Compilers tend to have a difficult time
// generating sensible error messages with templates,
// so debugging can be challenging.
// 3) -- Longer compile times --
// Also, because templates tend to live in header files,
// changes to header files with templates can lead to recompilation
// of larger portions of our code than would otherwise be necessary.

int main(int argc, char **argv)
{
    int x = 5;
    int y = 10;
    int z = maxof(x, y);
    printf("the maxof value is %d\n", z);

    vector<string> nums = {"one", "two", "three"};
    for (string s : nums)
    {
        puts(s.c_str());
    }

    // -- Templates --
    // C++ templates are a very powerful feature.
    // It's also simple to implement and support.
    // They have great advantages over other generic programming solutions,
    // in particular, pre-processor macros.
    // And they're widely used to implement containers
    // and other generic objects in the C++ Standard Library.

    return 0;
}
