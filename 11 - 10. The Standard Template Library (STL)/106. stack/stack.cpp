// stack
#include <iostream>
#include <stack>
#include <string>
#include <list>
using namespace std;

// A stack is what's called a container adapter,
// and it does not have iterators.
// If we need iterators, we want to use the container type directly.

int main(int argc, char **argv)
{
    // What a container adapter does is, it takes another container,
    // and it adapts it for a particular use.
    // And so, in this case we notice that we start with a "list" container,
    // and then we initialize the "stack" from that "list".
    // So, "stack" is a container adapter,
    // and it's adapting that "list" to its own uses.
    cout << "initialize stack from list:" << endl;
    list<int> li = {1, 2, 3, 4, 5}; // a list of integers
    // stack of integers from the list
    stack<int, list<int>> si(li); // constructor copies to new list
    // "list" has a size, and "stack" has a size
    // and they're exactly the same
    cout << "li has " << li.size() << " entries; si has " << si.size() << " entries." << endl;

    // And now when we pop everything from si,
    // li still has all five of its entries, and si has none,
    // because si is actually making a copy of the list.
    // It's not using the list directly.
    // So, when we pop the items from the stack container,
    // the "pop()" method doesn't actually return the value.
    // The value is returned from the "top()" method before,
    // and so, if we want to actually see the things that we're
    // popping from it, we can use "top()" to access that
    // element before we pop it, which is what we're doing here.
    cout << "pop all from si:" << endl;
    while (!si.empty())
    {
        cout << si.top() << " ";
        si.pop();
    }
    cout << endl;

    cout << "li has " << li.size() << " entries; si has " << si.size() << " entries." << endl;
    // And we notice that our list still has all of its entries
    // after the stack has been emptied,
    // because it initialized if from a list.
    cout << "contents of li after si is emptied:" << endl;
    for (int i : li)
        cout << i << " ";
    cout << endl;

    // We can also use the default stack,
    // which actually uses the deque object.
    // default container, stack of strings
    stack<string> ss; // default stack uses deque object
    cout << "push strings onto ss:" << endl;
    // We add things to the stack by pushing elements on one by one.
    ss.push("one");
    ss.push("two");
    ss.push("three");
    ss.push("four");
    ss.push("five");
    // And so, here we pushed five elements onto ss, and our size is five.
    cout << "size of ss: " << ss.size() << endl;
    cout << "pop all from ss:" << endl;
    // And then we popped the elements, accessing them with top first.
    // And we notice that they come out in the opposite order that they go in.
    // That's because the stack is a last-in, first-out, or LIFO type of a queue.
    while (!ss.empty())
    {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << endl;
    cout << "size of ss: " << ss.size() << endl;
    // So, that's the stack object.

    return 0;
}