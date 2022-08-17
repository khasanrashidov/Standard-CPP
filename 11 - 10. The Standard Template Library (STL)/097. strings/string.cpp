// strings
#include <iostream>
#include <string> // including the string header
using namespace std;

// The STL String class is a special type of container
// specifically designed to operate with sequences of characters.
// It's designed with many features to operate on strings
// efficiently and intuitively.
// String is an STL container class
// that operates on characters in the same way
// as any sequence container operates on other types.
// String has functions that are specifically
// designed for operating on strings of Characters.
// It's very much like a vector but with
// additional string-related functions.

int main(int argc, char **argv)
{
    // Our string is initialized with the copy constructor, this is a string.
    string s1 = "This is a string";

    // Demonstration of different methods on the string class.

    // size() & length()
    // There's the normal size method that any
    // sequence container in the STL has and
    // it has an alias called length
    // which does exactly the same things.
    // So we see that the size is the same as length 16 characters.
    cout << "size is same as length: " << s1.size() << endl;
    cout << "size is same as length: " << s1.length() << endl;

    // + concatenation
    // And we concatenate strings using the plus operator.
    // And the plus operator is a nonmember operator overload.
    // So it'll work with the C string on either side of the operator.
    // So we can say "String + C String" or "C String + String" and
    // it'll still concatenate.
    cout << "concatenated strings: ";
    string s2 = "this is also a string";
    cout << s1 + ":" + s2 << endl;

    // compare
    // We can compare two strings with a normal comparison operators.
    // And we have a number of examples of this here.
    // We're using it with the conditional operator and yes or no.
    cout << "is s1 === s2? " << (s1 == s2 ? "yes" : "no") << endl;
    cout << "copy-assign s2 = s1" << endl;
    s2 = s1; // copying using assignment operator
    cout << "is s1 == s2? " << (s1 == s2 ? "yes" : "no") << endl;
    // And then we use the "greater than" (>) or "less than" (<)
    // operators with other string.
    cout << "is s1 > \"other string\"? " << (s1 > "other string" ? "yes" : "no") << endl;
    cout << "is s1 < \"other string\"? " << (s1 < "other string" ? "yes" : "no") << endl;
    cout << "is \"other string\" > s1? " << ("other string" > s1 ? "yes" : "no") << endl;
    cout << "is \"other string\" < s1? " << ("other string" < s1 ? "yes" : "no") << endl;

    // each character
    // We can use a range-based "for loop"
    // to step through each of the characters
    // and we're putting a space character between them
    // and so each character is separated with spaces.
    cout << "each character: ";
    for (char c : s1)
    {
        cout << c << ' '; // With spaces between each of the characters.
    }
    cout << endl;

    // insert() & erase() with an iterator
    // We can use an iterator to insert a character.
    // We need to remember this is just like any container except it contains characters.
    s1.insert(s1.begin() + 5, 'X'); // it's zero base
    cout << "after insert: " << s1 << endl;
    // Erasing, taking it out of the container,
    // deleting it from the container using exactly the same
    // syntax with the erase() method.
    s1.erase(s1.begin() + 5);
    // And so, after the erase the X is gone.
    cout << "after erase: " << s1 << endl;

    // replace()
    // We can use the replace method to replace two characters,
    // so those two characters are
    // "is" part of the string and we change it to "ain't".
    // (It's not good grammar
    // but it's a good demonstration of the replace() method.)
    s1.replace(5, 2, "ain't"); // replace(char_start_position, char_quantity, new_word)
    cout << "after replace: " << s1 << endl;

    // substr()
    // We can use sub-string to extract five characters from the fifth position
    // and we get that same "ain't".
    cout << "substr: " << s1.substr(5, 5) << endl;

    // find()
    // And we can use find to find the first position
    // of a character within string.
    // We need to remember the first position is zero.
    size_t pos = s1.find("s");
    cout << "find first \"s\" in s1 (pos): " << pos << endl;

    // rfind
    // rfind() is for last position.
    pos = s1.rfind("s");
    cout << "find last \"s\" in s1 (pos): " << pos << endl;

    // So those are the highlights of the string class.
    // The string class of course has a lot more in it.
    // The string class is a powerful and flexible class
    // implemented as a sequence container,
    // has a rich set of features, and an intuitive interface.

    return 0;
}