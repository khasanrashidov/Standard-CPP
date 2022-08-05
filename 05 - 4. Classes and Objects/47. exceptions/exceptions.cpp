// exceptions
#include <cstdio>
#include <string>
#include <exception>
using namespace std;

// The C++ language has complete support for exceptions.
// In C++, exceptions may be used to report errors,
// especially, in circumstances where errors cannot be reported locally.

static string unk = "unknown";
static string clone_prefix = "clone-";

// So, this uses an exception class.
// The class is called E and it inherits from the exception class in the exception header.
// And so this is a standard class that comes with our C++ standard library.
// And so when it inherits that class, it overrides a few important functions.
// It overloads the constructor, allowing us to set a message.
// And it overloads 'what' method, allowing us to return the message.
class E : public exception
{
    const char *msg = nullptr;
    E(){};

public:
    E(const char *s)
    throw() : msg(s) {}
    const char *what() const throw() { return msg; }
};

class Animal
{
    string _type;
    string _name;
    string _sound;

public:
    Animal();                                                            // default constructor
    Animal(const string &type, const string &name, const string &sound); // parametrized ctor
    Animal(const Animal &);                                              // copy constructor
    Animal &operator=(const Animal &);                                   // copy operator
    ~Animal();                                                           // dtor
    void print() const;
};

// -- implementation --

Animal::Animal() : _type(unk), _name(unk), _sound(unk)
{
    puts("default constructor");
}

Animal::Animal(const string &type, const string &name, const string &sound)
    : _type(type), _name(name), _sound(sound)
{
    puts("constructor with arguments");
    if (type.length() == 0 || name.length() == 0 || sound.length() == 0)
    {
        throw E("Insufficient parameters");
    }
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

void Animal::print() const
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

Animal &Animal::operator=(const Animal &o)
{
    puts("the assignment operator");
    if (this != &o)
    {
        _name = clone_prefix + o._name;
        _type = o._type;
        _sound = o._sound;
    }
    return *this;
}

int main(int argc, char **argv)
{
    // We catch exceptions using 'try' block.
    // 'try' consist of two parts. There is a block for 'try' and there is a block for 'catch'.
    // 'try' is the code that we are executing where exceptions may happen.
    // And if an exception happens, for example, while constructing the object,
    // then execution is immediately switched to catch where the exception
    // object can report what the error was.
    try
    {
        Animal x("bear", "bill", "");
        x.print();
    }
    catch (exception &e)
    {
        printf("Animal x: %s\n", e.what());
    }
    return 0;
}
