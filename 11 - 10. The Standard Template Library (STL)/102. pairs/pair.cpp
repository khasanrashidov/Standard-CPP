// pairs
#include <iostream>
// Including the "utility" header
// because that's where a "pair" is defined.
// We normally won't need to include "utility" directly.
// It'll usually be included by any class that uses "pairs".
#include <utility>
#include <string> // string is a container type
using namespace std;

// A pair is a simple fixed container
// for holding two related values.
// While it's not very complicated
// and it's not often used on its own,
// it is used by a number of other classes in the STL.

int main(int argc, char **argv)
{
    // Defining a "pair" of integers.
    // So, the "pair" class is a template type with two types.
    // One for each of the values.
    // In this simple example, both of the values are declared as "int".
    pair<int, int> p = {5, 21};
    // And the values are named first and second
    // and are directly accessible as public data members,
    // so we're gonna come here and we're going to
    // say "first" is "p.first" and "second" is "p.second".
    // So, we access the members of the "pair" directly.
    // They're public data members.
    // We don't need to use accessors to get at first and second.
    // Like we said, it's an incredibly simple template class.
    cout << "first is " << p.first << ", second is " << p.second << endl;
    // Of course, we can use a different type for either of these.
    // If we want to say include a container type,
    // we can use a "string" which is a container type.
    // And we can just make the second one string.
    pair<int, string> p2 = {5, "twenty-one"};
    cout << "first is " << p2.first << ", second is " << p2.second << endl;
    // So, pairs are very handy.
    // They're commonly used within the STL.

    cout << "Pairs" << endl;
    return 0;
}