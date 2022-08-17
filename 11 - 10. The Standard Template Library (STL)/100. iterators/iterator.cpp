// iterators, different types of iterators
#include <iostream>
#include <vector>
using namespace std;

// In the STL, iterators or a generalization of pointers
// that allow access to STL containers with a consistent interface.
// There are five types of iterators.
// Some classes don't support all of the different types.

// This demonstration uses a vector type
// which supports all five types of iterators
// for demonstration purposes.
// 1) input iterator
// 2) output iterator
// 3) forward iterator
// 4) bidirectional iterator
// 5) random access iterator

int main(int argc, char **argv)
{
    // vector of int
    vector<int> vi1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Declaring a variable of type iterator from the vector above.
    vector<int>::iterator it; // vector iterator

    // input iterator
    // The input iterator allows reading
    // from the iterator object without
    // multi-pass guarantee.
    // That is, re-reading an object is not guaranteed
    // to produce the same result,
    // but in essence what the input iterator does
    // it allows us to read from the object.
    cout << "input iterator: " << endl;
    for (it = vi1.begin(); it < vi1.end(); ++it)
    {
        // It's just as if we were reading from a pointer.
        // So, the * and our iterator variable will return
        // the object at that point in the container.
        // At the point that the iterator is pointing to.
        cout << *it << " ";
        // printf("address is %p (%d)\n", it, it); // to print out the address
        // And we have the result exactly what we would expect
        // if this were a fundamental container,
        // like an array.
    }
    cout << endl;
    // So, the whole idea of the iterator is it allows us to
    // access all of these different containers types
    // as if they were made of fundamental type in C++.

    // save start and end points
    // Initializing from vi1.begin() and vi1.end().
    // This is something that we can do
    // if we're not inserting and deleting
    // objects from a container.
    // Once we start inserting and deleting objects
    // from a container our saved iterators
    // are no longer going to be valid,
    // so we need to be aware of that.
    // We're not doing that here,
    // so this just makes the rest of this easy.
    vector<int>::iterator start = vi1.begin();
    vector<int>::iterator end = vi1.end();

    // output iterator
    // So, now we're going to look at the output iterator.
    // And output iterator allows writing to the iterator object.
    // In other words, it allows writing to the container
    // that the iterator object is pointing to.
    // It may iterate forward without multi-pass guarantee.
    // So, it's just like the input iterator
    // only it allows writing instead of reading.
    // And so, in this case, we're doing exactly
    // the same type of loop.
    // We're demonstrating writing to the object
    // by incrementing what is pointed at by our iterator.
    // And so, this requires the () around the *it,
    // in order to have the pre-increment
    // and the pre-decrement.
    // For each pass through the loop,
    // we increment it and print it out.
    // And then we decrement it, so that
    // it's reset to the way that it was before.
    // And so we see the output iterator,
    // instead of 1 through 10, it's 2 through 11.
    // So, we actually changed the values
    // that were pointed at by the iterator.
    cout << "output iterator:" << endl;
    for (it = start; it < end; it++)
    {
        cout << ++(*it) << " ";
        --(*it);
    }
    cout << endl;

    // forward iterator allows re-iteration of same set with same results
    // The forward iterator allows reading from and writing
    // to the iterator object with multi-pass guarantee.
    // That means that re-reading an object is guaranteed to
    // produce exactly the same result.
    // And so we're demonstrating it by reading the object
    // twice with exactly the same result.
    cout << "forward iterator:" << endl;
    for (it = start; it < end; ++it)
    {
        cout << *it << " ";
    }
    for (it = start; it < end; ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // bidirectional iterator -- iterate forward or backward
    // allows it--
    // And bi-directional iterator allows
    // reading from the iterator object
    // both forward and backwards with multi-pass guarantee.
    // We want to notice here that the "end" iterator
    // points past the last object of the container,
    // (By past the last element it is meant that 
    // the iterator returned by the end() function 
    // return an iterator to an element 
    // which follows the last element in the list container. 
    // It can not be used to modify the element or the list container.)
    // so at the beginning of our "for loop",
    // we have to start at "end - 1" and go through
    // "greater than or equal" (>=) start.
    cout << "bidirectional iterator:" << endl;
    for (it = end - 1; it >= start; --it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // random access iterator
    //  allows += and -= access
    // Random access iterator allows reading from the iterator object
    // randomly with multi-pass guarantee.
    // And it also overloads the array sub script operator [],
    // so we're able to access with an iterator + or -
    // a given offset or using the sub script operator [].
    cout << "random access iterator:" << endl;
    it = start + 7;
    cout << *it << " ";
    it -= 3;
    cout << *it << " ";
    it += 4;
    cout << *it << " ";
    cout << vi1[5] << " ";
    cout << endl;

    // STL iterators allow us to iterate through
    // a number of different types of container
    // with a common interface.
    // Not all containers support all types of iterators,
    // in fact not all containers even support
    // iterators at all.
    // The documentation for each container type
    // will tell us which type of iterators it supports.

    return 0;
}
