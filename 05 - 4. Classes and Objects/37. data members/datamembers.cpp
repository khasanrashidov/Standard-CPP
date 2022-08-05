// data members
#include <cstdio>
#include <string>
using namespace std;

// we define structure using struct keyword
struct A
{
public:
    int ia;
    int ib;
    int ic;
};

struct B
{
public:
    int id;
    int ie;
    int ig;
};

// So, struct and class are identical with one significant difference.
// Members of a struct default to public and members of a class default to private.
// So this is exactly the same as if we had used  public keyword inside structure.
// And of course, we have exactly the same result.

// C++ classes are based upon C structures.
// It is good practice to use struct when the structure will only have data members and
// to use class when they're all function members.

class C
{
private:
    int ih;
    string si;
    int ij;

public:
    C(const int h, const string &i, const int j) : ih(h), si(i), ij(j){};
    void seth(const int a) { ih = a; }
    void seti(const string &b) { si = b; }
    void setj(const int c) { ij = c; }
    int geth() const { return ih; }
    const string &geti() const { return si; }
    const char *geti_cstr() const { return si.c_str(); }
    int getj() const { return ij; }
};

int main(int argc, char **argv)
{
    // We define an object (object based on the structure) using the structure name as a type
    A a = {1, 2, 3};

    // Data members are accessed using the elements selection operator (. (dot)).
    // This is how we access the data members in the object.
    printf("ia is %d, ib is %d, ic is %d\n", a.ia, a.ib, a.ic);

    B b = {4, 5, 6};
    B *ptrb = &b;

    // If we are using a pointer, we use the pointer selection operator (-> (dash with arrow)).
    // This is how we select the members through a pointer.
    printf("id is %d, ie is %d, ig is %d\n", ptrb->id, ptrb->ie, ptrb->ig);

    C c(7, "eight", 9);
    printf("ih is %d, si is %s, ij is %d\n", c.geth(), c.geti_cstr(), c.getj());

    return 0;
}
