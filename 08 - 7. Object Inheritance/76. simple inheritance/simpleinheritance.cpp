// simple inheritance
#include <cstdio>
#include <string>
using namespace std;

// Class inheritance in C++ is simply a matter
// of creating a base class and then declaring
// the inheritance in our derived class definitions.

// The Animal class is a base class and
// the classes that inherit from it
// down here are the derived classes.
// Some people use the terms parent and child
// but that's not as common.
// The Animal class is simple.
// It has three private data members for the name, type and sound of the animal.
// It has a public method called speak and a protected constructor.
// The protected access specifier means that members are only accessible
// through derived classes.
// Also we can notice that the default constructor is in the private access section.
// The default constructor defaults to public so overloading it and marking it is private
// prevents anyone from constructing an object of this class.
// If we wanna use this as a base class, but not directly for creating objects,
// this is a good way to ensure that the class is never used directly to create an object.

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
// Here we can notice how the Dog class inherits the Animal class.
// The colon is followed by an access specifier and the name of the base class.
// The access specifier controls how base class members will be accessed by the code
// that uses our derived class. This will almost always be public.
class Dog : public Animal
{
private:
    int walked;

public:
    // Now, we can notice the constructor for the Dog class.
    // It has initializers that call a base class constructor
    // and initialize a private member variable.
    // Now, we remember this base class constructor
    // is in the protected section above.
    // So we can only call it from derived classes.
    // The base class constructor is called because it initializes its members.
    // If we wanna initialize any base class members directly,
    // they would have to be declared protected or public.
    // This is not really recommended.
    // It's much easier to maintain our code when we use the class interface.
    // In this case, that means using the base class constructor.
    // We can notice that we've also included a private data member
    // and a public accessor down here in the Dog class.
    // This is to show the derived class is just like any other class
    // except that it inherits some properties its base class.
    // The private member is initialized just like any other class
    // and the accessor is used as we would expect.
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
};

int main(int argc, char **argv)
{
    // So down here in main, we construct
    // three objects of Dog, Cat and Hen.
    // They all inherit Animal.
    Dog d("Rex");
    Cat c("Tom");
    Hen h("Gloria");

    // And we call the speak method on each of these
    // and we can notice that the speak method is in the base class.
    d.speak();
    c.speak();
    h.speak();

    // And then we call these individual methods, walk, pet and feed
    // for each of the derived classes. And we can notice that each of these
    // methods increments its private data member.
    printf("the dog has been walked %d times\n", d.walk());
    printf("the cat has been petted %d times\n", c.pet());
    printf("the hen has been fed %d times\n", h.feed());

    // So this is actually very simple.
    // It might look like a lot of stuff.
    // This is just a simple example just
    // for the purpose of showing how inheritance works.

    // Class inheritance in C++ is really very simple.
    // It's also very powerful.

    return 0;
}