// deque
#include <iostream>
#include <deque>
#include <string>
using namespace std;

// "Deque" stands for "double-ended queue",
// and so it's spelled like that,
// but it's typically pronounced deck.

int main(int argc, char **argv)
{
    // And so, this is a double-ended queue.
    deque<string> dqs;
    // And so, we can push onto the back,
    // we can push onto the front,
    // and we can pop from the front,
    // and we can pop from the back.
    cout << "push_back values: " << endl;
    // And so, here we're just pushing all of these elements from the back.
    // And so, they're coming out in order. (front is "one", and back is "ten")
    dqs.push_back("one");
    dqs.push_back("two");
    dqs.push_back("three");
    dqs.push_back("four");
    dqs.push_back("five");
    dqs.push_back("six");
    dqs.push_back("seven");
    dqs.push_back("eight");
    dqs.push_back("nine");
    dqs.push_back("ten");

    cout << "size: " << dqs.size() << endl;
    cout << "front: " << dqs.front() << endl;
    cout << "back: " << dqs.back() << endl;
    cout << "the value at 5th position: " << dqs[5] << endl;
    cout << "the value at 5th position: " << dqs.at(5) << endl;

    // access deque with iterator
    // We can access them with an iterator like that.
    for (string s : dqs)
        cout << s << ' ';
    cout << endl;

    cout << "pop from front:" << endl;
    dqs.pop_front();
    for (string s : dqs)
        cout << s << ' ';
    cout << endl;

    cout << "pop from back:" << endl;
    dqs.pop_back();
    for (string s : dqs)
        cout << s << ' ';
    cout << endl;

    cout << "push_front:" << endl;
    dqs.push_front("newfront");
    for (string s : dqs)
        cout << s << ' ';
    cout << endl;

    cout << "push_back:" << endl;
    dqs.push_back("newback");
    for (string s : dqs)
        cout << s << ' ';
    cout << endl;

    // And so, we can push and pop from both ends
    // of a double-ended queue or a "deque".

    // So, the STL "stack" and "queue" classes are container adapters.
    // They take an underlying container,
    // and they adapt it to "last-in, first out" or "first-in, first-out" queue.
    // They default container that they'll use,
    // if we don't specify one, is actually the "deque" queue,
    // and that'll be used as a default container,
    // if we don't specify one for "stack" and "queue".
    // The "deque" class is a complete double-ended queue
    // with random access iterator, and it's useful for many needs,
    // where a LIFO or a FIFO queue is not enough.

    return 0;
}