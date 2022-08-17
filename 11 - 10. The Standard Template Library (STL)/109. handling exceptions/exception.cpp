// handling exceptions
#include <iostream>
#include <exception>
using namespace std;

// The standard exception class is specifically designed
// to declare object to be thrown as exceptions.
// The exception class has a virtual function called "what"
// that returns a C string. And this function can be overloaded
// in derived classes to provide a description of our exception.

// We're going to inherit from the standard exception class.
class E : public exception
{
private:
    // And we're gonna have a place for a message.
    const char *msg;
    // And just one more thing we're gonna do here
    // is we're going to create a "private:" constructor
    // for the default constructor, so that this
    // class cannot be constructed without that string.
    E() {}

public:
    // And we're going to build a constructor
    // that allows us to pass a message.
    // So we can notice that we have
    // this "throw()" modifier here for our constructor.
    // That's used very rarely, but it's used in places
    // where we absolutely, positively know that
    // we're not going to be throwing an exception.
    // And this is one of those places.
    E(const char *s)
    throw() : msg(s) {}
    // All this constructor does is it copies this message over,
    // and we're gonna use it again for our "what" which
    // is overloading the virtual function
    // called "what" in the standard exception class.
    // And again, we have the "throw()" modifier.
    const char *what() const throw() { return msg; };
};

// We have a function called "broken",
// that does nothing but throw an exception.
// So, when we call that, we can notice that
// it just brings up the debugger and
// it gives us and error, and it all looks
// very, very catastrophic.
// And so, if we have an error condition
// inside one of our classes that we're writing,
// we probably don't want that to happen.
// So, I'm gonna show here how to catch an exception
// and how to create our own exception class.
void broken()
{
    cout << "this is broken function" << endl;
    throw exception();
}

// Alright, now we just want to throw
// one of our clever little exceptions instead.
void brokentoo()
{
    cout << "this is broken function" << endl;
    throw E("this function is broken");
}

// exception constants
// But we can call these whatever we want.
// These can be our standard errors
// for the classes that we write.
// Those all look like really useful error messages.

const E e_ouch("ouch!");
const E e_bad("bad code!");
const E e_worse("don't do that!");
void sobroken()
{
    cout << "this is broken function" << endl;
    // And so now, instead of throwing "E"
    // we can throw exception constants.
    throw e_ouch; // Now it says "ouch!".
}

int main(int argc, char **argv)
{
    cout << "let's have an emergency!" << endl;
    // So, first of all we want to catch this exception,
    // and so, instead of calling "broken()" directly
    // broken();
    // we're gonna call it from inside of a try loop.
    try
    {
        broken();
    }
    // We're going to catch the standard exception class
    // because that's what we're throwing.
    catch (const std::exception &e) // or just catch (exception &e)
    {
        cout << "this can't be good: " << e.what() << endl;
    }
    // And so now, when we build and run,
    // instead of bringing up our debugger and everything,
    // we get a nice useful message.
    // Well, the message isn't that useful because
    // we're using the standard exception class.
    // If we want a useful message, we're going to
    // have to write our exception class.
    // Which is actually really, really easy to do
    // because we can inherit from the standard exception class.

    try
    {
        brokentoo();
    }
    // And we'll need to catch that
    // instead of the standard exception.
    catch (E &e)
    {
        cout << "this can't be good: " << e.what() << endl;
    }
    // And now when we build and run
    // it says "this can't be good: this function is broken".
    // And so it passed the message, "this function is broken",
    // to the exception, and when we catch it we can
    // get that through the "e.what()" method.
    // This is exactly what we want.
    // Now this is very convenient.
    // So now, we can have exceptions with error messages,
    // but it's not actually very scalable.
    // Because if we have a large system,
    // we could end up with a mess of different error messages.
    // So, instead, there's really easy solution to this.
    // We can actually define some constant
    // of our exception class that can then be passed as
    // thrown exceptions.
    try
    {
        sobroken();
    }
    catch (E &e)
    {
        cout << "this can't be good: " << e.what() << endl;
    }

    // So, C++ exceptions provide a simple and
    // effective way of handling errors, and
    // other exceptional circumstances at run time.
    // The standard exception class is well suited for deriving objects
    // that we can throw as exceptions for a variety of uses.

    return 0;
}
