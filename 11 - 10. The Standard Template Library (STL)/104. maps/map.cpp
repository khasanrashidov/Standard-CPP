// maps
#include <iostream>
#include <string>
#include <map>
using namespace std;

// The "strmap" class provides and ordered set
// of key value pairs like an associative or hashed array.
// The data in a map container is organized in pairs.
// The "first" is the "key" value and the "second" is the "mapped" value
// and the map is ordered by "key".

int main(int argc, char **argv)
{
    cout << "map of strings from initializer list:" << endl;
    // So, here we have a map of strings.
    // We're initializing if from the initializer list
    // and we can notice that our initializer list is nested.
    // That we're initializing both first and second,
    // the key and the value in each of these elements.
    // So, we have four elements and each of these
    // four elements has two elements.
    map<string, string> strmap = {{"David", "Father"}, {"Anna", "Mother"}, {"Rose", "Daughter"}, {"James", "Neighbor's Son"}};

    cout << "size is " << strmap.size() << endl;
    cout << "get some values:" << endl;
    // getting values using some different methods
    // We can access the values with the subscript operator [].
    cout << "David is " << strmap["David"] << endl;
    // We can use the "at()" method
    // which works exactly like the subscript operator [].
    cout << "Anna is " << strmap.at("Anna") << endl;
    // Or we can use the "find()" method
    // which actually returns the "pair".
    // And it actually returns rather an "iterator".
    // And that "iterator" accesses each element of the "map" as a "pair".
    // And so, we remember that "iterators" are accessed as
    // if they are "pointers" so we get that "second" through
    // the pointer dereference operator, the dash right angle bracket,
    // and we could also get "first" although we know
    // "first" because we're searching for "first".
    cout << "James is " << strmap.find("James")->second << endl;
    cout << endl;

    // And now, we'll loop through the map.
    cout << "loop through the map:" << endl;
    for (auto p : strmap)
    {
        // We get the output of all of these in alphabetical order
        // by the key: Anna, David, James, Rose.
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    cout << "insert an element:" << endl;
    // We can insert an element with insert
    // and again we can notice our curly braces
    // because we're inserting a "pair".
    strmap.insert({"John", "Neighbor"});
    // And now our size is 5.
    cout << "inserted - size is " << strmap.size() << endl;
    // And as we loop through we have five elements
    // and they're still in alphabetical order still.
    for (auto p : strmap)
    {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    cout << "insert a duplicate:" << endl;
    // If we try insert a duplicate, we can notice that the duplicate fails
    // because we're trying to insert something that's already there.
    auto rp = strmap.insert({"John", "Neighbor"});
    // And so, the insert returns a pair
    // and the "first" element is the "iterator"
    // to either the new element or the element that was matched
    // if it failed due to a duplicate, and the "second" is a "bool" for success,
    // and so, we can see that we're testing it in "if" condition.
    if (rp.second)
    {
        cout << "insert succeeded: " << rp.first->first << " is " << rp.first->second << endl;
    }
    else
    {
        cout << "insert failed" << endl;
    }
    cout << "after insert size is " << strmap.size() << endl;
    for (auto p : strmap)
    {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    // If instead, we try to insert one that's not there,
    // we can notice it will succeed and size will be 6.
    cout << "insert an element:" << endl;
    // If we try insert a duplicate, we can notice that the duplicate fails
    // because we're trying to insert something that's already there.
    auto pr = strmap.insert({"Amy", "Neighbor"});
    if (pr.second)
    {
        cout << "insert succeeded: " << pr.first->first << " is " << pr.first->second << endl;
    }
    else
    {
        cout << "insert failed" << endl;
    }
    cout << "after insert size is " << strmap.size() << endl;
    for (auto p : strmap)
    {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    // Now, if we want to erase an element, we first find it
    // and we take that "iterator" and use that "iterator" to erase,
    // and so, we're gonna erase "James", we search for "James",
    // and then we erase "James".
    cout << "find and erase an element:" << endl;
    auto it = strmap.find("James");
    if (it != strmap.end())
    {
        cout << "found " << it->first << ":" << it->second << endl;
        strmap.erase(it);
        // And now our size is five and "James" is not in there anymore.
        cout << "erased - size is " << strmap.size() << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    for (auto p : strmap)
    {
        cout << p.first << " is " << p.second << endl;
    }
    cout << endl;

    // So, the map class provides a sorted set of "key" : "value" pairs.
    // This is like an associative or hashed array in other languages.
    // This can be very useful in keeping track of "key" : "value"
    // relationships like username or other database keys.

    return 0;
}
