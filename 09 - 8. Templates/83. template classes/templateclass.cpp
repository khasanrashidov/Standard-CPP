// template classes
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Template classes are commonly used for operating on containers.

// This is a simple LIFO Stack, last in first out.
// There's more complete version in the standard template library.
// We've created this simple version so we can see how it works.

// simple exception class for error reporting
class E : public std::exception
{
public:
    explicit E(const char *s) throw() : msg(s) {}
    const char *what() const throw() { return msg; }

private:
    E(); // no default constructor
    const char *msg;
};

// template class - stack
// simple fixed-size LIFO stack template
// The important thing to notice about this
// is there's nothing in this that really cares about
// what type is being used with this stack.
template <typename T>
class Stack
{
private:
    static const int defaultSize = 10;
    static const int maxSize = 1000;
    int _size;
    int _top;
    T *stackPtr;

public:
    explicit Stack(int s = defaultSize);
    ~Stack() { delete[] stackPtr; }
    T &push(const T &);
    T &pop();
    bool isEmpty() const { return _top < 0; }
    bool isFull() const { return _top >= _size - 1; }
    int top() const { return _top; }
    int size() const { return _size; }
};

// Code that implements the stack itself.
// We can notice that we are using comparison operators
// and we return a stack pointer and a few things like that.
// Stack<T> constructor
// It uses the size which is an integer
// to initialize an array of whatever
// the type is that's being used in the template.
template <typename T>
Stack<T>::Stack(int s)
{
    if (s > maxSize || s < 1)
        throw E("invalid stack size");
    else
        _size = s;
    stackPtr = new T[_size];
    _top = -1;
}

template <typename T>
T &Stack<T>::push(const T &i)
{
    if (isFull())
        throw E("stack full");
    return stackPtr[++_top] = i;
}

template <typename T>
T &Stack<T>::pop()
{
    if (isEmpty())
        throw E("stack is empty");
    return stackPtr[_top--];
}

int main(int argc, char **argv)
{
    try
    {
        Stack<int> si(5); // initializing with the stack size of 5

        // We are using "cout" here because we're already using the STL
        // so we don't mind using "cout".

        // And so we look at the size of the stack.
        // We look at the top of the stack
        // which returns an index into the stack and
        // the stack is numbered zero through whatever
        // the size of the stack is.
        // So this is a stack of five so the top
        // of the stack will be four.
        cout << "si size: " << si.size() << endl;
        cout << "si top: " << si.top() << endl;
        // When we build and run the program, our stack size is five,
        // and the top is minus one, because it's zero based
        // we return a minus one if the stack is empty.

        // And then we use a range based four loop
        // to push five values on to the stack.
        for (int i : {1, 2, 3, 4, 5})
        {
            si.push(i);
        }

        // And then we look at the top after the pushes so that should say four.
        cout << "si top after pushes: " << si.top() << endl;
        // Indeed, after the pushes the top of the stack is four.

        // It should also say full.
        // It checks the "isFull" method which returns a boolean value
        // if the top of the stack is greater than or equal to the size minus one.
        cout << "si is " << (si.isFull() ? "" : "not ") << "full" << endl;

        // And then it pops the values off the stack and
        // it looks at those values while its popping them out.
        while (!si.isEmpty())
        {
            cout << "popped " << si.pop() << endl;
        }
    }
    catch (E &e)
    {
        cout << "Stack error: " << e.what() << endl;
    }

    puts("");

    // And we do the same thing with strings.
    try
    {
        Stack<string> ss(5);

        // Stack size is five,
        // top is minus one,
        // top after the pushes is four.
        // It's full, and popping five, four, three, two, one.

        cout << "ss size: " << ss.size() << endl;
        cout << "ss top: " << ss.top() << endl;

        for (const char *s : {"one", "two", "three", "four", "five"})
        {
            ss.push(s);
        }

        cout << "ss top after pushes: " << ss.top() << endl;
        cout << "ss is " << (ss.isFull() ? "" : "not ") << "full" << endl;

        while (!ss.isEmpty())
        {
            cout << "popped " << ss.pop() << endl;
        }
    }
    catch (E &e)
    {
        cout << "Stack error: " << e.what() << endl;
    }

    puts("");

    // And we can see that the same code is working with
    // both strings and integers, two entirely different types.
    // One of them is a fundamental type, the integers,
    // and the other is a class type out of the Standard Template Library,
    // the string library.
    // So this is possible because of templates.
    // We write this code once and we're able to use it with different types.
    // We can also notice that we're using exceptions for our error reporting.
    // That just makes the error reporting really simple.
    // We don't have to have a lot of logic around it.
    // And so if we try to push too many values on the stack
    // for example and we build and run, it will say "Stack Error, Stack Full"
    // and that error message is declared above in "push" method.
    // If we're trying to push past it already being full.
    // And we just check that "isFull" member function.
    try
    {
        // Stack error: stack full

        Stack<int> stackint(5);

        cout << "stackint size: " << stackint.size() << endl;
        cout << "stackint top: " << stackint.top() << endl;

        for (int i : {1, 2, 3, 4, 5, 6}) // Stack error: stack full
        {
            stackint.push(i);
        }

        cout << "stackint top after pushes: " << stackint.top() << endl;

        cout << "stackint is " << (stackint.isFull() ? "" : "not ") << "full" << endl;

        while (!stackint.isEmpty())
        {
            cout << "popped " << stackint.pop() << endl;
        }
    }
    catch (E &e)
    {
        cout << "Stack error: " << e.what() << endl; // Stack error: stack full
    }

    puts("");

    // So we see this makes the code very simple.
    // There's really nothing very complicated about this
    // and yet it's able to handle stacks with different types of values in the stack.

    // So template classes are especially useful for manipulating containers of items
    // where the logic of the manipulation is independent of the type.
    // That's why the C++ standard containers are written using templates.

    return 0;
}