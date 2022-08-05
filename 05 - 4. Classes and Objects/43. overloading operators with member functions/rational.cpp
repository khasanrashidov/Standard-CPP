// overloading operators with member functions
#include <cstdio>
#include <iostream>
using namespace std;

// There are two distinct ways to overload operators in C++.
// One is with member functions as part of a class definition and
// the other is a separate nonmember function.

class Rational
{
    int _n = 0;
    int _d = 1;

public:
    // Our constructors give us both a numerator and the denominator
    // and those are assigned to our _n and _d respectively.
    Rational(int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator){};

    // Definition is rhs (right-hand side) and the left-hand side is the object itself.

    // The parameter &rhs in the copy constructor is a reference to a Rational object.
    // It is a reference to the same class of object and its being defined here
    // and that is what makes it a copy constructor.
    // What it does is very simple.
    // It simply copies over the numerator (rhs._n) and the denominator (rhs._d) from this rhs object.
    Rational(const Rational &rhs) : _n(rhs._n), _d(rhs._d){}; // copy constructor

    ~Rational(); // destructor (dtor)
    // The overhead occurs for small functions because
    // execution time of small function is less than the switching time.
    // C++ provides an inline functions to reduce the function call overhead.
    inline int numerator() const { return _n; }
    inline int denominator() const { return _d; }

    // One assignment operator and four constant safe arithmetic operators.
    // Each of the operators takes a constant Rational reference.
    // All of the operators are constant safe with the exception of the assignment operator
    // which obviously cannot be constant safe because it needs to change data members.
    Rational &operator=(const Rational &);
    Rational operator+(const Rational &) const;
    Rational operator-(const Rational &) const;
    Rational operator*(const Rational &) const;
    Rational operator/(const Rational &) const;
    // The operator overload is defined by giving the name of the member function
    // as the operator keyword followed by the operator itself.
};

// the assignment operator
Rational &Rational::operator=(const Rational &rhs)
{
    // The assignment operator uses this pointer.
    // Basically, first it tests if this is the same as the address
    // of the right-hand side because the right-hand side is being passed
    // as a reference so we can get its address and
    // we can see if we are assigning to our self.
    // If we are, we simply return our self
    // because there is no actual assignment that needs to happen
    // and if we're not assigning our self then we simply copy the numerator
    // and the denominator from the right-hand side.

    if (this != &rhs)
    {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
    // We use this asterisk to dereference the pointer,
    // so that we are actually returning a reference to the object itself
    // and not a reference to the pointer.
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// operator overloads for the arithmetic operations
Rational Rational::operator+(const Rational &rhs) const
{
    // It constructs a temporary object called Rational
    // and it returns that temporary object without ever giving it a name.
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
    // The temporary objects, they just get created for the purpose of returning a result
    // and then they are immediately destroyed after they are used.
}

Rational Rational::operator-(const Rational &rhs) const
{
    return Rational((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator*(const Rational &rhs) const
{
    return Rational(_n * rhs._n, _d * rhs._d);
}

Rational Rational::operator/(const Rational &rhs) const
{
    return Rational(_n * rhs._d, _d * rhs._n);
}
////////////////////////////////////////////////////////////////////////////////////////////////////

Rational::~Rational()
{
    printf("dtor: %d/%d\n", _n, _d); // dtor stands for destructor
    _n = 0;
    _d = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// This is actually a nonmember function overload.
// This is an operator overload of the left shift operator
// that returns an ostream object and
// it takes an ostream object on the left-hand side and
// a rational object on the right-hand side.
// Then it simply returns the ostream object
// and it uses the left shift operator that ostream object
// just as we would at cout and we give it parameters just as we would at cout.

// useful for std::cout
std::ostream &operator<<(std::ostream &o, const Rational &r)
{
    return o << r.numerator() << '/' << r.denominator();
}
////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    Rational a = 7; // 7/1 which is (7, default value which is one); left to right
    cout << "a is: " << a << endl;

    Rational b(5, 3); // 5/3
    cout << "b is: " << b << endl;

    Rational c = b; // copy constructor
    cout << "c is: " << c << endl;

    Rational d; // default constructor
    cout << "d is: " << d << endl;

    d = c; // assignment operator
    cout << "d is: " << d << endl;

    Rational &e = d; // reference

    // We are doing the assignment to self and nothing happens.
    // e remains 5/3
    d = e; // assignment to self!
    cout << "e is: " << e << endl;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    // Here, the assignment operator is actually returning a reference to itself.
    d = c = b = a;

    printf("a is %d/%d\n", a.numerator(), a.denominator());
    printf("b is %d/%d\n", b.numerator(), b.denominator());
    printf("c is %d/%d\n", c.numerator(), c.denominator());
    printf("d is %d/%d\n", d.numerator(), d.denominator());

    return 0;
}
