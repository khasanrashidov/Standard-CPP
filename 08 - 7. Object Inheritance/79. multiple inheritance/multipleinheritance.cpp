// multiple inheritance
#include <cstdio>
#include <string>
using namespace std;

// Multiple inheritance in C++ is implemented by simply listing
// more than one base Class in the Class definition.

// We're gonna start by creating a second base Class. (class Fur)
// It's a simple class that we can use as a second base Class with "Cat" class.

class Fur
{
private:
    string _type;
    Fur(){}; // private Constructor so that it cannot be constructed by itself
protected:
    Fur(const string &f) : _type(f){}; // protected constructor
public:
    // public Interface member function
    const string &type() const { return _type; }
};

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

// Dog class - derived from Animal
class Dog : public Animal
{
private:
    int walked;

public:
    Dog(string n) : Animal(n, "dog", "woof"), walked(0){};
    int walk() { return ++walked; }
};

// Cat class - derived from Animal
// We'll add Fur listed in here to base Classes, like this.
// Now, we could have omitted the word "public" hereb
// (just class Animal : public Animal, Fur)
// because it would have just been public
// because there's two of them listed there,
// it is a good idea to include it just to make that we're clear.
class Cat : public Animal, public Fur
{
private:
    int petted;

public:
    // And here we'll add a second Constructor to this Constructor for Fur
    // and we'll say that this Cat has "silky" fur.
    Cat(string n) : Animal(n, "cat", "meow"), Fur("silky"), petted(0){};
    int pet() { return ++petted; }
    // And we can have a const safe member function here for "grooming".
    void grooming() const; // method or member function which prints out a String
                           // with the name of the animal and the type of the fur

    // The Fur Class holds a type for the fur
    // and it has an accessor for that type,
    // and the type gets initialized in the Constructor.
    // The Cat inherits both Animal and Fur,
    // and it constructs Fur here with the type.
    // We could have had a separate Constructor
    // that also allows the user to specify the type
    // but we're just being simple here.
};

// implementing void grooming();
void Cat::grooming() const
{
    printf("%s grooms his %s fur.\n", Animal::name().c_str(), Fur::type().c_str());
    // And because there's a "type" member function both in Animal, and in Fur,
    // we need to specify which of the base Classes we're calling that member function on.
}

// Hen class - derived from Animal
class Hen : public Animal
{
private:
    int fed;

public:
    Hen(string n) : Animal(n, "hen", "cackle"), fed(0){};
    int feed() { return ++fed; }
};

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

    c.grooming();

    // Multiple Inheritance in C++ is really very simple,
    // perhaps too simple, because sometimes while it's really necessary,
    // many times, like here for example, it can create unnecessary complexity.
    // In this example it may have been more clear if the Cat Class used a Fur
    // object as a data member, rather than inheriting it.
    // The code would have been simpler and easier to follow, and the "type" function
    // would no longer be ambiguous.
    // So, it's good to demonstrate that as well.

    return 0;
}