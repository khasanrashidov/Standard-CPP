// type inference
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Beginning with C++11 the auto keyword
// was repurposed to provide type inference.

// So here we have a template function, and there's
// a couple of things here that we haven't seen before.
// The template keyword followed by the template argument list,
// which defines two types in this case:
// a left-hand side type and a right-hand side type.
// So, it's allowing both of these arguments,
// left-hand side and right-hand side, to be of different types.
// And the return type needs to be derived from whatever
// the result is when these two types are added together.
// So, in the case of most objects, or most class types,
// this plus sign will be overloaded and it will work in different ways
// depending on which arguments are which.
// And so in a normal template definition
// there would be no way for the compiler to know what this
// return type is by the time it gets to that keyword auto.
// And so that's what decltype is for.
// So we see this -> (dash followed by right anlge bracket),
// and that's after the normal function signature,
// and that's called a trailing return type.
// This is also new in C++11.
// It's necessary because of how templates are parsed.
// When the compiler encounters the normal leading return type,
// in this case the auto keyword, it doesn't yet have enough information
// to determine what that type may be. In this case it hasn't even seen the
// left-hand side and right-hand side parameters
// so it doesn't know what type they are.
// And even if it knew what type they were, it wouldn't know what
// type to return because it doesn't know what's going to happen in the function.
// And so this is where "decltype" comes in.
// We take "decltype" and we pass it an expression,
// and it already knows what these types are
// because the compiler compiles in order.
// And this gives it an opportunity to gather
// that sufficient information to derive the return type
// without having to make a second pass over the function signature
// which actually is quite expensive for a compiler to do
// in terms of processing time and resources.
// And so with the trailing return type
// it now has enough of that information.
// It can use "decltype" and an expression
// to derive the return type and then whatever goes in "auto",
// which is really just a placeholder here, can then be determined.
// So let's see this in action, because this is actually pretty cool.
// This is something that we couldn't do before C++11 and this may not
// actually work on some compilers (of that time, because a lot of compilers
// were still implementing all of these features from C++11).
template <typename lhsT, typename rhsT>
auto tf(lhsT &lhs, rhsT &rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}

int main(int argc, char **argv)
{
    int i = 47;                                     // integer
    const char *cstr = "this is a c-string";        // c string
    string strobj("this is a string class string"); // string object, the Standard Library string type

    // Using the "auto" keyword type to declare a variable x of the string type.
    auto x = string("this is a string class string");
    decltype(x) y; // decltype

    // Reporting the typeid name of each of these objects.
    // And this is very implementation dependent,
    // so most of these will probably look different
    // on different compilers and different operating systems, and that's ok.
    // The "typeid" is really meant to be compared, not to have the name used,
    // but here we're using the name just to show that they're different.
    cout << "type of i is " << typeid(i).name() << endl;
    cout << "type of cstr is " << typeid(cstr).name() << endl;
    cout << "type of strobj is " << typeid(strobj).name() << endl;
    cout << "type of x is " << typeid(x).name() << endl;
    cout << "type of y is " << typeid(y).name() << endl;
    // And so output is the
    // 1) integer,
    // 2) pointer to constant character, so that's constant character string
    // and then
    // 3) string type has the long name, which is sometimes called basic_string.
    // So those are the types of the different objects.
    // 4) Now, we can notice that x is also a string,
    // it's the same as string object.

    // 5) And we can notice that y is also a C++ string class.
    // And this is how it's declared, with this "decltype".
    // This is new also in C++11.
    // The "decltype" keyword provides a type declaration
    // based on the type of an expression.
    // So, in this case the expression is x,
    // which we know is a string type,
    // and so whatever that expression returns
    // becomes the type that can then be applied to a new object,
    // in this case we're just declaring a simple object called y,
    // and we see that the type of y is exactly the same as the type of x.
    // Okay, so that looks cool, but what's it really useful for?
    // And this is where we get to something really cool.
    // So we're going to create template function outside the main function above.
    //
    // So we're going to declare a variable here
    // and give it auto type and call it "z",
    // and it will be the return type of tf.
    // Now, we're not using a template argument list here
    // to give it the types, we're letting it infer them.
    // Normally, we've said this before,
    // we would always use a template parameter list,
    // but in this case we want it to infer them
    // just to demonstrate how this works.
    // So, we're going to give it our cstr and our strobj
    // and then we'll see what the type is, so type of z.
    auto z = tf(cstr, strobj);
    cout << "z is " << z << endl;
    cout << "type of z is " << typeid(z).name() << endl;
    // And when we build and run we see that z is the concatenation
    // of those two strings.
    // This is a c-string and this is a string class string.
    // So those are concatenated without any space in between
    // and the type is the basic string class.
    // So that's the C++ Standard Library string class.
    // Now even though these two arguments are of different types
    // what it did is it took this expression of the c-string
    // plus the string class and it operated on it with
    // the overloaded operator to see what that type is, and
    // it derived that type and set the return type as a string class.
    // So even if we turn these arguments around it still works and
    // we still get that same result.
    auto z2 = tf(strobj, cstr);
    cout << "z2 is " << z2 << endl;
    cout << "type of z2 is " << typeid(z2).name() << endl;

    // So, that's what "decltype" is really used for.
    // Most often we'll just see it used in a "trailing return type"
    // in a template function.

    // So, the decltype keyword allows type inference
    // for template function return types.
    // This is essential for generic programming,
    // and it's actually used quite a bit in the Standard Template Library.

    return 0;
}