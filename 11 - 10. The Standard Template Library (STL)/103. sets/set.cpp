// sets
#include <iostream>
#include <string>
#include <set>
using namespace std;

// A set is an Associative Container
// which means that the elements are referenced
// by their value rather than by their
// location in the container.
// A set holds an ordered set of objects
// and it holds only unique objects
// where there's another version called
// "multiset" that allows duplicates.
// Set does not support random access
// and it uses a bidirectional iterator.

int main(int argc, char **argv)
{
    // Declaring a set of strings.
    set<string> strset = {"one", "two", "three", "four", "five"};
    cout << "size of set: " << strset.size() << endl; // size is five
    // "set" is alphabetical, when we access it through its iterator,
    // it comes out in alphabetical order, because set is ordered
    // using the comparison operators of the underlying class.
    cout << "ordered set is alphabetical:" << endl;
    for (string s : strset)
    {
        // And so the "string" sorts by alphabetical.
        cout << s << " ";
    }
    cout << endl
         << endl;

    // So, when we insert an element as we do here
    // with the element with the value of the "string"
    // six it puts it into the set in its alphabetical location.
    // And again it's using the comparison operators
    // in the underlying class and so that's
    // why it comes out alphabetical.
    // If we were using integers they would come out in integer order.
    cout << "insert element \"six\":" << endl;
    strset.insert("six");
    for (string s : strset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    cout << "find and erase element \"six\":" << endl;
    // Now because the set is associative, it has a "find()" method
    // which allows us to find a particular element and it'll
    // return an iterator pointing to that element.
    set<string>::iterator it = strset.find("six"); // const_iterator find(const std::string &_Keyval) const
    // And so, here we're finding the element "six"
    // and if "find()" fails it'll return end().
    // So, we're checking to see if it failed and
    // if it did not fail then we'll go ahead and
    // we'll erase the six and if it did fail then
    // we'll just print out a message that says "Not Found".
    if (it != strset.end())
    {
        cout << "erasing " << *it << endl; // And so, here it found it.
        strset.erase(it);
    }
    else
    {
        // If we were to misspell the element,
        // then it would not find it and we would see
        // that we ge the error message that says "Not Found".
        cout << "not found" << endl;
    }
    for (string s : strset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // Now if we try to insert a duplicate element
    // we can notice that it fails.
    // We did not get two fives here.
    cout << "insert duplicate element \"five\":" << endl;
    strset.insert("five");
    for (string s : strset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // If instead of using "set", if we use "multiset"
    // we do get a duplicate five.
    multiset<string> multistrset = {"one", "two", "three", "four", "five"};
    cout << "insert duplicate element \"five\":" << endl;
    multistrset.insert("five");
    for (string s : multistrset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;
    // So, now everything works exactly the same except that
    // the "multiset" allows duplicates where "set" does not.
    // Well, there actually is one difference.
    // And we're going to change that "multiset" back to "set" and we'll build and run.
    // And when we try to we can get an error from this.
    // The error is a pair so we're just gonna say "auto rp = insert()"
    // and then we're going to test and see if it failed.
    // The pair that is returned by "insert()" returns two elements in the pair.
    // "First" is an iterator pointing to either the newly inserted element
    // or an existing element if the insert failed due to duplicate.
    // The "second" is a "bool" which is true for success
    // and false for failure due to duplicate.
    // So, we can just say "if (rp.second)" and then we know it succeeded
    // and else for if it failed.
    // And we can just say "Input Succeeded" or "Input Failed".
    cout << "insert duplicate element \"five\":" << endl;
    auto rp = strset.insert("five");
    if (rp.second)
    {
        cout << "Input Succeeded" << endl;
    }
    else
    {
        cout << "Input Failed" << endl; // output is "Input Failed"
    }
    for (string s : strset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;
    // And if we try to insert, for example, a "seven"
    // then it'll say "Input Succeeded" and there we have a "seven".
    cout << "insert element \"seven\":" << endl;
    auto p = strset.insert("seven");
    if (p.second)
    {
        cout << "Input Succeeded" << endl;
    }
    else
    {
        cout << "Input Failed" << endl; // output is "Input Failed"
    }
    for (string s : strset)
    {
        cout << s << " ";
    }
    cout << endl
         << endl;

    // Now, the "multiset" version of "insert()" only returns an "iterator".
    // It does not return a "pair" because it's not going to fail
    // due to duplicates.

    // So, "sets" are really useful in cases where
    // we need an ordered set of objects
    // that we can search but we don't need random access.
    // And we'll use "multiset" if we need to have
    // duplicates in our set.

    return 0;
}