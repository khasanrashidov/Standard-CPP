// stacks and queues
#include <iostream>
using namespace std;

// The STL provides three distinct types of queues.
// -- stack object (LIFO) --
// The stack object (LIFO) provides a "last-in, first-out"
// or LIFO queue, where we "push" and "pop" items
// from the same side of the queue, and items
// are removed in the reverse order from which
// they were inserted.
// -- queue object (FIFO) --
// The queue object (FIFO) provides a "first-in, first-out"
// or FIFO queue, where we "push" and "pop" from opposite sides
// of the queue, and items are removed in the same order
// in which they were inserted.
// -- deque object --
// The double-ended queue object, pronounced deck,
// can push and pop from either side, allowing us
// to control the order in which items are inserted and removed.

int main(int argc, char **argv)
{
    cout << "stack, queue, deque" << endl;
    return 0;
}