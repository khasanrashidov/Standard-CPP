// accessing the base class
#include <cstdio>
#include <string>
using namespace std;

// Sometimes we may want to grant access to our class's private variables
// to another specific class or even a few select classes.
// This is accomplished with a friend declaration.

// Let's take a look at what happens if we move our protected constructor to private.
// We can do that by just deleting the "protected" label.
// Then our constructor becomes private.
// Then we can see that we get an error for each of these.
// It's trying to call the private constructor. ("Base class 'Animal' has a private constructor")
// So, that's not working.
// We can force this to work by declaring these derived classes as friends.
// (under the private access modifier in the base class)
// This works, but it also exposes all of the private members
// of the base class to these derived classes.
// In other words, the Dog, Cat, Hen classes now have access to all the private members
// including the data members of the Animal class.

// We can also declare functions as friends.

// Base class Animal
class Animal
{
private:
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){};
    Animal(const string &n, const string &t, const string &s)
        : _name(n), _type(t), _sound(s) {}
    // friends
    friend class Dog;
    friend class Cat;
    friend class Hen;
    friend const string &get_animal_name(const Animal &);

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
};

// If we come down here and create a standalone function,
// and we wanna give the underscore.
// So, this is trying to access the private data member
// underscore name (_name) and we notice our error here,
// "name is a private member of Animal".
// So, we can make that work.
// We can force it work by declaring that function as a friend.
// (under the private access modifier in the base class)
// Then, we'll be able to notice that that error has gone away
// and we can use that function in main function.
const string &get_animal_name(const Animal &a)
{
    return a._name;
    // So now this function, get_animal_name, because it's declared
    // as a friend up in the base class, it can access all the private variables
    // and the private members in the Animal class.
    // This can be convenient but it also undermines encapsulation
    // and a lot of the controls that make object-oriented programming work so well.
    // It's usually safer to just use an accessor in the Animal interface.
    // And so we can really get this same result without the friend declaration,
    // and come up there in the base class and use the accessor method.
    // instead of
    // -- return a._name; --
    // we use
    // -- return a.name(); --
    // and this gives the same result.
    // But the control remains where it belongs in the class.
    // The same is actually true of the friend declarations with classes in the base class.
    // By keeping our constructor as protected,
    // we're leaving control where it belongs in the base class.
    // And we can then notice that we can accomplish all of these things
    // without making any of these classes or functions friends.

    // So the friend declaration allows us to grant
    // private member access to other classes and functions.
    // And this can be handy sometimes and it may even be necessary at times.
    // But it should always be used with caution.
    // Most of the time, it's best practice
    // to access private members through the class interface methods.
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

    printf("The hen named %s\n", get_animal_name(h).c_str());

    return 0;
}