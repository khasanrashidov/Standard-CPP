// namespaces
#include <cstdio>
#include <string>
// "using namespace std;" allows us to use classes and
// objects from the standard namespace in our code.

// As we begin to create lots of classes and objects,
// the possibility of name inclusions increases.
// Namespaces in C++ are a great tool for managing this.
// Typically, namespaces are defined in header files with the class definitions that use them.

namespace mystring
{
    const std::string prefix = "(mystring)";
    // const std::string prefix("(mystring)");

    class string
    {
        std::string _s = "";
        // A private constructor does not allow to create an object outside the class.
        // If all the constant methods are there in our class we can use a private constructor
        string();

    public:
        string(const std::string &s) : _s(prefix + s){};
        const char *c_str() { return _s.c_str(); }
        operator const std::string &() { return _s; };
    }; // class string

}; // namespace mystring

//////////////////////////////
using namespace mystring;
// or (both of them work fine)
using mystring::string;
//////////////////////////////

std::string s1("This is a string");

int main(int argc, char **argv)
{
    mystring::string s(s1);
    std::puts(s.c_str());

    std::string s2(s1);
    std::puts(s2.c_str());

    string s3(s1); // because we are using namespace mystring;
    std::puts(s3.c_str());
    return 0;
}
