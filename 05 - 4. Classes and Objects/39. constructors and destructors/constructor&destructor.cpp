// constructors and destructors
#include <cstdio>
#include <string>
using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

// -- interface --
class Animal
{
private:
    string _type = "";
    string _name = "";
    string _sound = "";

public:
    Animal();                                                            // default constructor
    Animal(const string &type, const string &name, const string &sound); // parametrized constructor

    Animal(const Animal &);            // copy constructor
    Animal &operator=(const Animal &); // copy operator
    ~Animal();                         // destructor (~ (tilde) operator designates destructor)
    void print() const;                // simple print method
};

// -- implementation --

// function operator () : a list of initializers ( name_of_data_member(value), data_member(value) {} )
Animal::Animal() : _type(unk), _name(unk), _sound(unk) // initialization list
{
    puts("default constructor");
}

Animal::Animal(const string &type, const string &name, const string &sound)
    : _type(type), _name(name), _sound(sound)
{
    puts("constructor with arguments");
}

Animal::Animal(const Animal &a)
{
    puts("copy constructor");
    _name = clone_prefix + a._name;
    _type = a._type;
    _sound = a._sound;
}

Animal::~Animal()
{
    printf("destructor: %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::print() const // print method
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

// assignment operator
Animal &Animal::operator=(const Animal &o)
{
    puts("assignment operator");
    if (this != &o)
    {
        _name = clone_prefix + o._name;
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
    // 'this' means pointer to the object, so '*this' is an object.
    // So we are returning an object, i.e. '*this' returns a reference to the object.
}
// There is something called the rule of threes,
// it says that if we are overloading any of the implicit copy constructor,
// destructor or copy operator, that it is a good idea to overload all three of them,
// because we might run into problems if we do not.

int main(int argc, char **argv)
{
    Animal a;
    a.print();

    const Animal b("duck", "donald", "quack");
    b.print();

    const Animal c = b;
    c.print();

    a = c;
    a.print();

    return 0;
}