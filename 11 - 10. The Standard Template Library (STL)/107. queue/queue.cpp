// queue
#include <iostream>
#include <queue>
#include <list>
using namespace std;

// And so, "queue" is a "first-in, first-out", or FIFO queue.
// It's also a container adapter, and so same thing applies. (like stack)

int main(int argc, char **argv)
{
    cout << "initialize queue from list:" << endl;
    // We can initialize it from a list like here,
    // or we can use the default queue.
    // And so, this works exactly like the stack,
    // except that it pops the elements in the reverse order.
    // Well, actually, it pops them from the end of the queue.
    // So, they come out in the same order that they go in.
    // And so, in this case we can notice when we call "pop()",
    // we're getting the elements in the same order
    // that they were in the list.
    list<int> li = {1, 2, 3, 4, 5};
    queue<int, list<int>> qi(li); // constructor copies to new list

    cout << "li has " << li.size() << " entries; qi has " << qi.size() << " entries." << endl;

    cout << "pop all from qi:" << endl;
    while (!qi.empty())
    {
        // cout << qi.back() << " "; // the queue back will be the same
        cout << qi.front() << " ";
        qi.pop();
    }
    cout << endl;

    cout << "li has " << li.size() << " entries; qi has " << qi.size() << " entries." << endl;

    cout << "contents of li after qi is emptied:" << endl;
    for (int i : li)
        cout << i << ' ';
    cout << endl;

    // default queue
    queue<string> qs;
    cout << "push strings onto qs:" << endl;
    // And when we use the "string" version,
    // we push one, two, three, four, five,
    // and they come out one, two, three, four, five,
    // in the same order that we put them in.
    qs.push("one");
    qs.push("two");
    qs.push("three");
    qs.push("four");
    qs.push("five");
    cout << "size of qs: " << qs.size() << endl;

    cout << "pop all from qs:" << endl;
    while (!qs.empty())
    {
        cout << qs.front() << " ";
        qs.pop();
    }
    cout << endl;
    cout << "size of qs:" << qs.size() << endl;
    // Other than that, this works exactly the same as the stack.

    return 0;
}