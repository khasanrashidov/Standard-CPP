// vectors
#include <iostream>
#include <vector> // vector library
#include <string> // although <iostream> has enough of it
using namespace std;

// A vector is a sequence container that
// supports random access to its elements.
// So, we can think of it like an object-oriented array
// with a bunch of extra cool features.
// Vectors are extremely flexible and powerful.
// The vector template is defined in the vector header file,
// which is included here on line three.

int main(int argc, char **argv)
{
    cout << "vector from intitializer list: " << endl;
    // initializing a vector
    // We declare it with the vector class,
    // and vector is a template class.
    // And so, inside the template parameter list
    // we have an "int" type.
    // And so, vector takes one type,
    // and it creates a container of elements of that type.
    // And we name it vi1, and we initialize it with 10 values,
    // one through 10, and this initializer list initialization,
    // being able to initialize a vector from an initializer list
    // like this, is actually a new feature (starting from) in C++ 11.
    // It is strongly recommended that we use it.
    // It's much more clear and simple than
    // the old way we had to initialize vectors,
    // which was from a C array. (And I'll show that as well.)
    vector<int> vi1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // size() method returns the number of elements in the vector.
    cout << "size: " << vi1.size() << endl;
    // The front() returns the actual element at the front, and
    cout << "front: " << vi1.front() << endl;
    // the back returns the element at the back.
    cout << "back: " << vi1.back() << endl;

    // Vectors, like most containers, have iterators,
    // and an iterator is a class that's actually
    // part of the container class itself.
    // It's linked to the container class itself,
    // and there's a "typedef" inside the container class
    // that defines this "iterator" type.
    // And so, the "iterator" type is actually a class itself.
    // And so, we get that with vector sub int.
    // And so, we use exactly the same declaration
    // as we do for our vector, and we follow it with two
    // colons and then iterator, and that gets the "typedef"
    // out of the class itself.
    // And so, that "iterator" can be used in most of
    // the same ways that we would use a pointer.

    // iterator
    vector<int>::iterator itbegin = vi1.begin();
    vector<int>::iterator itend = vi1.end();
    // And so, the begin() method returns an iterator
    // at the beginning of the container,
    // and the end() method returns an iterator
    // at the end of the container.
    // And so, we can use it just like we would
    // use a pointer in a for loop.
    // For example, here we're using "auto".
    // We could use the same long declaration here,
    // and it starts at begin, and while IT is less than end,
    // we increment IT, and we see that we get the value,
    // just as we would from a pointer in an array
    // with the pointed at operator.
    for (auto it = itbegin; it < itend; ++it) // or vector<int>::iterator it, instead of "auto"
    {
        cout << *it << ' ';
    }
    cout << endl;
    // So, most of the time, as we have "auto" type and we're not
    // going to want to type all of this every time, especially
    // if we have complicated STL containers of other STL containers.
    // That can get to be really long.
    // instead of following
    // vector<int>::iterator itbegin = vi1.begin();
    // vector<int>::iterator itend = vi1.end();
    // we use
    // auto itbegin =vi1.begin();
    // auto itend =vi1.end();

    // We dereference a vector the same way we would an array.
    // We can use the array subscript operator,-
    // or we can use the "at()" method,
    // and we see that both of these return the same thing.
    cout << "element at 5: " << vi1[5] << endl;
    cout << "element at 5: " << vi1.at(5) << endl; // const int & at(const size_t _Pos) const

    cout << "range-based for loop: " << endl;
    for (int &i : vi1)
    {
        cout << i << ' ';
    }
    cout << endl;

    cout << "insert 21 at begin + 5: " << endl;
    vi1.insert(vi1.begin() + 5, 21);
    // insert(std::vector<int>::const_iterator _Where, const int &_Val)
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;

    cout << "erase at begin + 5: " << endl;
    vi1.erase(vi1.begin() + 5);
    // erase(std::vector<int>::const_iterator _Where)
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;

    cout << "push_back 30: " << endl;
    vi1.push_back(30);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi1.back() << endl;

    cout << "range-based for loop: " << endl;
    for (int &v : vi1)
    {
        cout << v << ' ';
    }
    cout << endl
         << endl;

    cout << "pop_back: " << endl;
    vi1.pop_back();
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi1.back() << endl;

    cout << "range-based for loop: " << endl;
    for (int &v : vi1)
    {
        cout << v << ' ';
    }
    cout << endl
         << endl;

    // from C-array
    const static size_t size = 10;
    // Now, in the days before C++ 11, this is the way
    // that we would initialize a vector.
    // We would first create an array
    int ia[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "vector from C-array: " << endl;
    // and populate that array and then initialize the vector
    // with this constructor here that takes two pointers,
    // a pointer to the beginning of the array and
    // a pointer to the end of the array.
    // And so, we need that size of the array.
    // We could use a "sizeof" operator or
    // since we're initializing the array anyway,
    // we have a constant for the size of it,
    // because that's usually good practice.
    vector<int> vi2(ia, ia + size);
    for (int &i : vi2)
    {
        cout << i << ' ';
    }
    cout << endl
         << endl;

    // vector of strings
    // We can use any type in a vector,
    // and this is the string type here.
    // We include the string type library.
    // Enough of it is usually included in "iostream"
    // that this will probably work just fine without that,
    // but it's a good idea, when we're using a string class,
    // to include the string header.
    cout << "vector of strings: " << endl;
    vector<string> vs = {"one", "two", "three", "four", "five"}; // vector of strings
    for (string &v : vs)
    {
        cout << v << endl;
    }
    cout << endl;
    // We can use any type in a vector.
    // Our type could be a class.
    // Our type could be a fundamental type.
    // Any type we want to use in a vector
    // is going to work exactly the same way.

    // So, vectors are a fundamental container type
    // that's very powerful and easy to use.
    // We use it whenever we would
    // otherwise we use a C array
    // but we could benefit from some capabilites
    // that vector provides in its object-oriented interface.

    return 0;
}
