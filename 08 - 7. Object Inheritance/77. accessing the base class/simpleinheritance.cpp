// accessing the base class
#include <cstdio>
#include <string>
using namespace std;

// When we're creating a Derived class, it's sometimes
// necessary to access member data and functions from it's base class.

// Base class Animal
class Animal
{
private:
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){};

protected:
    // protected constructor for use by derived classes
    Animal(const string &n, const string &t, const string &s)
        : _name(n), _type(t), _sound(s) {}

public:
    void speak() const;
    const string &name() const { return _name; }
    const string &type() const { return _type; }
    const string &sound() const { return _sound; }
};

void Animal::speak() const
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

class Dog : public Animal
{
private:
    int walked;

public:
    Dog(string n) : Animal(n, "dog", "woof"), walked(0){};
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
class Cat : public Animal
{
private:
    int petted;

public:
    Cat(string n) : Animal(n, "cat", "meow"), petted(0){};
    int pet() { return ++petted; }
};

// Hen class - derived from Animal
class Hen : public Animal
{
private:
    int fed;

public:
    Hen(string n) : Animal(n, "hen", "cackle"), fed(0){};
    int feed() { return ++fed; }
    string nickname() const; // public method
};

// implementation
string Hen::nickname() const
{
    return name() + "n";
    // We could have specified that this isn't a Base class
    // by giving the name of the Base class and two colons like this
    // return Animal::name() + "n";
    // and that does exactly the same thing.
    // That's more specific.
    // It specifies that the method is in the Base class,
    // but it isn't strictly necessary here
    // because there's no conflicting name in the Derived class.
    // But it's worth noting because it can be necessary under other circumstances.
    // We can note that we used this method to access the data member in the Base class.
    // That's because we can't access the _name data member because it has private access.
    // We could give it protected access, but it's considered best practice
    // to use an accessor method because this leaves access control in the Base class
    // where it belongs.
    // We can also notice that we gave a leading underscore to the names
    // of each of these private data members.
    // That's a convention that we use, a lot of people use a convention like that.
    // It just reminds us that that's a private data member.
    // So this is an easy method of accessing private data from a Base class
    // in the Derived class.
}

int main(int argc, char **argv)
{
    Dog d("Rex");
    Cat c("Tom");
    Hen h("Gloria");

    d.speak();
    c.speak();
    h.speak();

    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the hen has been fed %d times\n", h.feed());

    // Because this returns a C++ Standard Library string,
    // we need to call c_string on that return result
    // in order to get a c_string that we can print with printf.
    printf("the hen is sometimes called %s\n", h.nickname().c_str());

    return 0;
}