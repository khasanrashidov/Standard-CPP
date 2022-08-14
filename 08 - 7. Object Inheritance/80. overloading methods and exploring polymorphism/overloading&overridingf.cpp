// overloading methods and exploring polymorphism
// function overriding
#include <cstdio>
#include <string>
using namespace std;

// Sometimes we may find it useful to have a member function in a derived class
// that overloads a function that's defined in a base class.

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
    virtual ~Animal(){};        // virtual destructor
    virtual void speak() const; // virtual member function in the base class, the animal class
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
class Cat : public Animal
{
private:
    int petted;

public:
    Cat(string n) : Animal(n, "cat", "meow"), petted(0){};
    int pet() { return ++petted; }

    void speak() const; // a member function, or method
    // This speak member function overloads the speak member function in animal.
};

void Cat::speak() const
{
    printf("purr\n");
    // Then if we build and run the program,
    // we can notice that instead of saying that the cat says meow,
    // it simply says purr.

    // That works well. But there's one important detail
    // that we need to understand here.
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

    // an array of pointers to animal
    Animal *ap[] = {&d, &c, &h};

    // Then we'll cycle through those pointers and we'll call the speak method.
    // We are gonna use the range-based for loop here, because that's fun and easy.
    for (Animal *a : ap)
    {
        a->speak();
        // That calls speak on each of these pointers.
    }
    // Because the pointer is typed as the base class it will always
    // prefer the base version of any overloaded members.
    // To get the compiler to use the overloaded version
    // we declare the base version as "virtual".
    // The "virtual" qualifier tells the compiler that the function may be overloaded,
    // and to prefer the derived version rather than the base version.
    // This allows the pointer to be polymorphic.
    // Now, this pointer, even though it's a pointer to an animal type,
    // when it sees that speak function it looks for a derived version
    // in the pointed to object.
    // There's one other important detail here.
    // Whenever we declare anything "virtual",
    // we need to also declare a virtual destructor.
    // This is not a hard fast requirement,
    // but many compilers will complain if we don't,
    // and it's always a good habit anyway.
    // The reason for this is that it's important
    // that the destructor matches the function members,
    // so that when an object is destroyed the appropriate destructor is called.
    // So in this case, even though we don't have destructors defined,
    // they're still default destructors,
    // for the c object (of Cat class), the c destructor will be called,
    // even though we're using, actually all of destructors will be called in the
    // dog, cat, and hen classes, rather than the animal class destructor.
    // Now our pointers will work as expected.

    // Overloading methods or member functions in derived classes
    // is a fundamental part of object-oriented programming
    // and especially polymorphism.
    // This gives us a lot of power and flexibility
    // in how we design our classes.

    return 0;
}