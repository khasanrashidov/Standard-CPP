// lists
#include <iostream>
#include <list>
using namespace std;

// A list is a sequence container like a vector,
// but optimized for speedy insert and delete operations.
// And it does not support random access.

int main(int argc, char **argv)
{
    // So, here we have our list that we've initialized.
    list<int> li1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Like other containers, a list supports size, and front and back.
    cout << "size: " << li1.size() << endl;
    cout << "front: " << li1.front() << endl;
    cout << "back: " << li1.back() << endl
         << endl;

    // And so, it's easy to access the front and the back of the list,
    // but to access anything inside, the list does not support
    // random access, and it does not support the subscript operator.
    // Because it doesn't support random access.
    // And so instead, it provides a bi-directional iterator.
    // So, we can push back or push front and actually add something
    // to the end or the beginning of the list, and so now the size is 12,
    // and the back is 21 and the front is 33.
    cout << "push_back 21: " << endl;
    li1.push_back(21);
    cout << "push_front 33: " << endl;
    li1.push_front(33);
    cout << "size: " << li1.size() << endl;
    cout << "back: " << li1.back() << endl;
    cout << "front: " << li1.front() << endl;

    // range-based for loop
    // And if we use a "range-based for loop",
    // we can see all of the elements in the list.
    cout << "range-based for loop: " << endl;
    for (int v : li1)
    {
        cout << v << " ";
    }
    cout << endl
         << endl;

    cout << "pop_back: " << endl;
    li1.pop_back();
    cout << "pop_front: " << endl;
    li1.pop_front();
    cout << "size: " << li1.size() << endl;
    cout << "back: " << li1.back() << endl;
    cout << "front: " << li1.front() << endl;

    // range-based for loop
    cout << "range-based for loop: " << endl;
    for (int v : li1)
    {
        cout << v << " ";
    }
    cout << endl
         << endl;

    // need an iterator to insert and erase
    // In order to insert and erase,
    // we need to actually loop through the iterators
    // to find the points to insert and erase.
    // Because it doesn't support random access.
    list<int>::iterator it1 = li1.begin();
    // We actually have to loop through and look at
    // each of the elements to find that spot
    // where we want to do an insert or an erase.
    // And so here we want to insert the number 64
    // before the number 5, and so we have to loop through
    // looking to see if our iterator is pointing at the number 5,
    // and if our iterator has hit the end.
    // And if we have not hit the end, then we go ahead and we insert.
    while ((*++it1 != 5) && (it1 != li1.end()))
        ;
    if (it1 != li1.end())
    {
        cout << "insert 64 before 5:" << endl;
        li1.insert(it1, 64);
    }
    for (int v : li1)
        cout << v << " ";
    cout << endl;

    // And if we want to erase the number 7,
    // we have to do the same thing.
    // We iterate through the loop,
    // looking for the number 7, and
    // making sure we haven't hit the end.
    while ((*++it1 != 7) && (it1 != li1.end()))
        ;
    if (it1 != li1.end())
    {
        cout << "erase 7:" << endl;
        // And then we can call erase on our iterator,
        // and it will erase the number 7.
        li1.erase(it1);
    }
    for (int v : li1)
        cout << v << " ";
    cout << endl;

    // Or we can erase a range.
    // There's an erase that'll take two iterators.
    cout << "erase 64 to 8:" << endl;
    list<int>::iterator it2 = it1 = li1.begin();
    // We're looking to see what they (it1 and it2) are pointing at,
    // and that they haven't hit the end.
    while ((*++it1 != 64) && (it1 != li1.end())) // for iterator 1
        ;
    while ((*++it2 != 8) && (it2 != li1.end())) // for iterator 2
        ;
    // And then we need to test and make sure
    // that they didn't hit the end.
    // And so, the code ends up looking a little bit complicated.
    if ((it1 != li1.end()) && (it2 != li1.end()))
    {
        cout << *it1 << " " << *it2 << endl;
        // The erase that takes two iterators,
        // it'll erase from the element that the first iterator
        // is pointing at, up to the element before
        // the last iterator is pointing.
        // And the reason for that is so that we can use "li1.end"
        // if we want to erase everything up to the end,
        // and it'll erase up to before that second iterator,
        // so we don't end up trying to erase
        // past the end of the container.
        // And again, this looks complicated because
        // we're iterating two different iterators here.
        li1.erase(it1, it2);
        // erase(const std::list<int>::const_iterator _First, const std::list<int>::const_iterator _Last)
        for (int v : li1)
            cout << v << " ";
        cout << endl
             << endl;
    }
    cout << endl;
    // The advantage of this is the lists are really, really fast.
    // Doing these inserts and these deletes, even with all of the looping,
    // is a lot faster than it is with something like a vector.
    // So, if we have really, really big data structures,
    // or data structures that have really, really big elements,
    // then a list can sometimes be efficient.
    // So, the STL lists are an excellent choice
    // for situations where we don't need random access,
    // and we will be inserting or removing a lot of elements.
    // They're very fast and lean,
    // but at the expense of some functionality.

    return 0;
}